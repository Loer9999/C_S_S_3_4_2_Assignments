#pragma once

template<class ItemType>
class Node
{
private:
    ItemType value;
    Node<ItemType>* next;

public:
    /** The default constructor creates an empty node that points to null.

     @pre  N/A.

     @post  An empty node that points to null exists. */
    Node();


    /** This parametrized constructor creates a new node that contains the given value and points
        to null.

     @pre  The given value is the value to store in the new node.

     @post  A new node that contains the given value and points to null exists.

     @param initialValue  The value to store in the new node. */
    Node(const ItemType& initialValue);


    /** This parametrized constructor creates a new node that contains the given value and 
        points to the given node.

     @pre  The given value is the value to store in the new node; the given node is the node that
        the new node will point to.

     @post  A new node that contains the given value and points to the given node exists.

     @param initialValue  The value to store in the new node. 
    
     @param nextNode  A pointer to the node that the new node will point to. */
    Node(const ItemType& initialValue, Node<ItemType>* nextNode);


    /** The destructor deletes this node.

     @pre  N/A.

     @post  This node does not exist. */
    virtual ~Node();


    /** The method setValue sets the value of this node to the given value.

     @pre  The given value is the value to store in this node.

     @post  This node contains the given value.

     @param newValue  The value to store in this node. */
    virtual void setValue(const ItemType& newValue);


    /** The method setNext sets this node to point to the given node.

     @pre  The given node is the node that this node will point to.

     @post  This node points to the given node.

     @param newNext  A pointer to the node that this node will point to. */
    virtual void setNext(Node<ItemType>* newNext);


    /** The method getValue returns the value of this node.

     @pre  This node is not empty.

     @post  This node does not change.

     @return  The value of this node. */
    virtual ItemType getValue() const;


    /** The method getNext returns a pointer to the node that this node points to.

     @pre  N/A.

     @post  This node does not change.

     @return  A pointer to the node that this node points to. */
    virtual Node<ItemType>* getNext() const;
};

#include "Node.cpp"