#include <string>
#include "Transaction.h"

Transaction::Transaction(const std::string& newReceiver, const std::string& newSender, const int& newAmount) :
Node<int>(), receiver(newReceiver), sender(newSender), amount(newAmount)
{
    // Create a new transaction that is to the given receiver, is from the given sender, and is of the given
    // amount.
}


std::string Transaction::getReceiver() const
{
    return receiver;
}


std::string Transaction::getSender() const
{
    return sender;
}


int Transaction::getAmount() const
{
    return amount;
}