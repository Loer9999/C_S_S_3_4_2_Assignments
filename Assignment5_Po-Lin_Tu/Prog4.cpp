#include <iostream>
#include "Subclass.h"

int main()
{
    std::cout<< std::endl << "Situation 4:" << std::endl << std::endl;


    std::cout << "Create an instance of the subclass, and use a pointer of type" << std::endl
              << "superclass to point to this instance. Both the constructor of" << std::endl
              << "the superclass and the constructor of the subclass are expected" << std:: endl
              << "to be callled." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    Superclass* instance = new Subclass();
    std::cout << "-------------------------------------------------------------" << std::endl;


    // If the destructor of the superclass is not virtual, using delete on the pointer that is of type
    // superclass and points to an instance of the subclass only calls the destructor of the superclass.
    // That is, the destructor of the subclass is not called, which leads to a memory leak because the
    // destructor of the subclass frees the memory that is dynamically allocated to the data member of
    // the subclass. To prevent a memory leak, one must make the destructor of the superclass virtual
    // so that both the destructor of the superclass and the destructor of the subclass are called.
    std::cout << "Delete this instance of the subclass. Both the destructor of" << std::endl
              << "the superclass and the destructor of the subclass are expected" << std::endl
              << "to be called. Since the destructor of the superclass frees the" << std::endl
              << "memory that was dynamically allocated to the data member of the" << std::endl
              << "superclass and the destructor of the subclass frees the memory" << std::endl
              << "that was dynamically allocated to the data member of the subclass," << std::endl
              << "there is expected to be no memory leak." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    delete instance;
    std::cout << "-------------------------------------------------------------" << std::endl;

    return 0;
}