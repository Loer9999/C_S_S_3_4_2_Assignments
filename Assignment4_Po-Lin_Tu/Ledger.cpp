#include <memory>
#include <map>
#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include "Ledger.h"

std::map<std::string, int> Ledger::summaryHelper() const
{
    std::map<std::string, int> summary;

    // Access the most recent summary if there is one.
    if (recentSummary != front)
    {
        // Convert the node that is pointed by the pointer recentSummary to a reference to a State node
        // and use the reference to access the summary in the State node. This solution is from
        // https://stackoverflow.com/questions/30150115/cant-cast-superclass-to-subclass
        summary = static_cast<State&>(*recentSummary).getSummary();
    }

    std::shared_ptr<Node<int>> current(recentSummary -> getNext());

    // Access and perform each of the transactions that are not included in the most recent summary.
    while (current != nullptr)
    {
        // Convert the node that is pointed by the pointer current to a reference to a transaction and
        // use the reference to create a copy of the transaction.
        Transaction copy(static_cast<Transaction&>(*current));
        std::map<std::string, int>::iterator it;

        // Perform the transaction.
        // Transfer money from the sender if the sender is not EXTERNAL.
        if (copy.getSender() != "EXTERNAL")
        {
            it = summary.find(copy.getSender());
            if (it != summary.end())
            {
                it -> second -= copy.getAmount();
            } 
            else
            {
                summary[copy.getSender()] = (-copy.getAmount());
            }
        }

        // Transfer money to the receiver.
        it = summary.find(copy.getReceiver());
        if (it != summary.end())
        {
            it -> second += copy.getAmount();
        }
        else
        {
            summary[copy.getReceiver()] = copy.getAmount();
        }

        current = current -> getNext();
    }
    // Return a summary that is created from the transactions in this ledger.
    return summary;
}


void Ledger::printHelper(const std::string& whichMethod) const
{
    // Create a summary of the accounts in the system.
    std::map<std::string, int> summary(summaryHelper());
    std::map<std::string, int>::iterator it(summary.begin());
    std::map<std::string, int>::iterator end(summary.end());

    if (it == end)
    {
        std::cout <<  "There are not any transactions in this ledger." << std::endl;
    }
    else
    {
        // Access each account in the system.
        do
        {
            bool condition = true;

            // Only print the name and balance of each of the users whose accounts have positive money if
            // the method inTheBlack calls this helper method.
            if (whichMethod == "inTheBlack")
            {
                condition = (it -> second) > 0;
            }
            // Only print the name and balance of each of the users whose accounts have negative money if
            // the method inTheRed calls this helper method.
            else if (whichMethod == "inTheRed")
            {
                condition = (it -> second) < 0;
            }
            // Print the name and balance of each user in the system if the method settle calls this helper
            // method.


            if (condition)
            {
                std::cout << "Name: " << it -> first << std::endl;
                std::cout << "Balance: " << it -> second << std::endl;
                std::cout << "------------------------------" << std::endl;
            }

            it++;

        } while (it != end);
    }
}


Ledger::Ledger()
{
    // Create an empty ledger. All the shared pointers of the Ledger class point to a dummy node.
    front = std::make_shared<Node<int>>();
    back = front;
    recentSummary = front;

    // Set the data member value of the dummy node to 0, which is the transaction count.
    back -> setValue(0);

    // Explicitly set the data member next of the dummy node to nullptr.
    back -> setNext(nullptr);
}


Ledger::~Ledger()
{
    // Free the memory that was allocated for the transactions and the summaries in this ledger.
    front = nullptr;
    back = nullptr;
    recentSummary = nullptr;
}


