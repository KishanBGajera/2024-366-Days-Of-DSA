#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
}

void freeNodeMemory(Node* node){
    free(node);
}

struct DoublyLinkedList {
    Node* head;
    int totalNodes;
};

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* getDoublyLinkedList(){
    DoublyLinkedList* doublyLinkedList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    doublyLinkedList->head = NULL;
    doublyLinkedList->totalNodes = 0;
    return doublyLinkedList;
}

/**
 * Methods added:
 * bool isEmpty(...)
 * void appendToList(...)
 * void insertAtBeginning(...)
 * void insertAt(...)
 * int popFromList(...)
 * void removeNode(...)
 * int searchNode(...)
 * Node* getNodeAt(...)
 * void printList(...)
 * void deleteList(...)
*/

void nodeAdded(DoublyLinkedList* doublyLinkedList, Node* node){
    printf("Node(%d) added to DLL\n", node->data);
    doublyLinkedList->totalNodes++;
}

void nodeRemoved(DoublyLinkedList* doublyLinkedList){
    doublyLinkedList->totalNodes--;
}

bool isEmpty(DoublyLinkedList* doublyLinkedList){
    return doublyLinkedList->head == NULL;
}

void appendToList(DoublyLinkedList* doublyLinkedList, Node* node){
    if(isEmpty(doublyLinkedList)){
        doublyLinkedList->head = node;
    }
    else{
        Node* currentNode = doublyLinkedList->head;
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        node->prev = currentNode;
        currentNode->next = node;
    }
    nodeAdded(doublyLinkedList, node);
}

void insertAtBeginning(DoublyLinkedList* doublyLinkedList, Node* node){
    if(isEmpty(doublyLinkedList)){
        doublyLinkedList->head = node;
    }
    else{
        node->next = doublyLinkedList->head;
        doublyLinkedList->head->prev = node;
        doublyLinkedList->head = node;
    }
    nodeAdded(doublyLinkedList, node);
}

void insertAt(int index, DoublyLinkedList *doublyLinkedList, Node* node){
    if(doublyLinkedList->totalNodes - 1 < index){
        appendToList(doublyLinkedList, node);
        return;
    }
    else{
        if(index == 0){
            insertAtBeginning(doublyLinkedList, node);
            return;
        }
        int counter = 0;
        Node* currentNode = doublyLinkedList->head;
        while(counter != index - 1){
            currentNode = currentNode->next;
            counter++;
        }
        node->prev = currentNode;
        node->next = currentNode->next;
        currentNode->next = node;
    }
    nodeAdded(doublyLinkedList, node);
}

int popFromList(DoublyLinkedList* doublyLinkedList){
    if(isEmpty(doublyLinkedList)){
        printf("ListUnderflowError: DoublyLinkedList already empty, can't `popFromList()`");
        return -1;
    }

    int data;
    if(!doublyLinkedList->head->next){
        data = doublyLinkedList->head->data;
        freeNodeMemory(doublyLinkedList->head->next);
        doublyLinkedList->head = NULL;
    }
    else{
        Node* currentNode = doublyLinkedList->head;
        while(currentNode->next->next){
            currentNode = currentNode->next;
        }
        data = currentNode->next->data;
        freeNodeMemory(currentNode->next);
        currentNode->next = NULL;
    }
    printf("Node(%d) popped out of DLL\n", data);
    nodeRemoved(doublyLinkedList);
    return data;
}

void removeNode(DoublyLinkedList *doublyLinkedList, int data){
    if(isEmpty(doublyLinkedList)){
        return;
    }
    Node* currentNode = doublyLinkedList->head;
    while(currentNode->next && currentNode->next->data != data){
        currentNode = currentNode->next;
    }
    if(currentNode->next->data == data){
        currentNode->next->prev = currentNode;
        Node* target = currentNode->next;
        currentNode->next = currentNode->next->next;
        freeNodeMemory(target);
    }
}

int searchNode(DoublyLinkedList *doublyLinkedList, int target){
    int counter = 0;
    Node* currentNode = doublyLinkedList->head;

    while(currentNode != NULL && currentNode->data != target){
        currentNode = currentNode->next;
        counter++;
    }

    if(currentNode->data == target){
        return counter;
    }

    return -1;
}

Node* getNodeAt(DoublyLinkedList *doublyLinkedList, int index){
    if(index > doublyLinkedList->totalNodes){
        return (Node*)(-1); // returning sentinel value (-1) in "Node*" type
    }
    
    Node* currentNode = doublyLinkedList->head;
    int counter = 0;
    while(currentNode != NULL && counter != index){
        currentNode = currentNode->next;
        counter++;
    }
    if(counter == index){
        return currentNode;
    }

    return (Node*)-1;
}

void printList(DoublyLinkedList* doublyLinkedList){
    if(isEmpty(doublyLinkedList)){
        return;
    }

    Node* currentNode = doublyLinkedList->head;
    while(currentNode){
        printf(" <-[%d]-> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void deleteList(DoublyLinkedList* doublyLinkedList){
    Node* currentNode = doublyLinkedList->head;
    while(currentNode->next){
        freeNodeMemory(currentNode);
        currentNode = currentNode->next;
    }
    freeNodeMemory(currentNode);
    free(doublyLinkedList);
    doublyLinkedList->head = NULL;
}

/**
 * To-be-added
 * reverseList: Reverse the order of nodes in the linked list.
 * sortList: Sort the linked list using a sorting algorithm.
 * removeNodeAtPosition: Remove a node at a specific position in the linked list.
 * mergeLists: Merge two doubly linked lists into one.
*/

#endif