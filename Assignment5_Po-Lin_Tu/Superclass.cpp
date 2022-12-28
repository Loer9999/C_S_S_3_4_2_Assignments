#include <iostream>
#include "Superclass.h"

Superclass::Superclass() : superData(new int(0))
{
    // Create an instance of the superclass.

    // Print a message to indicate that the constructor is called.
    std::cout << "The constructor of the superclass is called." << std::endl;
}


Superclass::~Superclass()
{
    // Delete this instance of the superclass. Since the superclass uses dynamic memory allocation,
    // the destructor must free the dynamically allocated memory.
    delete superData;
    superData = nullptr;


    // Print a message to indicate that the destructor is called.
    std::cout << "The destructor of the superclass is called." << std::endl;
}