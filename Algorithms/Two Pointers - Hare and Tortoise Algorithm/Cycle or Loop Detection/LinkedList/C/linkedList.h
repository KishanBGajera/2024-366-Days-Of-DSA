#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    // printf("Node(%d) created\n", data);
    return node;
}

void setValue(Node* node, int data){
    printf("Node(%d) updated/set to Node(%d)\n", node->data, data);
    node->data = data;
}

void freeNodeMemory(Node* node){
    printf("Node(%d) freed\n", node->data);
    free(node);
}

struct LinkedList{
    Node* head;
    int totalNodes;
};

typedef struct LinkedList LinkedList;

// LinkedList functions' prototypes
LinkedList* getLinkedList();

void addToLinkedList(LinkedList*, Node*);
void insertAt(LinkedList*, int index, Node*);
void insertAtBeginning(LinkedList*, Node*);

int popOutOfLinkedList(LinkedList* linkedList);
void removeFromLinkedList(LinkedList* linkedList, int data);

Node* searchNode(LinkedList*, int target);
Node* getNodeAt(LinkedList*, int index);

void reverseList(LinkedList*);
void sortList(LinkedList*);

LinkedList* mergedSLLs(LinkedList*, LinkedList*);

void displayLinkedList(LinkedList* linkedList);

LinkedList* getLinkedList(){
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->totalNodes = 0;
    linkedList->head = NULL;
    return linkedList;
}

void addedToSLL(LinkedList* linkedList){
    linkedList->totalNodes++;
}

void removedFromSLL(LinkedList* linkedList){
    linkedList->totalNodes--;
}

void addToLinkedList(LinkedList* linkedList, Node* node){
    if(!linkedList->head){
        linkedList->head = node;
    }
    else{
        Node* currentNode = linkedList->head;
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }
    addedToSLL(linkedList);
}

void insertAfter(LinkedList* ll, Node* reference, Node* node){
    node->next = reference->next;
    reference->next = node; 
}

void cycleIt(Node* lastNode, Node* cycleStart){
    lastNode->next = cycleStart;
}

void insertAt(LinkedList* linkedList, int index, Node* node){
    if(linkedList->totalNodes - 1 < index){
        addToLinkedList(linkedList, node);
        return;
    }
    else{
        int count = 0;
        Node* currentNode = linkedList->head;
        while(count != index){
            count++;
            currentNode = currentNode->next;
        }
        node->next = currentNode->next;
        currentNode->next = node;
        addedToSLL(linkedList);
    }
}

void insertAtBeginning(LinkedList* linkedList, Node* node){
    if(!linkedList->head){
        linkedList->head = node;
        addedToSLL(linkedList);
        return;
    }
    else{
        node->next = linkedList->head;
        linkedList->head = node;
        addedToSLL(linkedList);
    }
}

int popOutOfLinkedList(LinkedList* linkedList){
    Node* currentNode = linkedList->head;
    Node* nextNode = currentNode->next;

    while(nextNode->next){
        currentNode = currentNode->next;
        nextNode = nextNode->next;
    }

    currentNode->next = NULL;
    int poppedData = nextNode->data;
    removedFromSLL(linkedList);
    free(nextNode);
    return poppedData;
}

void removeFromLinkedList(LinkedList* linkedList, int data){
    Node* currentNode = linkedList->head;
    Node* nextNode = currentNode->next;

    if (currentNode->data == data) {
        linkedList->head = nextNode;
        removedFromSLL(linkedList);
        freeNodeMemory(currentNode);
        return;
    }

    while(nextNode && nextNode->data != data){
        currentNode = nextNode;
        nextNode = nextNode->next;
    }

    if (nextNode) {
        currentNode->next = nextNode->next;
        printf("Removed Node(%d) from LinkedList\n", nextNode->data);
        removedFromSLL(linkedList);
        freeNodeMemory(nextNode);
    } else {
        printf("Node with data %d not found in LinkedList\n", data);
    }
}

Node* searchNode(LinkedList* linkedList, int target){
    if(!linkedList->head){
        return (Node*)0;
    }
    else{
        Node* currentNode = linkedList->head;
        while(currentNode && currentNode->data != target){
            currentNode = currentNode->next;
        }
        
        if(currentNode->data == target){
            return currentNode;
        }
        else{
            return (Node*)0;
        }
    }
}

Node* getNodeAt(LinkedList* linkedLinked, int index){
    if(!linkedLinked->head){
        return NULL;
    }
    else{
        int count = 0;
        Node* currentNode = linkedLinked->head;
        while(count != index){
            count++;
            currentNode = currentNode->next;
        }
        return currentNode;
    }
}

void displayLinkedList(LinkedList* linkedList){
    Node* currentNode = linkedList->head;
    printf("head -> ");
    while (currentNode)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

#endif