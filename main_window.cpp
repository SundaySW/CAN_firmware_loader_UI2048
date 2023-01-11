#include "main_window.h"
#include "fixed_packet.h"
#include "log_view.h"
#include "packet_utils.h"
#include <algorithm>
#include <qapplication.h>
#include <qaction.h>
#include <qdockwidget.h>
#include <qjsondocument.h>
#include <qstackedwidget.h>
#include <qstatusbar.h>
#include <qboxlayout.h>
#include <qbuttongroup.h>
#include <qevent.h>
#include <qjsonarray.h>
#include <qicon.h>
#include <qmenu.h>
#include <qtcpsocket.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <QtWidgets/QDialogButtonBox>
#include <QtGui/QRegExpValidator>
#include "qfiledialog.h"

SocketAdapter Socket;

MainWindow::MainWindow(int argv, char** argc, QWidget *parent)
        : QMainWindow(parent)
        , CentralWin(new QWidget(parent))
        , Toolbar(nullptr)
        , Dlg(new ConnectionDialog(this, &Socket))
        , fwLoader(new FWLoader)
        , statusLabel(new QLabel("Status: ", this))
{
    Toolbar = CreateToolbar();
    auto* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    statusLabel->setAlignment(Qt::AlignHCenter);
    statusLabel->setMinimumSize(statusLabel->sizeHint());
    statusBar()->addWidget(statusLabel);
    CentralWin->setLayout(mainLayout);
    setCentralWidget(CentralWin);
    logView = new LogView(this);
    mainLayout->addWidget(logView);
    connect(fwLoader, SIGNAL(signalNextBlock(uint, uint, uint)), this, SLOT(updateStatus(uint, uint, uint)));
    connect(fwLoader, SIGNAL(signalBootData(uint)), this, SLOT(transmitBlock(uint)));
    connect(fwLoader, SIGNAL(signalAckReceived()), this, SLOT(ackInBootReceived()));
    connect(fwLoader, SIGNAL(signalFinishedOK(uint, int)), this, SLOT(finishedOk(uint,int)));
    connect(fwLoader, SIGNAL(signalError(const QString&, uint)), this, SLOT(getError(const QString&, uint)));
    Socket.AddRxMsgHandler([this](const ProtosMessage& rxMsg) {	fwLoader->ParseBootMsg(rxMsg);});
    Socket.AddTxMsgHandler([this](const ProtosMessage& txMsg) { txMsgHandler(txMsg);});

    if (!Socket.Connect("127.0.0.1", 3699, 1000)){
        statusLabel->setText(tr("Cant connect to Server"));
        logView->AddMsg(tr("Cant connect to Server"));
    }
    else{
        statusLabel->setText(tr("Connected to Server"));
        logView->AddMsg(tr("Connected to Server"));
    }
}

QToolBar* MainWindow::CreateToolbar()
{
    QToolBar* toolbar = addToolBar(QString());
    toolbar->setMovable(false);
    toolbar->setStyleSheet("QToolBar { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\ stop: 0 #f6f7fa, stop: 1 #dadbde); }");

    auto socketConnect = toolbar->addAction(QString("Connect Server"));
    socketConnect->setObjectName("ServerConnect");
    socketConnect->setCheckable(true);
    socketConnect->setToolTip(QStringLiteral("Подключиться/Отключиться к серверу"));
    connect(socketConnect, &QAction::triggered, [this](bool checked)
    {
        auto ConnDialog = new ConnectionDialog(this, &Socket);
        UpdatePortButton(ConnDialog->exec() != 0);
        delete ConnDialog;
    });
    toolbar->addSeparator();
    auto loadDevice = toolbar->addAction(QIcon(), QString("Add Device"));
    loadDevice->setObjectName("AddDevice");
    loadDevice->setCheckable(false);
    loadDevice->setToolTip(QStringLiteral("Добавить девайс"));
    connect(loadDevice, &QAction::triggered, [this](bool checked)
    {
        openFile();
    });

    toolbar->addSeparator();
    auto setDelay = toolbar->addAction(QIcon(), QString("Set Adapter Delay"));
    setDelay->setObjectName("SetDelay");
    setDelay->setCheckable(false);
    setDelay->setToolTip(QStringLiteral("Изменить задержку отправки в коробку"));
    connect(setDelay, &QAction::triggered, [this](bool checked)
    {
        setDelayDlg();
    });

    toolbar->addSeparator();
    auto stopProcess = toolbar->addAction(QIcon(), QString("Stop Process"));
    stopProcess->setObjectName("stopProcess");
    stopProcess->setCheckable(false);
    stopProcess->setToolTip(QStringLiteral("Остановить процесс"));
    connect(stopProcess, &QAction::triggered, [this](bool checked)
    {
        stopProcessDlg();
    });

//    toolbar->addSeparator();
//    auto sendMSG = toolbar->addAction(QIcon(), QString("sendMSG"));
//    sendMSG->setObjectName("sendMSG");
//    sendMSG->setCheckable(false);
//    sendMSG->setToolTip(QStringLiteral("Отправить сообщ"));
//    connect(sendMSG, &QAction::triggered, [this](bool checked)
//    {
//        sendMessage();
//    });
//    toolbar->addSeparator();
//    auto getBlockOKMSG = toolbar->addAction(QIcon(), QString("getBlockOKMSG"));
//    getBlockOKMSG->setObjectName("getBlockOKMSG");
//    getBlockOKMSG->setCheckable(false);
//    getBlockOKMSG->setToolTip(QStringLiteral("Получить блок ОК"));
//    connect(getBlockOKMSG, &QAction::triggered, [this, &blockNum](bool checked)
//    {
//        getMessage();
//    });
//    toolbar->addSeparator();

    auto* expander = new QWidget(toolbar);
    expander->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    toolbar->addWidget(expander);

    auto exit = toolbar->addAction( QString("Exit"));
    exit->setToolTip(QStringLiteral("Закрыть приложение"));
    connect(exit, &QAction::triggered, [this](bool checked)
    {
        close();
    });
    return toolbar;
}

