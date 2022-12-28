#pragma once

#include <iostream>
#include "Node.h"

template<class ItemType>
class LinkedList
{
private:
    Node<ItemType>* head;
    Node<ItemType>* tail;

public:
    /** The default constructor creates an empty linked list.

     @pre  N/A.

     @post  An empty linked list exists. */
    LinkedList();


    /** The copy constructor creates a linked list that is the same as the given linked list.

     @pre  N/A.

     @post  A linked list that is the same as the given linked list exists. 
     
     @param other  The linked list to copy.
    LinkedList(const LinkedList<ItemType>& other);
    */
    


    /** The destructor deletes this linked list and frees the memory that was dynamically allocated
        to the nodes in this linked list.

     @pre  N/A.

     @post  This linked list does not exist, and the memory that was dynamically allocated to the
        nodes is freed. */
    ~LinkedList();


    /** The method add adds the given node to the end of this linked list.

     @pre  N/A.

     @post  The given node is the last node of this linked list.

     @param node  The node to add to this linked list. */
    void add(const Node<ItemType>& node);


    /** The method replace replaces a specified data item in this linked list with the given data item.

     @pre  The data item to replace exists in this linked list.

     @post  The first data item that matches the specified data item is replaced with the given data
        item. If the specified data item does not exist in this linked list, an exception is thrown.

     @param origin  The data item to replace.

     @param other  The data item to substitute for the data item to replace. */
    void replace(const ItemType& origin, const ItemType& other);


    /** The method operator<< overloads the operator <<, writing all data items in the linked list,
        which is on the right hand side of the operator <<, through the ostream object, which is
        on the left hand side.

     @pre  N/A.

     @post  All data items in the linked list are written through the ostream object.

     @param output  An ostream object.

     @param list  The linked list whose data items are to be written.

     @return  A reference to the ostream object. */
    template<class ListItemType>
    friend std::ostream& operator<<(std::ostream& output, const LinkedList<ListItemType>& list);
};

#include "LinkedList.cpp"