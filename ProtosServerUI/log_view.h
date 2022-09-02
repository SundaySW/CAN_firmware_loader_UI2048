#pragma once

#include <qwidget.h>

class QLineEdit;
class QComboBox;
class QPushButton;
class QTableView;

class LogView : public QWidget
{
	Q_OBJECT

public:
	LogView(QWidget* parent);
	virtual ~LogView();

	void SetLogSize(int size) { LogSize = size; }
	void AddMsg(const QString& msg);
	void AddMsgs(const QStringList& msgs);

private:
	int LogSize = 1000;
	QTableView* EventTable;
};