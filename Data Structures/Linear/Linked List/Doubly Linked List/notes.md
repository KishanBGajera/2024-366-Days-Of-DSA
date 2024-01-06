# Doubly Linked List Implementation

## Introduction

The Doubly Linked List implementation is a versatile data structure that offers dynamic storage with each node containing data, a reference to the next node, and a reference to the previous node. This concise overview covers real-world analogies, core operations, and key functionalities of the Doubly Linked List.

## Core Operations

1. **Insertion:** The addition of new nodes allows the list to accommodate dynamic growth. Nodes can be inserted at various positions, enhancing flexibility.

2. **Deletion:** Removing nodes from the list is a crucial operation. Deletion can be performed at the beginning, end, or any specific position in the list.

3. **Traversal:** Iterating through nodes is essential for accessing or manipulating elements within the linked structure. Traversal ensures efficient data handling.

4. **Search:** Locating a specific element within the linked structure is a fundamental operation. Efficient search algorithms enhance the usability of the Doubly Linked List.

## Added Functions

#### _isEmpty_
```c
bool isEmpty(DoublyLinkedList*, int){}
```
- A boolean check determines whether the list is empty, guiding decision-making during program execution.

#### _appendToList_
```c
void appendToList(DoublyLinkedList*, int)
```
- Adding a node to the end of the list ensures seamless expansion and maintains the chronological order of elements.

#### _insertAtBeginning_
```c
void insertAtBeginning(DoublyLinkedList*, Node*)
```
- Inserting a node at the beginning of the list is a fast and efficient way to add elements to the linked structure.

#### _insertAt_
```c
void insertAt(int index, DoublyLinkedList *, Node*)
```
- Inserting a node at a specific index allows for targeted placement, enhancing control over the list's arrangement.

#### _popFromList_
```c
int popFromList(DoublyLinkedList*)
```
- Removing the last node from the list is useful for managing the size and memory usage of the linked structure.

#### _removeNode_
```c
void removeNode(DoublyLinkedList *, int)
```
- Removing a node with a specific data value provides flexibility in data management and organization.

#### _searchNode_
```c
int searchNode(DoublyLinkedList *, int)
```
- Searching for a node with a specific data value is crucial for identifying and retrieving relevant information.

#### _getNodeAt_
```c
Node* getNodeAt(DoublyLinkedList *, int)
```
- Retrieving a node at a specific index enables direct access to elements at desired positions.

#### _printList_
```c
void printList(DoublyLinkedList*)
```
- Displaying the contents of the list is a helpful debugging and visualization tool for developers.

#### _deleteList_
```c
void deleteList(DoublyLinkedList*)
```
- Deleting the entire linked list ensures proper memory management and resource cleanup.

