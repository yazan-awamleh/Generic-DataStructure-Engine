#pragma once
#include <iostream>
using namespace std;
#include "clsDoublyLinkedList.h"	


// here use and rev. a composition and abstraction and adapter design patterns time complixty in dbl linked list is excellent and why Rev this concepts very important 

template <class t>
class clsMyQueue
{
protected:
	clsDoublyLinkedList<t> _MyQueue; // this concept call Composition def an object in a another class better than inhertance here 

public:
	void push(t value)
	{
		_MyQueue.InsertAtEnd(value);
	}

	void pop()
	{
		_MyQueue.DeleteFirstNode();
	}

	void Print() const
	{
		_MyQueue.Print();
	}

	inline int Size() const { return _MyQueue.Size(); }

	t front() const
	{
		return _MyQueue.GetFirst();
	}

	t back() const
	{
		return _MyQueue.GetLast();
	}

	inline bool IsEmpty() const { return _MyQueue.IsEmpty(); }

	t GetItem(int index) const
	{
		return _MyQueue.GetItem(index);
	}

	void Reverse()
	{
		_MyQueue.Reverse();
	}

	bool UpdateItem(int index, t newValue)
	{
		return _MyQueue.UpdateItem(index, newValue);
	}

	void InsertAfter(int index, t value)
	{
		_MyQueue.InsertAfter(index, value);
	}

	void InsertAtFront(t value)
	{
		_MyQueue.InsertAtBeginning(value);
	}

	void InsertAtBack(t value)
	{
		push(value);
	}

	void Clear()
	{
		_MyQueue.Clear();
	}

};

