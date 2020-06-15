#pragma once
#include "StackItem.hpp"
#include <iostream>

template<typename T> class Stack
{
private:
	int size = 0;
	StackItem<T>* top;

	void DeleteAllItems();
public:
	Stack();
	~Stack();

	void Push(T value);
	T Pop();
	void Delete();
	int Size() const;
};

template<typename T> inline void Stack<T>::DeleteAllItems()
{
	StackItem<T>* item = this->top;
	while (item) {
		this->top = item->GetPrev();
		delete item;
		item = this->top;
		this->size -= 1;
	}
}

template<typename T> inline Stack<T>::Stack()
{
	std::cout << "Stack Constructor" << std::endl;
}

template<typename T> inline Stack<T>::~Stack()
{
	this->DeleteAllItems();
	std::cout << "Stack Destructor" << std::endl;
}

template<typename T> inline void Stack<T>::Push(T value)
{
	StackItem<T>* item = new StackItem<T>(value, NULL);
	if (this->top == NULL) { 
		this->top = item; 
		item->SetPrev(NULL);
	}
	else 
	{
		item->SetPrev(this->top);
		this->top = item;	
	}
	this->size += 1;
}

template<typename T> inline T Stack<T>::Pop()
{
	if (top == NULL) {
		throw "The queue is empty";
	}
	T item = this->top->GetItem();
	this->top = this->top->GetPrev();
	this->size -= 1;
	return item;
}

template<typename T> inline void Stack<T>::Delete()
{
	this->DeleteAllItems();
}

template<typename T> inline int Stack<T>::Size() const
{
	return this->size;
}
