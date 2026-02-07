# Custom Data Structures Library (C++)

A robust, template-based C++ library implementing fundamental data structures from scratch. This project demonstrates advanced OOP concepts, efficient memory management, and clean code architecture.

## 🚀 Overview
This repository contains a collection of four custom-built data structures, designed to be reusable and efficient. The library is implemented using **C++ Templates** to support any data type.

## 🛠 Programming Concepts Applied
* **Generics (Templates):** All classes support any data type.
* **Composition:** Building complex structures (Stack/Queue) using existing ones (Doubly Linked List).
* **Memory Management:** Proper use of dynamic memory with constructors and destructors to prevent memory leaks.
* **Abstraction & Encapsulation:** Hiding implementation details and providing a clean public API.

---

## 📚 Libraries & Features

### 1. Doubly Linked List (`clsDoublyLinkedList`)
A bidirectional linked list that allows traversal in both directions.
* **Key Features:** `InsertAtBeginning`, `InsertAtEnd`, `Reverse`, `Find`, `UpdateItem`.
* **Complexity:** * Access: $O(n)$
    * Insertion/Deletion at ends: $O(1)$ (using `head` and `tail` pointers).



### 2. Dynamic Array (`clsDynamicArray`)
A flexible array that resizes itself as needed.
* **Key Features:** Automatic resizing, `DeleteItemAt`, `InsertAt`, `Reverse`.
* **Complexity:** * Random Access: $O(1)$
    * Insertion/Deletion: $O(n)$

### 3. My Stack (`clsMyStack`)
A Last-In-First-Out (LIFO) structure built using **Composition** with the Doubly Linked List.
* **Key Features:** `push`, `pop`, `top`, `bottom`.
* **Complexity:** All operations are $O(1)$.



### 4. My Queue (`clsMyQueue`)
A First-In-First-Out (FIFO) structure built using the **Adapter Pattern** logic via Composition.
* **Key Features:** `push` (enqueue), `pop` (dequeue), `front`, `back`.
* **Complexity:** All operations are $O(1)$.



---

## 💻 Usage & Testing
To test the library, include the header files in your project and use the provided `main.cpp`.

