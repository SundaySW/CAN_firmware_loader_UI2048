#include "log_view.h"
#include "log_table_model.h"
#include <qboxlayout.h>
#include <qheaderview.h>
#include <qpushbutton.h>
#include <qtextstream.h>
#include <qtableview.h>
#include <memory>

namespace
{
	QTableView* CreateEventTable(QWidget* parent)
	{
		QTableView* table = new QTableView(parent);
		table->setAlternatingRowColors(true);
		table->horizontalHeader()->setStretchLastSection(true);
		// будет преп€тствовать к авто. прокрутке к выделенной
		// строке(€чейке), когда она скроетс€ из области видимости.
		table->setAutoScroll(false); 
		table->setModel((QAbstractItemModel*)(new LogTableModel(parent)));
		return table;
	}

}//namespace

LogView::LogView(QWidget* parent)
	: QWidget(parent)
	, EventTable(CreateEventTable(this))
{
	QVBoxLayout* mainLayout = new QVBoxLayout();
	
	auto clearBtn = new QPushButton(QStringLiteral("ќчистить"));
	clearBtn->setToolTip(QStringLiteral("ќчистить список"));
	connect(clearBtn, &QPushButton::clicked, [this](bool checked)
	{
		auto* model = (LogTableModel*)EventTable->model();
		model->Clear();
		EventTable->update();
	});

	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(EventTable);
	QHBoxLayout* btnLayout = new QHBoxLayout();
	btnLayout->addWidget(clearBtn);
	mainLayout->addLayout(btnLayout);
	mainLayout->setContentsMargins(1, 1, 1, 1);
	setLayout(mainLayout);
}

LogView::~LogView()
{
}

void LogView::AddMsg(const QString& msg)
{
	LogTableModel* model = dynamic_cast<LogTableModel*>(EventTable->model());
	if (model->rowCount() >= LogSize)
	{
		model->removeRows(0, 1);
		model->StartIndex++;
	}
	model->AddEntry(msg);

	EventTable->update();
}

void LogView::AddMsgs(const QStringList& msgs)
{
	LogTableModel* model = dynamic_cast<LogTableModel*>(EventTable->model());
	for (auto& msg : msgs)
	{
		if (model->rowCount() >= LogSize)
		{
			model->removeRows(0, 1);
			model->StartIndex++;
		}
		model->AddEntry(msg);
	}

	EventTable->update();
}