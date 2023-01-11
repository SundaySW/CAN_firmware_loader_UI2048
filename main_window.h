
#include <qmainwindow.h>
#include "connection_dialog.h"
#include "FWLoader/FWLoader.hpp"

class LogView;
class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow(int argv, char** argc, QWidget *parent = 0);
    //signals:
    private slots:
        void transmitBlock(uint UID);
        void updateStatus(uint delta, uint uid, uint addr);
        void ackInBootReceived();
        void finishedOk(uint, int);
        void getError(const QString& error, uint uid);
    private:
        QToolBar* CreateToolbar();
        void openFile();
        void sendMessage();
        void getMessage();
        void setDelayDlg();
        void stopProcessDlg();
        void UpdatePortButton(bool checked);
        LogView* logView;
        QLabel* statusLabel;
        QWidget* CentralWin;
        QToolBar* Toolbar;
        FWLoader* fwLoader;
        std::unique_ptr<ConnectionDialog> Dlg;
        void txMsgHandler(const ProtosMessage &txMsg);
        QString lastUID = "FFFFFF", lasrADDR = "FF", SWVer = "0";
};
