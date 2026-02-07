#pragma once
#include <iostream>
using namespace std;

template <class t>
class clsDoublyLinkedList
{
protected:

	class Node
	{
	public:
		t value;
		Node* prev;
		Node* next;

		Node() : prev(nullptr), next(nullptr) {}
		Node(t v) : value(v), prev(nullptr), next(nullptr) {}
	};

	size_t _size;

	Node* head;
	Node* tail; //  if (list has only one element)
	//head == tail
	// Using the tail pointer improve the time Complexty to O(1) from O(n) in last methods using loops because i can here access the last element in list dirictly without loop 

public:

	clsDoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

	~clsDoublyLinkedList() { Clear(); }


	void InsertAtBeginning(t value)
	{
		Node* newNode = new Node(value);

		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		_size++;
	}


	// Print the linked list
	void Print() const
	{
		Node* Current = head;

		while (Current != nullptr) {
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";

	}

	/*void DeleteList()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		_size = 0;
		head = nullptr;

	}*/

	void Clear()
	{
		while (_size > 0)
		{
			DeleteFirstNode();
		}
	}

	Node* Find(t value) const
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->value == value)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	void InsertAfter(Node* current, t value) // we use by ref in current just when we change the pointer current to another thing such
		//as current = nullptr but change value or prev or next no need to by ref
	{
		/*  1 - Create a new node with the desired value.
			2-Set the next pointer of the new node to the next node of the current node.
			3-Set the previous pointer of the new node to the current node.
			4-Set the next pointer of the current node to the new node.
			5-Set the previous pointer of the next node to the new node(if it exists).
	   */

		if (current == nullptr)
			return;

		Node* new_Node = new Node(value);

		new_Node->next = current->next;
		new_Node->prev = current;

		if (current->next != nullptr)
		{
			current->next->prev = new_Node;
		}

		current->next = new_Node;
		if (current == tail)
			tail = new_Node;
		_size++;
	}

	void InsertAtEnd(t value)
	{
		Node* new_Node = new Node(value);

		if (tail == nullptr)
		{
			head = tail = new_Node;
		}
		else
		{
			tail->next = new_Node;
			new_Node->prev = tail;
			tail = new_Node;
		}
		_size++;

	}

	void DeleteNode(Node* nodeToDelete)
	{
		if (head == nullptr || nodeToDelete == nullptr)
			return;

		if (head == nodeToDelete)
		{
			head = nodeToDelete->next;
			if (head != nullptr)
				head->prev = nullptr; // equal to NodeToDeleted->next->prev = nullptr;
		}
		else
		{

			if (nodeToDelete->prev != nullptr)
				nodeToDelete->prev->next = nodeToDelete->next;


			if (nodeToDelete->next != nullptr)
				nodeToDelete->next->prev = nodeToDelete->prev;
		}

		if (tail == nodeToDelete)
		{
			tail = nodeToDelete->prev;
		}

		nodeToDelete->next = nullptr;
		nodeToDelete->prev = nullptr;

		delete nodeToDelete;

		_size--;

	}

	void DeleteNode(t value)
	{
		Node* nodeToDelete = Find(value);
		if (nodeToDelete == nullptr) return;
		DeleteNode(nodeToDelete);
	}


	void DeleteFirstNode()
	{
		if (head == nullptr)
			return;

		Node* temp = head;

		if (head == tail)
		{
			head = tail = nullptr; // One element only in list head & tail points to the same element
		}
		else
		{
			head = head->next;
			head->prev = nullptr;
		}

		delete temp;
		_size--;
	}

	void DeleteLastNode()
	{
		if (head == nullptr)
			return;

		Node* temp = tail;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;
		_size--;


	}

	//size_t Size() const // O() here is O(n) we can improve it by use member class call size change when insert or delete
	//{
	//	size_t size = 0;
	//	Node* temp = head;
	//	while (temp != nullptr)
	//	{
	//		size++;
	//		temp = temp->next;
	//	}
	//	return size;
	//}

	int Size() const { return _size; }   // here O(1) more faster than loop (On))

	bool IsEmpty() const { return _size == 0; } // O(1)

	void Reverse()
	{
		if (head == nullptr || head->next == nullptr)
			return; // we can remove this line 


		// An Algorithm here swap between prev & next pointers using third variable 
		Node* current = head;
		Node* temp = nullptr;

		tail = head;


		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev; // we swap between next and prev so use prev here 
		}

		if (temp != nullptr)
		{
			head = temp->prev; // here temp in prev last Node because above we write a temp = current.prev so here we put the head in temp.prev == temp.next (last Node in a list) because we swap between a prev and Next 
		}

	}

	Node* GetNode(int index) const
	{
		if (index >= _size || index < 0)
			return nullptr;

		Node* current = head;

		for (size_t i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current;
	}

	t GetItem(int index) const
	{
		Node* current = GetNode(index);
		if (current != nullptr)
			return current->value;
		else
			throw std::out_of_range("Index out of range");

	}

	bool UpdateItem(int index, t newValue)
	{
		Node* NodeToUpdate = GetNode(index);
		if (NodeToUpdate != nullptr)
		{
			NodeToUpdate->value = newValue;
			return true;
		}
		return false;
	}

	bool InsertAfter(int index, t value)
	{
		Node* current = GetNode(index);

		if (current != nullptr)
		{
			InsertAfter(current, value);
			return true;
		}
		else
			return false;

	}

	t GetFirst() const
	{
		if (head == nullptr)
			throw std::out_of_range("List is empty");

		return head->value;
	}

	t GetLast() const
	{
		if (tail == nullptr)
			throw std::out_of_range("List is empty");

		return tail->value;
	}


};