void MainWindow::UpdatePortButton(bool checked)
{
    auto btn = Toolbar->findChild<QAction*>("ServerConnect");
    btn->setText(checked ? "Connected" : "Disconnected");
//    btn->setIcon(QIcon(checked ? ":/plugin" : ":/plugout_red"));
    btn->setChecked(checked);
}

void MainWindow::transmitBlock(uint uid){
    fwLoader->transmitBlock(uid);
}

void MainWindow::updateStatus(uint delta, uint uid, uint addr) {
    if(delta >= 100) statusLabel->setText("Status: all packets sent and received by target");
    else {
        statusLabel->setText(QStringLiteral("Status: %1%").arg(delta));
        logView->AddMsg(tr("Device UID: %1, Boot Addr: %2 Status: %3%").arg(uid,8,16).arg(addr, 3,16).arg(delta));
    }
}

void MainWindow::ackInBootReceived() {
    QDialog dlg(this);
    dlg.setWindowTitle(tr("ackRecieved"));
    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok);
    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    QFormLayout *layout = new QFormLayout();
    layout->addWidget(btn_box);
    dlg.setLayout(layout);
    if(dlg.exec() == QDialog::Accepted) {
    }
}

void MainWindow::finishedOk(uint uid, int msecs) {
    QString msg = QString(tr("On device UID:%1 successfully loaded new FW. Time spent(msecs): %2").arg(uid, 8, 16).arg(msecs));
    logView->AddMsg(msg);
    statusLabel->setText(msg);
}

void MainWindow::getError(const QString &error, uint uid) {
    QDialog dlg(this);
    dlg.setWindowTitle(error);
    auto *layout = new QFormLayout();
    auto errorLabel = new QLabel(error, &dlg);
    auto questionLabel = new QLabel((QStringLiteral("Finish device FW with UID: %1").arg(uid,8,16)), &dlg);
    auto *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    errorLabel->setAlignment(Qt::AlignHCenter);
    errorLabel->setMinimumSize(statusLabel->sizeHint());
    layout->addRow(errorLabel);
    layout->addRow(questionLabel);
    layout->addWidget(btn_box);

    dlg.setLayout(layout);

    if(dlg.exec() == QDialog::Accepted) {
        fwLoader->cancelFWLoad(uid);
    }
}

void MainWindow::txMsgHandler(const ProtosMessage &txMsg)
{
//    statusLabel->setText(tr("UID: %1 ADDR: %2 MSG_TYPE: %3\n[0]: %4  [1]: %5  [2]: %6  [3]: %7  [4]: %8 [5]: %9 [6]: %10 [7]: %11 ")
//    .arg(txMsg.IdBytes[0] | txMsg.IdBytes[1] << 8 | txMsg.IdBytes[2] << 16, 1, 16)
//    .arg(txMsg.Data[1], 1, 16)
//    .arg(txMsg.BootMsgType, 1, 16)
//                                 .arg(txMsg.Data[0], 1, 16)
//                                 .arg(txMsg.Data[1], 1, 16)
//                                 .arg(txMsg.Data[2], 1, 16)
//                                 .arg(txMsg.Data[3], 1, 16)
//                                 .arg(txMsg.Data[4], 1, 16)
//                                 .arg(txMsg.Data[5], 1, 16)
//                                 .arg(txMsg.Data[6], 1, 16)
//                                 .arg(txMsg.Data[7], 1, 16)
//    );
}

