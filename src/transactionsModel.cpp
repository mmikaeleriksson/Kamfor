#include "transactionsModel.h"
#include "transactionHandler.h"
#include <iostream>

enum Columns { date, message, amount, Count };


TransactionModel::TransactionModel(QObject* parent) :
    QAbstractItemModel(parent)
{
    transactions = TransactionHandler::getInstance().getTransactions();
}


const Transaction&
TransactionModel::getItem(const QModelIndex& index) const
{
    return transactions->at(index.row());
}


QVariant TransactionModel::headerData(int section, Qt::Orientation orientation,
                                      int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch(section) {
        case Columns::date:
            return "Date";
        case Columns::message:
            return "Message";
        case Columns::amount:
            return "Amount";
        }
    }
    return QVariant();
}


QVariant TransactionModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    auto& item = getItem(index);

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch(index.column()) {
        case Columns::date:
            return item.getDate();
        case Columns::message:
            return QString::fromUtf8(item.getMessage().c_str());
        case Columns::amount:
            return item.getAmount();
        }
    }

    return QVariant();
}


QModelIndex TransactionModel::index(int row, int column,
                                    const QModelIndex& parent) const
{
    if (!parent.isValid() || parent.column() == 0) {
	return createIndex(row, column);
    }

    return QModelIndex();
}


QModelIndex TransactionModel::parent(const QModelIndex& index) const
{
    return QModelIndex();
}


int TransactionModel::rowCount(const QModelIndex& parent) const
{
    return transactions->size();
}


Qt::ItemFlags TransactionModel::flags(const QModelIndex& index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemNeverHasChildren;
}


int TransactionModel::columnCount(const QModelIndex& parent) const
{
    return Columns::Count;
}
