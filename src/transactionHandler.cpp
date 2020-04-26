#include "transactionHandler.h"

std::vector<Transaction>* TransactionHandler::getTransactions()
{
    return &transactionVector;
}
