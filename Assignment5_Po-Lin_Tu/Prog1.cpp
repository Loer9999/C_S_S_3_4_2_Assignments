#include <iostream>

/** The method addition adds the two given integers.

 @pre  N/A.

 @post  This method returns the sum of the two given integers.

 @return  The memory location of a local variable whose value is the sum of the two given integers.

 @param a  An integer.

 @param b  Another integer. */
int* addition(const int& a, const int& b)
{
    // Create a local variable whose value is the sum of the two given integers.
    int sum = a + b;


    // Return the memory location of the local variable.
    int* location = &sum;
    return location;
}


/** The method addition adds the two given integers.

 @pre  N/A.

 @post  This method returns the sum of the two given integers.

 @return  The location of the dynamically allocated memory that has the sum of the two given integers.

 @param a  An integer.

 @param b  Another integer.
int* addition(const int& a, const int& b)
{
    // Dynamically allocate memory to the sum of the two given integers.
    int* location = new int(a + b);


    // Return the location of the dynamically allocated memory.
    return location;
} */


/** The method multiplication multiplies the two given integers.

 @pre  N/A.

 @post  This method returns the result of the multiplication.

 @return  The memory location of a local variable whose value is the result of the multiplication.

 @param a  An integer.

 @param b  Another integer. */
int* multiplication(const int& a, const int& b)
{
    // Create a local variable whose value is the result of the multiplication.
    int result = a * b;


    // Return the memory location of the local variable.
    int* location = &result;
    return location;
}


int main()
{
    std::cout<< std::endl << "Situation 1:" << std::endl << std::endl;


    // Create the pointer a that points to nothing.
    int* a;


    // Making the pointer a have the memory location of a local variable of a function produces an 
    // error in the sense that the local variable is deleted after the funcion exits. In other words,
    // a has the memory location that is free within the system and can be overwritten by another
    // function or other operations. Thus, the pointer a may point to an unexpected value instead of
    // the value of the local variable of the function. To return the result of a function, one can
    // store the result in dynamically allocated memory and make the function return the location of
    // the dynamically allocated memory instead of the location of a local variable.
    std::cout << "Make the pointer a points to the result of the method addition," << std::endl
              << "which calculates the sum of 10 and 30." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    a = addition(10, 30);


    // Store what a points to at this point.
    int temp = *a;


    std::cout << " a is expected to point to 40." << std::endl
              << " a in fact points to " << temp << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    std::cout << "Perform some operations and calculations that do not intend to" << std::endl
              << "change what the pointer a points to." << std::endl
              << "-------------------------------------------------------------" << std::endl;

    
    multiplication(5, 6);
    multiplication(7, 8);


    // Store what a points to at this point.
    temp = *a;


    // a points to 56, the value of the local variable of the method multiplication.
    std::cout << " a is expected to point to 40." << std::endl
              << " a in fact points to " << temp << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    return 0;
}