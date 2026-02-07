#pragma once
#include <iostream>
using namespace std;

template <class t>
class clsDynamicArray
{
protected:
	size_t _size;
	t* _MyArray;

public:
	clsDynamicArray(int size = 0)
	{
		if (size < 0)
			size = 0;

		_size = size;
		_MyArray = new t[size];
	}

	clsDynamicArray(const clsDynamicArray& other)
	{
		// this is a copy constructor to perform copy operation create a new list in memory with a same values same size 
		// Copy when creation an object is valid after this code (clsDynamicArray<int> a = b;)
		// but a = b (after creation) i  make it invalid 
		_size = other._size;
		_MyArray = new t[_size];

		for (size_t i = 0; i < _size; i++)
		{
			_MyArray[i] = other._MyArray[i];
		}

	}

	clsDynamicArray& operator=(const clsDynamicArray&) = delete; // to be a copy after creation an object invalid (منع النسخ بعد الانشاء )

	~clsDynamicArray()
	{
		delete[] _MyArray;
	}

	bool SetItem(size_t index, t value)
	{
		if (index >= _size) // size_t not a minus number 
			return false;

		_MyArray[index] = value;
		return true;
	}

	bool IsEmpty() const
	{
		return _size == 0;
	}

	int Size() const { return _size; }

	void Print() const
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << _MyArray[i] << "\t";
		}
		cout << "\n";
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		t* newMyArray = new t[newSize];

		if (newSize < _size)
			_size = newSize;

		for (size_t i = 0; i < _size; i++)
		{
			newMyArray[i] = _MyArray[i];
		}

		_size = newSize;

		delete[] _MyArray;

		_MyArray = newMyArray;


	}

	t GetItem(int index) const
	{
		if (index < 0 || index >= _size)
		{
			throw out_of_range("out of range");
		}
		return _MyArray[index];
	}

	void Clear()
	{
		delete[] _MyArray;
		_MyArray = nullptr;
		_size = 0;
	}

	void Reverse()
	{

		if (_size <= 1)
			return;

		t* tempArray = new t[_size];

		for (size_t i = 0; i < _size; i++)
		{
			tempArray[i] = _MyArray[_size - 1 - i];
		}

		delete[] _MyArray;

		_MyArray = tempArray;

	}

	bool DeleteItemAt(int index) // Another algorithm Using 2 loops maybe faster than first method a few because there is not if in loop 
	{
		if (index < 0 || index >= _size)
			return false;

		if (_size == 1)
		{
			this->Clear();
			return true;
		}

		t* tempArray = new t[_size - 1];

		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = _MyArray[i];
		}

		for (size_t i = index + 1; i < _size; i++)
		{
			tempArray[i - 1] = _MyArray[i];
		}

		delete[] _MyArray;
		_size--;
		_MyArray = tempArray;
		return true;


	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_size - 1);
	}

	int Find(t value) const // O(n)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_MyArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(t value)
	{
		int index = Find(value);
		if (index == -1) // we can remove this line because inside Method DeleteItemAt we check before bit this for best practise 
			return 0;
		return DeleteItemAt(index);
	}

	void DeleteAllItemByValue(t value) // But maybe this be slow if a a number of element big so we can use copy in another array without values
	{
		while (DeleteItem(value));
	}

	bool InsertAt(int index, t value) {

		if (index > _size || index < 0)
		{
			return false;
		}

		_size++;

		t* _TempArray = new t[_size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = _MyArray[i];
		}

		_TempArray[index] = value;

		//copy all after index
		for (int i = index; i < _size - 1; i++)
		{
			_TempArray[i + 1] = _MyArray[i];
		}

		delete[] _MyArray;
		_MyArray = _TempArray;
		return true;

	}

	bool InsertAtBeginning(t value)
	{
		return InsertAt(0, value);
	}

	bool InsertBefore(int index, t value)
	{
		return InsertAt(index, value);
	}

	bool InsertAfter(int index, t value)
	{
		return InsertAt(index + 1, value);
	}

	bool InsertAtEnd(t value)
	{
		return InsertAt(_size, value);
	}


};


