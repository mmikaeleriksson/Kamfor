#include "transaction.h"
#include <sstream>


QDate Transaction::getDate() const
{
    return date;
}


std::string Transaction::getType() const
{
    return type;
}


void Transaction::setType(const std::string& type)
{
    this->type = type;
}


std::string Transaction::getMessage() const
{
    return message;
}


double Transaction::getAmount() const
{
    return amount;
}


std::string Transaction::ToString() const
{
    std::stringstream output;

    output << date.toString(Qt::ISODate).toUtf8().constData() << std::endl;
    output << type << std::endl;
    output << message << std::endl;
    output << amount;

    return output.str();
}
