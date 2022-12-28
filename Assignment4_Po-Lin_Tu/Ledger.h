#pragma once

#include <memory>
#include <map>
#include <string>
#include <iostream>
#include "State.h"
#include "Transaction.h"

class Ledger
{
private:
    std::shared_ptr<Node<int>> front;
    std::shared_ptr<Node<int>> back;
    std::shared_ptr<Node<int>> recentSummary;


    /** The method summaryHelper creates a summary of the accounts in the system from the transactions
        in this ledger.

     @pre  There is at least one transaction in this ledger.

     @post  This ledger does not change.

     @return  A map that is a summary of the accounts in the system. */
    std::map<std::string, int> summaryHelper() const;


    /** The method printHelper prints the name and balance of each of the users whose accounts satisfy
        the certain conditions that are made by the methods that call this helper method.

     @pre  N/A.

     @post  This ledger does not change.

     @param whichMethod  A string that indicates which method calls this helper method. */
    void printHelper(const std::string& whichMethod) const;


public:
    /** The default constructor creates an empty ledger.

     @pre  N/A.

     @post  An empty ledger exists. */
    Ledger();


    /** The destructor frees all the allocated memory.

     @pre  N/A.

     @post  The memory that was allocated for this ledger is free. */
    ~Ledger();


    /** The method operator+= overloads the operator +=, adding the transaction, which is on the
        right hand side of the operator +=, to this ledger, which is on the left hand side.

     @pre  The transaction is correct.

     @post  The transaction is added to this ledger. For every 10 transactions, a new summary of the 
         accounts in the system is added to this ledger.

     @param transaction  The transaction to add.

     @return  A reference to this ledger. */
    Ledger& operator+=(const Transaction& transaction);


    /** The method operator-= overloads the operator -=, deleting the transaction, which is on the
        right hand side of the operator -=, from this ledger, which is on the left hand side. The
        deletion only involves the transactions that are not included in the most recent summary.

     @pre  The transaction exists in the ledger and is not included in the most recent summary.

     @post  One transaction that matches the transaction on the right hand side is deleted from this
        ledger. If the transaction on the right hand side does not exist outside the summary, an 
        exception is thrown.

     @param transaction  The transaction to delete.

     @return  A reference to this ledger. */
    Ledger& operator-=(const Transaction& transaction);


    /** The method clear deletes all the transactions from this ledger.

     @pre  N/A.

     @post  This ledger becomes empty. */
    void clear();


    /** The method operator<< overloads the operator <<, writing every transaction in the ledger,
        which is on the right hand side of the operator <<, through the ostream object, which is
        on the left hand side.

     @pre  N/A.

     @post  All the transactions in the ledger are written through the ostream object. The ledger
        does not change.

     @param output  An ostream object.

     @param ledger  The ledger whose transactions are to be written.

     @return  A reference to the ostream object. */
    friend std::ostream& operator<<(std::ostream& output, const Ledger& ledger);


    /** The method settle prints the name and balance of each user in the system based on this ledger.
    
     @pre  N/A.

     @post  This ledger does not change. */
    void settle() const;


    /** The method inTheBlack prints the name and balance of each of the users whose accounts have
        postive money based on this ledger.

     @pre  N/A.

     @post  This ledger does not change. */
    void inTheBlack() const;


    /** The method inTheRed prints the name and balance of each of the users whose accounts have
        negative money based on this ledger.

     @pre  N/A.

     @post  This ledger does not change. */
    void inTheRed() const;
};