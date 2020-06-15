#pragma once
#include <iostream>

using namespace std;

template<typename T> class StackItem
{
private:
	T item;
	StackItem<T>* prev;
public:
	StackItem(T item, StackItem<T>* next);
	~StackItem();

	const T GetItem() const;
	StackItem<T>* GetPrev() const;
	void SetItem(const T item);
	void SetPrev(StackItem<T>* prev);
};

template<typename T> StackItem<T>::StackItem(T item, StackItem<T>* next)
{
	this->item = item;
	this->prev = prev;
}

template<typename T> StackItem<T>::~StackItem()
{
	//
}

template<typename T> void StackItem<T>::SetItem(const T item)
{
	this->item = item;
}

template<typename T> inline void StackItem<T>::SetPrev(StackItem<T>* prev)
{
	this->prev = prev;
}

template<typename T> const T StackItem<T>::GetItem() const
{
	return this->item;
}

template<typename T> inline StackItem<T>* StackItem<T>::GetPrev() const
{
	return this->prev;
}
