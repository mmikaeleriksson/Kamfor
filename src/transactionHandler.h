#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "transaction.h"

class TransactionHandler
{
public:
    static TransactionHandler& getInstance()
    {
        static TransactionHandler instance;
        return instance;
    }

    std::vector<Transaction>* getTransactions();

protected:
    TransactionHandler() = default;
    ~TransactionHandler() = default;

    TransactionHandler(const TransactionHandler&) = delete;
    TransactionHandler(const TransactionHandler&&) = delete;

    TransactionHandler& operator=(const TransactionHandler&) = delete;
    TransactionHandler& operator=(const TransactionHandler&&) = delete;


private:
    std::vector<Transaction> transactionVector;

};

#endif // TRANSACTIONHANDLER_H
