#include "transaction.h"
#include "transactionHandler.h"

#include <iostream>


void importExample()
{
    //Example transactions
    auto transactions = TransactionHandler::getInstance().getTransactions();

    transactions->emplace_back(
        Transaction(QDate(2019, 10, 01), "Hemkop", -500.00));

    transactions->emplace_back(
        Transaction(QDate(2019, 10, 01), "Ica", -250.99));

    transactions->emplace_back(
        Transaction(QDate(2019, 10, 01), "Restaurang Yogi", -99.99));

    for (auto transaction : *transactions) {
        transaction.setType("None");
    }

    std::cout << transactions->size() << std::endl;
}
