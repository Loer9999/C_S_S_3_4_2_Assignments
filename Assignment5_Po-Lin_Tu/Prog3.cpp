#include <iostream>

int main()
{
    std::cout<< std::endl << "Situation 3:" << std::endl << std::endl;


    std::cout << "Dynamically allocate two variables of type integer, a and b." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    int* a = new int(100);
    int* b = new int(200);


    std::cout << " a is expected to point to 100." << std::endl
              << " a in fact points to " << *a << "." << std::endl
              << " b is expected to point to 200." << std::endl
              << " b in fact points to " << *b << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    // When one uses delete on a and b, the memory that was dynamically allocated to a and b is
    // released and returned to the system. However, a and b continue to exist, and they have the
    // addresses of the memory that no longer belongs to them. The system may allocate the memory
    // that no longer belongs to a and b to other variables, which makes a and b point to the
    // values that are pointed by other variables. To prevent a and b from pointing to unexpected
    // values, one must set a and b to nullptr after using delete on them so that one cannot
    // dereference a and b and get unexpected values.
    delete a;
    delete b;


    std::cout << "Perform operations and calculations that do not intend to" << std::endl
              << "change what a and b point to, including dynamically allocating" << std::endl
              << "two more variables, c and d" << std::endl
              << "-------------------------------------------------------------" << std::endl;
    int* c = new int(300);
    int* d = new int(400);
    int* addition = new int(*c + *d);


    // a and b end up pointing to what c and d point to.
    std::cout << " a is expected to point to 100." << std::endl
              << " a in fact points to " << *a << "." << std::endl
              << " b is expected to point to 200." << std::endl
              << " b in fact points to " << *b << "." << std::endl
              << " c is expected to point to 300." << std::endl
              << " c in fact points to " << *c << "." << std::endl
              << " d is expected to point to 400." << std::endl
              << " d in fact points to " << *d << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    

    std::cout << std::endl << std::endl;


    delete c;
    delete d;
    delete addition;


    return 0;
}