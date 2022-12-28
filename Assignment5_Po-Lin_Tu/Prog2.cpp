#include <iostream>
#include "Node.h"

int main()
{
    std::cout<< std::endl << "Situation 2:" << std::endl << std::endl;


    std::cout << "Use a for loop to repeatedly add integers into a linked list." << std::endl
              << "This for loop contains an if statement that should prevent" << std::endl
              << "the linked list from occupying too much memory by pruning off" << std::endl
              << "the first integer in the linked list if the linked list has" << std::endl
              << "more than 10000 integers." << std::endl
              << "-------------------------------------------------------------" << std::endl;
    Node<int>* head = new Node<int>(0);
    Node<int>* current = head;
    int size = 1;
    for (int i = 1; i <= 2000000000; i++)
    {
        // Add an integer to the linked list.
        current -> setNext(new Node<int>(i));
        current = current -> getNext();
        

        // Prune off the first integer in the linked list if the linked list has 10001 integers.
        if (size == 10000)
        {
            // Making the pointer head points to the second node in the linked list prunes off the
            // first node, but this produces a memory leak at the same time. The node that is
            // pruned off still stays in a block of memory, and that block of memory is not freed.
            // In other words, the memory that was once occupied by the linked list is never released
            // and returned to the system. To release and return the memory that the linked list
            // occupies, one must keep a reference to the first node before making the pointer head
            // point to the second node and use delete on the first node.
            head = head -> getNext();
        }
        else
        {
            size++;
        }
    }


    std::cout << "The for loop successfully adds 2000000000 integers into the" << std::endl
              << "linked list while pruning off the first integers so that the" << std::endl
              << "linked list does not occupy too much memory." << std::endl
              << "-------------------------------------------------------------" << std::endl;

    return 0;
}