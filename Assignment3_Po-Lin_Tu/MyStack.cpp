#include <iostream>

template<class T>
void MyStack<T>::push(const T& value)
{
    myStack.push_back(value);
}


template<class T>
T MyStack<T>::pop()
{
    if (myStack.empty())
    {
        std::cerr << "The stack does not have any values to pop." << std::endl;
        throw "Error";
    }
    T temp = myStack.back();
    myStack.pop_back();
    return temp;
}


template<class T>
T MyStack<T>::peek() const
{
    if (myStack.empty())
    {
        std::cerr << "The stack does not have any values to peek." << std::endl;
        throw "Error";
    }
    return myStack.back();
}


template<class T>
bool MyStack<T>::empty() const
{
    return myStack.empty();
}


template<class T>
int MyStack<T>::size() const
{
    return myStack.size();
}


template<class T>
void MyStack<T>::clear()
{
    while (!myStack.empty())
    {
        myStack.pop_back();
    }
}


template<class T>
std::ostream& operator<<(std::ostream& output, const MyStack<T>& stack)
{
    if (stack.empty())
    {
        std::cout << "The stack is empty.";
    }
    else
    {
        std::cout << "The stack currently contains: ";
        for (T val : stack.myStack)
        {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
    return output;
}