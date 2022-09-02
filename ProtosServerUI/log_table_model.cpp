#include "log_table_model.h"

void LogTableModel::AddEntry(const QString& entry)
{
	size_t size = Data.size();
	Data.push_back(entry);
	insertRow(size);
}

void LogTableModel::AddEntries(const QStringList& entries)
{
}

int LogTableModel::columnCount(const QModelIndex& parent) const
{
	return 1;
}

QVariant LogTableModel::data(const QModelIndex& index, int role) const
{
	try
	{
		int row = index.row();
		if (row >= (int)Data.size())
			throw 0;

		int col = index.column();

		if (role == Qt::DisplayRole)
		{
			return GetCellString(index);
		}
		if (role == Qt::TextAlignmentRole)
		{
			return QVariant(Qt::AlignLeft|Qt::AlignVCenter);
		}
	}
	catch (...)
	{
	}
	return QString();
}

void LogTableModel::Clear()
{
	beginResetModel();
	Data.clear();
	StartIndex = 0;
	Data.clear();
	endResetModel();
}

QString LogTableModel::GetCellString(const QModelIndex& _index) const
{
	try
	{
		int index = _index.row();
		return Data[index];
	}
	catch (...)
	{
	}
	return QString();
}

QVariant LogTableModel::headerData(int section,
	Qt::Orientation orientation, int role) const
{
	QVariant result;
	if (orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{
		}
		else if (role == Qt::UserRole)
		{
		}
	}
	else
	{//vertical
		if (role == Qt::DisplayRole)
		{
			return QString::number(StartIndex + section);
		}
		else
		{
			result = QAbstractItemModel::headerData(section, orientation, role);
		}
	}
	return result;
}

QModelIndex LogTableModel::index(int row, int column, const QModelIndex& parent) const
{
	return createIndex(row, column, nullptr);
}

bool LogTableModel::insertRows(int row, int count, const QModelIndex& parent)
{
	beginInsertRows(QModelIndex(), row, row + count - 1);
	endInsertRows();
	return true;
}

QModelIndex LogTableModel::parent(const QModelIndex & index) const
{
	return QModelIndex();
}

bool LogTableModel::removeRows(int row, int count, const QModelIndex& parent)
{
	if (count <= 0 || row >= (int)Data.size()) return false;

	if (row + count > Data.size())
		count = Data.size() - row;

	beginRemoveRows(parent, row, row + count - 1);
	Data.erase(Data.begin() + row, Data.begin() + row + count);
	endRemoveRows();
	return true;
}

int LogTableModel::rowCount(const QModelIndex& parent) const
{
	return Data.size();
}