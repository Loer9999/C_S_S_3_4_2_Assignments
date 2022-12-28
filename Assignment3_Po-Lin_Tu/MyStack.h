#pragma once

#include <list>
#include <iostream>

template<class T>
class MyStack
{
private:
    std::list<T> myStack;

public:
    /** The method push adds the specified value onto my stack.

     @pre  N/A.

     @post  The specified value is on the top of my stack. */
    void push(const T& value);


    /** The method pop removes and returns the value on the top of my stack.

     @pre  My stack has at least one value left.

     @post  This method removes the topmost value on my stack and returns a copy of that value.
        If my stack has no value left when this method is called, this method throws an error.

     @return  The removed value. */
    T pop();


    /** The method peek returns the value on the top of my stack.

     @pre  My stack has at least one value left.

     @post  This method returns a copy of the topmost value on my stack; my stack does not change.
        If my stack has no value left when this method is called, this method throws an error.

     @return  The topmost value. */
    T peek() const;


    /** The method empty checks whether my stack is empty.

     @pre  N/A.

     @post  This method reports whether my stack is empty; my stack does not change.

     @return  true if my stack is empty; false otherwise. */
    bool empty() const;


    /** The method size checks the size of my stack.

     @pre  N/A.

     @post  This method returns the size of my stack; my stack does not change.

     @return  The number of values on my stack. */
    int size() const;


    /** The method clear empties my stack.

     @pre  N/A.

     @post  My stack becomes empty. */
    void clear();


    /** The method operator<< overloads the operator <<, writing my stack, which is on the right hand
        side of the operator <<, through an ostream object, which is on the left hand side of the
        operator <<.

     @pre  N/A.

     @post  This method writes my stack through the ostream object; my stack does not change.

     @param output  An ostream object.

     @param stack  The stack to write.

     @return  A reference to the ostream object. */
    template<class Type>
    friend std::ostream& operator<<(std::ostream& output, const MyStack<Type>& stack);
};

#include "MyStack.cpp"