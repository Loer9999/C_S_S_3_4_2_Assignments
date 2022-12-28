#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
    std::cout<< std::endl << "Situation 5:" << std::endl << std::endl;


    std::cout << "Dynamically allocate a linked list, which is called list1." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    LinkedList<int>* list1 = new LinkedList<int>();
    list1 -> add(Node<int>(1));
    list1 -> add(Node<int>(2));
    list1 -> add(Node<int>(3));


    std::cout << " List1 is expected to contain these numbers: 1 2 3 ." << std::endl
              << " List1 in fact contains these numbers: " << *list1 << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    // The default copy constructor that creates list2 only copies the data members of list1. That is,
    // the data members of list1 and the data members of list2 point to the same linked list, and list1
    // and list2 refer to the same linked list instead of two separate linked lists. Thus, when the linked
    // list that list1 refers to is modified, the linked list that list2 refers to is modified at the
    // same time. Additionally, when the destructor is called on list1, the linked list that list2 refers
    // to is also deleted. If the destructor is called on list2 after this, the destructor will
    // produce a segmentation fault since the destructor tries to delete what had been deleted. To
    // fix these problems, one must write a copy constructor that copies the entire linked list to
    // replace the default copy constructor.
    std::cout << "Dynamically allocate another linked list, which is a copy of" <<std::endl
              << "list1 and is called list2." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    LinkedList<int>* list2 = new LinkedList<int>(*list1);


    std::cout << " List2 is expected to contain these numbers: 1 2 3 ." << std::endl
              << " List2 in fact contains these numbers: " << *list2 << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    std::cout << "Replace the numbers in list1 with 4, 5, and 6." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    list1 -> replace(1, 4);
    list1 -> replace(2, 5);
    list1 -> replace(3, 6);


    std::cout << " List1 is expected to contain these numbers: 4 5 6 ." << std::endl
              << " List1 in fact contains these numbers: " << *list1 << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    std::cout << " List2 is expected to contain these numbers: 1 2 3 ." << std::endl
              << " List2 in fact contains these numbers: " << *list2 << "." << std::endl
              << "-------------------------------------------------------------" << std::endl;


    std::cout << "Use delete on list1. The destructor of the linked list is expected" <<std::endl
              << "to free all the memory that was dynamically allocated to list1." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    delete list1;
    list1 = nullptr;


    std::cout << "Use delete on list2. The destructor of the linked list is expected" <<std::endl
              << "to free all the memory that was dynamically allocated to list2." << std::endl
              << "Furthermore, there should not be any segmentation faults." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    delete list2;
    list2 = nullptr;

    return 0;
}