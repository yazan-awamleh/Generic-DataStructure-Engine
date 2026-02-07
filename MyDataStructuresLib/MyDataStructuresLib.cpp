#include <iostream>
#include "clsDoublyLinkedList.h"
#include "clsDynamicArray.h"
#include "clsMyStack.h"
#include "clsMyQueue.h"

using namespace std;

int main()
{
    // --- Testing Doubly Linked List ---
    cout << "======================================\n";
    cout << "   TESTING DOUBLY LINKED LIST\n";
    cout << "======================================\n";
    clsDoublyLinkedList<int> list;
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtBeginning(5);
    list.InsertAfter(0, 7); // Inserts 7 after index 0 (5)

    cout << "List Content:  "; list.Print();
    list.Reverse();
    cout << "After Reverse: "; list.Print();
    cout << "List Size:     " << list.Size() << "\n\n";

    // --- Testing Dynamic Array ---
    cout << "======================================\n";
    cout << "   TESTING DYNAMIC ARRAY\n";
    cout << "======================================\n";
    clsDynamicArray<int> arr(3);
    arr.SetItem(0, 10);
    arr.SetItem(1, 20);
    arr.SetItem(2, 30);

    cout << "Array Content: "; arr.Print();
    arr.InsertAtEnd(40);
    arr.DeleteItem(20); // Deletes value 20
    cout << "After Changes: "; arr.Print();
    cout << "Array Size:    " << arr.Size() << "\n\n";

    // --- Testing Stack (LIFO) ---
    cout << "======================================\n";
    cout << "   TESTING STACK (LIFO)\n";
    cout << "======================================\n";
    clsMyStack<int> stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);

    cout << "Stack:  "; stack.Print();
    cout << "Top:    " << stack.top() << "\n";
    stack.pop();
    cout << "After Pop (Top was 300): "; stack.Print();
    cout << "Bottom: " << stack.bottom() << "\n\n";

    // --- Testing Queue (FIFO) ---
    cout << "======================================\n";
    cout << "   TESTING QUEUE (FIFO)\n";
    cout << "======================================\n";
    clsMyQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Queue: "; queue.Print();
    queue.pop(); // Removes 1
    cout << "After Pop (1 is removed): "; queue.Print();
    queue.InsertAtFront(0);
    cout << "After InsertAtFront(0):   "; queue.Print();
    cout << "Front: " << queue.front() << " | Back: " << queue.back() << "\n";
    cout << "======================================\n";

    return 0;
}