void MainWindow::openFile() {
    QDialog dlg(this);
    dlg.setWindowTitle(tr("AddDevice"));
    auto *uid = new QLineEdit(lastUID, &dlg);
    auto *addr = new QLineEdit(lasrADDR, &dlg);
    auto *ver = new QLineEdit(SWVer, &dlg);

    auto *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok);
    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

    auto *layout = new QFormLayout();
    layout->addRow(tr("UID: "), uid);
    layout->addRow(tr("ADDR: "), addr);
    layout->addRow(tr("SW Ver: "), ver);
    layout->addWidget(btn_box);

    dlg.setLayout(layout);
    if(dlg.exec() == QDialog::Accepted) {
        lasrADDR = addr->text();
        lastUID = uid->text();
        SWVer = ver->text();
        uint32_t uid24 = uid->text().toUInt(nullptr, 16);
        uint8_t addr8 = addr->text().toShort(nullptr, 16);
        uchar version = ver->text().toShort(nullptr, 16);
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open Bin"), "/home", tr("Bin Files (*.bin)"));
//            QString fileName = "D:\\u\\sa_pico_can.bin";
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite))
        {
            fwLoader->addDevice(fileName, addr8, uid24,0x1, version);
            qDebug() << (tr("UID: %1 ADDR: %2 ").arg(uid24).arg(addr8));
            statusLabel->setText(tr("Device loaded UID: %1 ADDR: %2 ").arg(uid24, 8, 16).arg(addr8, 2,16));
            logView->AddMsg(tr("Device loaded UID: %1 ADDR: %2 ").arg(uid24, 8, 16).arg(addr8, 2,16));
        }
    } else{
        statusLabel->setText(tr("Aborted adding device"));
        logView->AddMsg(tr("Aborted adding device"));
    }
}

void MainWindow::sendMessage() {
    char data[8] = {0};
    data[0] = 0x1;
    data[1] = 0xFF;
    data[2] = 0x1;
    data[3] = 0x1;
    data[4] = 0x1;
    data[5] = 0xFF;
    data[6] = 0xFF;
    data[7] = 0xFF;
    uint idBytes = 0xffffff;
    ProtosMessage setAddrCRCMsg(0, 0, ProtosMessage::MsgTypes::NONE, 8,
                                data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    setAddrCRCMsg.IdBytes[0] = idBytes & 0xff;
    setAddrCRCMsg.IdBytes[1] = (idBytes >> 8) & 0xff;
    setAddrCRCMsg.IdBytes[2] = (idBytes >> 16) & 0xff;
    setAddrCRCMsg.IdBytes[3] = 0;
    setAddrCRCMsg.BootMsgType = Protos::MSGTYPE_BOOT_ADDR_CRC;
    setAddrCRCMsg.ProtocolType = ProtosMessage::RAW;
    setAddrCRCMsg.BootLoader = ProtosMessage::BOOT;
    Socket.SendMsg(setAddrCRCMsg);
}
int blockNum;
void MainWindow::getMessage() {
    char data[8] = {0};
    data[0] = 0x1;
    data[1] = 0xFF;
    data[2] = Protos::BOOT_FC_FLAG_FC;
    data[3] = Protos::BOOT_FC_BLOCK_OK;
    data[6] = blockNum & 0xFF;
    data[7] = (blockNum << 8) & 0xFF;
    uint idBytes = 0xffffff;
    ProtosMessage setAddrCRCMsg(0, 0, ProtosMessage::MsgTypes::NONE, 8,
                                data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    setAddrCRCMsg.IdBytes[0] = idBytes & 0xff;
    setAddrCRCMsg.IdBytes[1] = (idBytes >> 8) & 0xff;
    setAddrCRCMsg.IdBytes[2] = (idBytes >> 16) & 0xff;
    setAddrCRCMsg.IdBytes[3] = 0;
    setAddrCRCMsg.BootMsgType = Protos::MSGTYPE_BOOT_FLOW;
    setAddrCRCMsg.ProtocolType = ProtosMessage::RAW;
    setAddrCRCMsg.BootLoader = ProtosMessage::BOOT;
    fwLoader->ParseBootMsg(setAddrCRCMsg);
    blockNum = blockNum + 1;
}

void MainWindow::setDelayDlg() {
    QDialog dlg(this);
    dlg.setWindowTitle(tr("Set Delay"));
    auto *delay = new QLineEdit(tr("%1").arg(Socket.getDelay()), &dlg);
    auto *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok);
    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

    auto *layout = new QFormLayout();
    layout->addRow(tr("Delay: "), delay);
    layout->addWidget(btn_box);
    dlg.setLayout(layout);
    if(dlg.exec() == QDialog::Accepted)
        Socket.setDelay(delay->text().toUInt(nullptr, 10));

    statusLabel->setText(tr("Delay Set to: %1").arg(Socket.getDelay()));
    logView->AddMsg(tr("Delay for can adapter is set to: %1").arg(Socket.getDelay()));
}

void MainWindow::stopProcessDlg() {
    QDialog dlg(this);
    dlg.setWindowTitle(tr("Stop Process"));
    auto *uid = new QLineEdit(lastUID, &dlg);
    auto *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok);
    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

    auto *layout = new QFormLayout();
    layout->addRow(tr("UID: "), uid);
    layout->addWidget(btn_box);
    dlg.setLayout(layout);
    uint uidValue = uid->text().toUInt(nullptr, 16);
    if(dlg.exec() == QDialog::Accepted)
        fwLoader->cancelFWLoad(uidValue);
    statusLabel->setText(tr("Aborted FW loading UID: %1").arg(uidValue, 8,16));
    logView->AddMsg(tr("Aborted FW loading UID: %1").arg(uidValue,8,16));
}