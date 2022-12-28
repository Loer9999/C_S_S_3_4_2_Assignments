#include <memory>

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
    // Create an empty node that points to null.
}


template<class ItemType>
Node<ItemType>::Node(const ItemType& initialValue) : value(initialValue), next(nullptr)
{
    // Create a node that contains the given value and points to null.
}


template<class ItemType>
Node<ItemType>::Node(const ItemType& initialValue, const std::shared_ptr<Node<ItemType>>& nextNode) : 
value(initialValue), next(nextNode)
{
    // Create a node that contains the given value and points to the given node.
}


template<class ItemType>
void Node<ItemType>::setValue(const ItemType& newValue)
{
    // Set the value to the given value.
    value = newValue;
}


template<class ItemType>
void Node<ItemType>::setNext(const std::shared_ptr<Node<ItemType>>& newNext)
{
    // Set this node to point to the given node.
    next = newNext;
}


template<class ItemType>
ItemType Node<ItemType>::getValue() const
{
    return value;
}


template<class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const
{
    return next;
}