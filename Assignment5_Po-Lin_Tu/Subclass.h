#pragma once

#include "Superclass.h"

class Subclass : public Superclass
{
private:
    int* subData;

public:
    /** The default constructor creates an instance of the subclass.

     @pre  N/A.

     @post  An instance of the subclass exists. A message is printed to indicate that the constructor
        is called. */
    Subclass();


    /** The destructor deletes this instance of the subclass and frees the memory that was dynamically
        allocated to the data of this instance.

     @pre  N/A.

     @post  This instance of the subclass does not exist, and the memory that was dynamically allocated
        to the data of this instance is freed. A message is printed to indicate that the destructor is 
        called. */
    ~Subclass();
};