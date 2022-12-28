#include <map>
#include <string>
#include "State.h"

State::State(const std::map<std::string, int>& newSummary) : Node<int>(), summary(newSummary)
{
    // Create a new State node that contains a summary of the accounts the system.
}


std::map<std::string, int> State::getSummary() const
{
    return summary;
}