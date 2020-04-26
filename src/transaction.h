#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <QDate>

class Transaction
{
public:
    Transaction() {}
    Transaction(QDate date, std::string message, double amount)
        : date(date), message(message), amount(amount) {}

    QDate getDate() const;
    std::string getType() const;
    void setType(const std::string &type);
    std::string getMessage() const;
    double getAmount() const;
    std::string ToString() const;


private:
    QDate date;
    std::string type;
    std::string message;
    double amount;
};

#endif // TRANSACTION_H
