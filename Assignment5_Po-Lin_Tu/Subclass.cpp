#include <iostream>
#include "Subclass.h"

Subclass::Subclass() : subData(new int(0))
{
    // Create an instance of the subclass.

    // Print a message to indicate that the constructor is called.
    std::cout << "The constructor of the subclass is called." << std::endl;
}


Subclass::~Subclass()
{
    // Delete this instance of the subclass. Since the subclass uses dynamic memory allocation,
    // the destructor must free the dynamically allocated memory.
    delete subData;
    subData = nullptr;


    // Print a message to indicate that the destructor is called.
    std::cout << "The destructor of the subclass is called." << std::endl;
}