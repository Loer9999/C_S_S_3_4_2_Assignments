#include <stdexcept>
#include <iostream>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : head(nullptr), tail(nullptr)
{
    // Create an empty linked list.
}


/*
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& other) : head(nullptr), tail(nullptr)
{
    Node<ItemType>* current = other.head;


    // Copy each of the nodes in the given linked list.
    while (current != nullptr)
    {
        add(Node<ItemType>(current -> getValue()));
        current = current -> getNext();
    }
}
*/


template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    tail = nullptr;


    // Empty this linked list and free the memory that was dynamically allocated to the nodes.
    while (head != nullptr)
    {
        Node<ItemType>* temp = head;
        head = head -> getNext();
        delete temp;
        temp = nullptr;
    }
}


template<class ItemType>
void LinkedList<ItemType>::add(const Node<ItemType>& node)
{
    // Dynamically allocate memory to the given node.
    Node<ItemType>* temp = new Node<ItemType>(node);


    // Make the pointers, the head and the tail, point to the given node if this linked list is empty.
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    // Make the last node in this linked list point to the given node and update the pointer tail if
    // this linked list is not empty.
    else
    {
        tail -> setNext(temp);
        tail = tail -> getNext();
    }
}


template<class ItemType>
void LinkedList<ItemType>::replace(const ItemType& origin, const ItemType& other)
{
    bool replace = false;
    Node<ItemType>* current = head;


    // Search for the specified data item and replace that data item.
    while (!replace && current != nullptr)
    {
        if (current -> getValue() == origin)
        {
            current -> setValue(other);
            replace = true;
        }
        current = current -> getNext();
    }


    // Throw an exception if the replacement did not happen.
    if (!replace)
    {
        throw std::invalid_argument("The specified data item does not exist.");
    }
}


template<class ItemType>
std::ostream& operator<<(std::ostream& output, const LinkedList<ItemType>& list)
{
    Node<ItemType>* current = list.head;


    // Write each of the data items in the linked list.
    while (current != nullptr)
    {
        output << (current -> getValue()) << " ";
        current = current -> getNext();
    }


    return output;
}
