#pragma once
#include <iostream>
using namespace std;
#include "clsDoublyLinkedList.h"

template <class t >
class clsMyStack
{
private:
	clsDoublyLinkedList<t> _MyStack;

public:

	void Print()
	{
		_MyStack.Print();
	}

	void push(t value)
	{
		_MyStack.InsertAtEnd(value);
	}

	void pop()
	{
		if (_MyStack.IsEmpty())
			throw std::out_of_range("Stack is empty");
		_MyStack.DeleteLastNode();
	}

	int Size() const { return _MyStack.Size(); }

	t top() const
	{
		if (Size() == 0)
			throw std::out_of_range("Stack is empty");

		return _MyStack.GetLast(); // O(1)

	}

	t bottom() const
	{
		if (Size() == 0)
			throw std::out_of_range("Stack is empty");

		return _MyStack.GetFirst();

	}

	bool IsEmpty() { return _MyStack.IsEmpty(); }

	void Reverse()
	{
		_MyStack.Reverse();
	}

	void Clear()
	{
		_MyStack.Clear();
	}


};

