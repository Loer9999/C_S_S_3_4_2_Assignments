#pragma once

#include <string>
#include "Node.h"

class Transaction : public Node<int>
{
private:
    std::string receiver;
    std::string sender;
    int amount;

public:
    // Since an empty transaction or a transaction with missing information is invalid, this class
    // does not have a default constructor or parametrized constructors with less than three
    // parameters so that every transaction has a valid receiver, sender, and amount.


    /** The parametrized constructor creates a new transaction that is to the given receiver, is from
        the given sender, and is of the given amount.

     @pre  The given receiver, sender, and amount are correct.

     @post  A transaction that is to the given receiver, is from the given sender, and is of the given
        amount exists. 
    
     @param newReceiver  The receiver of the new transaction.
    
     @param newSender  The sender of the new transaction.
     
     @param newAmount  The amount of the new transaction. */
    Transaction(const std::string& newReceiver, const std::string& newSender, const int& newAmount);


    /** The method getReceiver returns the receiver of this transaction.

     @pre  This transaction has a valid receiver, which is always true in this situation.

     @post  This transaction does not change.

     @return  The receiver of this transaction. */
    std::string getReceiver() const;


    /** The method getSender returns the sender of this transaction.

     @pre  This transaction has a valid sender, which is always true in this situation.

     @post  This transaction does not change.

     @return  The sender of this transaction. */
    std::string getSender() const;


    /** The method getAmount returns the amount of this transaction.

     @pre  This transaction has a valid amount, which is always true in this situation.

     @post  This transaction does not change.

     @return  The amount of this transaction. */
    int getAmount() const;
};