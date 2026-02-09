# Algorithms & Problem Solving – Level 5 (Data Structures & Real-World Apps)

## Course Overview

This level represents the completion of Part One of my programming roadmap. It is a rigorous, project-intensive course where I transformed theoretical data structures into practical, reusable components and real-world applications. The core focus was on implementing custom versions of standard containers and using them to solve complex logic problems.

## Key Technical Projects

### 1. Custom Data Structures Library (The Core)

I built a set of high-performance C++ template libraries to mimic and optimize standard behavior:

- **clsDoublyLinkedList**: A full-featured list with O(1) tail access, including advanced operations like Reverse and UpdateItem.  
- **clsDynamicArray**: A custom implementation of a dynamic array that handles automatic memory reallocation (Resize), deep copying via Copy Constructor, and precise index manipulation.  
- **clsMyStack & clsMyQueue**: Built using the Adapter Pattern (Composition) on top of the Doubly Linked List, ensuring modularity and clean interface design.  

### 2. QueueLine System (Queue Application)

A realistic simulation of a customer service ticketing system:

- **Logic**: Implemented a clsQueueLine using the queue data structure to manage customer tickets.  
- **Features**: Automated ticket issuance, calculation of Waiting Clients, and Expected Serve Time.  
- **Data Flow**: Demonstrated the ability to manipulate data between queue and stack to display ticket lines in different directions (RTL/LTR).  

### 3. Undo/Redo System (Stack Application)

A sophisticated string management system that tracks state changes:

- **Logic**: Utilized two stacks (_UndoList and _RedoList) to manage state history.  
- **Features**: Full support for Undo() and Redo() operations with logic to clear the redo history upon new state changes—mimicking professional software behavior like MS Word or Photoshop.  
- **Properties**: Used __declspec(property) for clean syntax in C++ (Get/Set).  

## Advanced Skills Demonstrated

- Template Programming: Designing generic classes to handle any data type.  
- Memory Management: Professional use of new and delete[], protecting against memory leaks through robust destructors and clear methods.  
- Pattern Implementation: Practical application of Composition over Inheritance and the Adapter Design Pattern.  
- Complexity Optimization: Focusing on constant time O(1) for size retrieval and element access where possible.  
- State Management: Handling complex logic to ensure data consistency during Undo/Redo cycles.  

## Engineering Mindset

- Modularity: Each project is built to be independent and reusable.  
- System Thinking: Moving from writing code to engineering systems that simulate real-world requirements.  
- Reliability: Implementing error handling (e.g., out_of_range exceptions) to ensure software stability.  

## Status

Part One Completed. Ready for Advanced Foundational Learning.
