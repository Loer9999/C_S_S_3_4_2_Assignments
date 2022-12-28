#pragma once

#include <map>
#include <string>
#include "Node.h"

class State : public Node<int>
{
private:
    std::map<std::string, int> summary;

public:
    // Since the system does not need an empty State node, this class does not have a default constructor.


    /** This parametrized constructor creates a new State node that contains the given map, which is a
        summary of the accounts in the system.

     @pre  The given map is a summary of the accounts in the system.

     @post  A State node that contains the summary exists.

     @param newSummary  A summary of the accounts in the system. */
    State(const std::map<std::string, int>& newSummary);


    /** The method getSummary returns the summary in this State node.

     @pre  This State node contains a summary, which is always true in this situation.

     @post  This State node does not change.

     @return  The summary in this State node. */
    std::map<std::string, int> getSummary() const;
};