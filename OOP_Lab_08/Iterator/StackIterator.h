#pragma once
#include "Stack.hpp" 
#include "StackItem.hpp"


template <typename T> class StackIterator {
private:
    Stack<T>* stack;
    StackItem<T>* stackItem;
public:
    typedef typename Stack<T> U;

    StackIterator(Stack<T>* stack);
    StackIterator(const StackIterator<T>& v);

    ~StackIterator();

    bool hasNext() const ;
    T getNext();

    StackIterator<T>& operator=(const StackIterator<T>& v);
};

template<typename T>
inline StackIterator<T>::StackIterator(Stack<T>* stack)
{
    //std::cout << "StackIterator<T>::StackIterator(Stack<T>* stack) " << std::endl;
    this->stack = stack;
}

template<typename T>
inline StackIterator<T>::StackIterator(const StackIterator<T>& v)
{
    //std::cout << "Constructor copy ... " << std::endl;
    this->stack = v.stack;
    this->stackItem = v.stackItem;
}


template<typename T>
inline StackIterator<T>::~StackIterator()
{
   /* std::cout << "Destructor ... " << std::endl;*/
}

template<typename T>
inline bool StackIterator<T>::hasNext() const
{
    return  this->stack->Size();
}

template<typename T>
inline T StackIterator<T>::getNext()
{
    if (!this->hasNext()) throw "there is no elements in stack";

    T item = this->stack->Pop();
    return item;
}


template<typename T>
inline StackIterator<T>& StackIterator<T>::operator=(const StackIterator<T>& v)
{
    this->stack = v.stack;
    this->stackItem = v.stackItem;
    return *this;
}