Ledger& Ledger::operator+=(const Transaction& transaction)
{
    // Place the transaction after the dummy node if this ledger is empty. Additionally, place the transaction
    // after another transaction if the ledger is not empty and the node on the back is another transaction.
    if (back -> getNext() == nullptr)
    {
        back -> setNext(std::make_shared<Transaction>(transaction));

        // Increment the transaction count.
        back -> getNext() -> setValue(back -> getValue() + 1);

        // Update the pointer back.
        back = back -> getNext();
        back -> setNext(nullptr);
    }
    // Place the transaction after the State node if the ledger is not empty and the node on the back is
    // a State node that contains a summary.
    else
    {
        recentSummary -> setNext(std::make_shared<Transaction>(transaction));

        // Increment the transaction count.
        recentSummary -> getNext() -> setValue(recentSummary -> getValue() + 1);

        // Update the pointer back.
        back = recentSummary -> getNext();
        back -> setNext(nullptr);
    }

    // Add a new summary of the accounts in the system to the ledger for every 10 transactions.
    if (back -> getValue() == 10)
    {
        // Place a State node that contains a summary after the transaction. 
        back -> setNext(std::make_shared<State>(State(summaryHelper())));

        // Update the pointer recentSummary.
        recentSummary = back -> getNext();

        // Reset the transaction count.
        recentSummary -> setValue(0);
    }

    return *this;
}


Ledger& Ledger::operator-=(const Transaction& transaction)
{
    std::shared_ptr<Node<int>> current(recentSummary);
    bool deletion = false;

    // Access and check each of the transactions that are in the ledger and are not included the
    // most recent summary.
    while (!deletion && current -> getNext() != nullptr)
    {
        // Convert the node that is pointed by (current -> getNext()) to a reference to a transaction and
        // use the reference to create a copy of the transaction.
        Transaction copy(static_cast<Transaction&>(*(current -> getNext())));

        // Delete the transaction if it matches the transaction on the right hand side of the operator -=.
        if (copy.getReceiver() == transaction.getReceiver() &&
            copy.getSender() == transaction.getSender() &&
            copy.getAmount() == transaction.getAmount())
        {
            current -> setNext(current -> getNext() -> getNext());

            // Update the pointer back if the deleted transaction is the last transaction.
            if (current -> getNext() == nullptr)
            {
                back = current;
            }
            deletion = true;
        }
        
        current = current -> getNext();
    }

    // Throw an exception if the transaction on the right hand side does not exist.
    if (!deletion)
    {
        throw std::invalid_argument("The transaction to delete does not exist.");
    }
    return *this;
}


void Ledger::clear()
{
    // Empty this ledger.
    back = front;
    recentSummary = front;
    front -> setNext(nullptr);
}


std::ostream& operator<<(std::ostream& output, const Ledger& ledger)
{
    output << "All Transactions: " << std::endl;
    output << std::endl;

    if (ledger.front == ledger.back)
    {
        output << "There are not any transactions in this ledger." << std::endl;
    }
    else
    {
        std::shared_ptr<Node<int>> current(ledger.front);

        // Access and write every transaction.
        while (current != nullptr)
        {
            // Skip the dummy node and the State nodes.
            if (current -> getValue() != 0)
            {
                // Convert the node that is pointed by the pointer current to a reference to a transaction and
                // use the reference to create a copy of the transaction.
                Transaction copy(static_cast<Transaction&>(*current));
                output << "To: " << copy.getReceiver() << std::endl;
                output << "From: " << copy.getSender() << std::endl;
                output << "Amount: " << copy.getAmount() << std::endl;
                output << "------------------------------" << std::endl;
            }
        
            current = current -> getNext();
        }
    }
    return output;
}


void Ledger::settle() const
{
    std::cout << "All Accounts: " << std::endl;
    std::cout << std::endl;
    printHelper("settle");
}


void Ledger::inTheBlack() const
{
    std::cout << "All Accounts with Positive Balance: " << std::endl;
    std::cout << std::endl;
    printHelper("inTheBlack");
}


void Ledger::inTheRed() const
{
    std::cout << "All Accounts with Negative Balance: " << std::endl;
    std::cout << std::endl;
    printHelper("inTheRed");
}