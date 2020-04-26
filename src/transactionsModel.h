#ifndef TRANSACTIONSMODEL_H
#define TRANSACTIONSMODEL_H

#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include "transaction.h"

class TransactionModel : public QAbstractItemModel
{
public:
    TransactionModel(QObject* parent = nullptr);

    const Transaction& getItem(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    std::vector<Transaction>* transactions;
};

#endif // TRANSACTIONSMODEL_H
