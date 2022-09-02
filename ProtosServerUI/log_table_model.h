#pragma once

#include <qstring.h>
#include <qlist.h>
#include <qabstractitemmodel.h>

class LogTableModel : public QAbstractItemModel
{
public:
	LogTableModel(QObject* parent = 0)
		: QAbstractItemModel(parent)
		, StartIndex(0)
	{
	}
	virtual ~LogTableModel(){};

	void AddEntry(const QString& entry);
	void AddEntries(const QStringList& entries);
	int columnCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
	QModelIndex parent(const QModelIndex & index) const;
	bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
	int rowCount(const QModelIndex & parent = QModelIndex()) const;

	void Clear();
	QString GetCellString(const QModelIndex& index) const;

	unsigned long long StartIndex;
	QList<QString> Data;
};
