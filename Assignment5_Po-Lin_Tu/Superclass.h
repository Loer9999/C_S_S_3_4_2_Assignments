#pragma once

class Superclass
{
private:
    int* superData;

public:
    /** The default constructor creates an instance of the superclass.

     @pre  N/A.

     @post  An instance of the superclass exists. A message is printed to indicate that the constructor
        is called. */
    Superclass();


    /** The destructor deletes this instance of the superclass and frees the memory that was dynamically
        allocated to the data of this instance.

     @pre  N/A.

     @post  This instance of the superclass does not exist, and the memory that was dynamically allocated
        to the data of this instance is freed. A message is printed to indicate that the destructor is 
        called. */
    ~Superclass();
};