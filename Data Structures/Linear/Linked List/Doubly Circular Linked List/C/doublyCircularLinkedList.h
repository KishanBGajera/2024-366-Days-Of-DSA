#ifndef DOUBLYCIRCULARLINKEDLIST_H
#define DOUBLYCIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Node functions' prototypes
Node* getNode(int data);
void freeNodeMemory(Node* node);

Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "Memory allocation failed for Node(%d)\n", data);
    }
    node->prev = NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void freeNodeMemory(Node* node){
    free(node);
}

struct DoublyCircularLinkedList {
    Node* head;
    int totalNodes;
};

typedef struct DoublyCircularLinkedList DoublyCircularLinkedList;

// DoublyCircularLinkedList's functions' prototypes
DoublyCircularLinkedList* getDoublyCircularLinkedList();
bool isDCLLEmpty(DoublyCircularLinkedList* DCLL);

void appendToDCLL(DoublyCircularLinkedList* DCLL, Node* node);
void insertAfterDCLLNode(DoublyCircularLinkedList* DCLL, int reference, Node* node);
void insertAtDCLLBeginning(DoublyCircularLinkedList* DCLL, Node* node);
void insertAtDCLL(DoublyCircularLinkedList* DCLL, int index, Node* node);

int popFromDCLL(DoublyCircularLinkedList* DCLL);
int removeDCLLHead(DoublyCircularLinkedList* DCLL);
void removeDCLLNode(DoublyCircularLinkedList* DCLL, int data);
int removeDCLLNodeAt(DoublyCircularLinkedList* DCLL, int index);

Node* searchDCLLNode(DoublyCircularLinkedList* DCLL, int target);
Node* getDCLLNodeAt(DoublyCircularLinkedList* DCLL, int index);

void printDCLL(DoublyCircularLinkedList* DCLL);
void freeDoublyCircularLinkedList(DoublyCircularLinkedList* DCLL);

// definitions
DoublyCircularLinkedList* getDoublyCircularLinkedList(){
    DoublyCircularLinkedList* DCLL = (DoublyCircularLinkedList*)malloc(sizeof(DoublyCircularLinkedList));
    DCLL->head = NULL;
    DCLL->totalNodes = 0;
    return DCLL;
}

void nodeAddedToDCLL(DoublyCircularLinkedList* DCLL){
    DCLL->totalNodes++;
}

void nodeRemovedFromDCLL(DoublyCircularLinkedList* DCLL){
    DCLL->totalNodes--;
}

bool isDCLLEmpty(DoublyCircularLinkedList* DCLL){
    return DCLL->head == NULL;
}

void connectAfterDCLLNode(Node* n1, Node* n2){
    Node* next = n1->next;
    
    n1->next = n2;
    next->prev = n2;
    n2->next = next;
    n2->prev = n1;
}

void appendToDCLL(DoublyCircularLinkedList* DCLL, Node* node){
    if(isDCLLEmpty(DCLL)){
        DCLL->head = node;
        DCLL->head->next = DCLL->head;
        DCLL->head->prev = DCLL->head;
    }
    else{
        if(DCLL->totalNodes == 1){
            connectAfterDCLLNode(DCLL->head, node);
        }
        else{
            connectAfterDCLLNode(DCLL->head->prev, node);
        }
    }
    nodeAddedToDCLL(DCLL);
}

void insertAfterDCLLNode(DoublyCircularLinkedList* DCLL, int reference, Node* node){
    if(isDCLLEmpty(DCLL)){
        printf("NodeNotFoundError: DCLL is empty, can't find Node(%d)\n", reference);
        return;
    }
    else{
        Node* prevNode = searchDCLLNode(DCLL, reference);
        if(!prevNode){
            printf("NodeNotFoundError: Node(%d) doesn't exist\n", reference);
        }
        else{
            connectAfterDCLLNode(prevNode, node);
        }
    }
}

void insertAtDCLLBeginning(DoublyCircularLinkedList* DCLL, Node* node){
    if(isDCLLEmpty(DCLL)){
        DCLL->head = node;
        node->next = node;
        node->prev = node;
    }
    else{
        connectAfterDCLLNode(DCLL->head->prev, node);
        DCLL->head = node;
    }
}

void insertAtDCLL(DoublyCircularLinkedList* DCLL, int index, Node* node){
    if(index < 0 || index > DCLL->totalNodes){
        printf("InvalidIndexError: Index %d is out of bounds\n", index);
        return;
    }
    
    if(index == 0){
        insertAtDCLLBeginning(DCLL, node);
    }
    else if(index == DCLL->totalNodes){
        appendToDCLL(DCLL, node);
    }
    else{
        Node* currentNode = getDCLLNodeAt(DCLL, index - 1);
        if(currentNode){
            connectAfterDCLLNode(currentNode, node);
            nodeAddedToDCLL(DCLL);
        }
    }
}

int popFromDCLL(DoublyCircularLinkedList* DCLL){
    if(isDCLLEmpty(DCLL)){
        printf("EmptyDCLLError: Can't pop from an empty DCLL\n");
        return -1;
    }
    
    int data;
    if(DCLL->totalNodes == 1){
        data = DCLL->head->data;
        freeNodeMemory(DCLL->head);
        DCLL->head = NULL;
    }
    else{
        Node* lastNode = DCLL->head->prev;
        data = lastNode->data;
        lastNode->prev->next = DCLL->head;
        DCLL->head->prev = lastNode->prev;
        freeNodeMemory(lastNode);
    }
    
    nodeRemovedFromDCLL(DCLL);
    return data;
}

int removeDCLLHead(DoublyCircularLinkedList* DCLL){
    if(isDCLLEmpty(DCLL)){
        printf("EmptyDCLLError: Can't remove head from an empty DCLL\n");
        return -1;
    }
    
    int data = DCLL->head->data;
    if(DCLL->totalNodes == 1){
        freeNodeMemory(DCLL->head);
        DCLL->head = NULL;
    }
    else{
        Node* newHead = DCLL->head->next;
        DCLL->head->prev->next = newHead;
        newHead->prev = DCLL->head->prev;
        freeNodeMemory(DCLL->head);
        DCLL->head = newHead;
    }
    
    nodeRemovedFromDCLL(DCLL);
    return data;
}

void removeDCLLNode(DoublyCircularLinkedList* DCLL, int data){
    if(isDCLLEmpty(DCLL)){
        printf("EmptyDCLLError: Can't remove node from an empty DCLL\n");
        return;
    }
    
    Node* nodeToRemove = searchDCLLNode(DCLL, data);
    if(!nodeToRemove){
        printf("NodeNotFoundError: Node(%d) not found\n", data);
        return;
    }
    
    if(nodeToRemove == DCLL->head){
        removeDCLLHead(DCLL);
    }
    else{
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
        freeNodeMemory(nodeToRemove);
        nodeRemovedFromDCLL(DCLL);
    }
}

int removeDCLLNodeAt(DoublyCircularLinkedList* DCLL, int index){
    if(index < 0 || index >= DCLL->totalNodes){
        printf("InvalidIndexError: Index %d is out of bounds\n", index);
        return -1;
    }
    
    if(index == 0){
        return removeDCLLHead(DCLL);
    }
    
    Node* nodeToRemove = getDCLLNodeAt(DCLL, index);
    if(nodeToRemove){
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
        int data = nodeToRemove->data;
        freeNodeMemory(nodeToRemove);
        nodeRemovedFromDCLL(DCLL);
        return data;
    }
    
    return -1;
}

Node* searchDCLLNode(DoublyCircularLinkedList* DCLL, int target){
    if(isDCLLEmpty(DCLL)){
        return NULL;
    }
    else{
        Node* currentNode = DCLL->head;
        while(currentNode && currentNode->data != target){
            currentNode = currentNode->next;
        }
        if(currentNode->data == target){
            return currentNode;
        }
    }
}

Node* getDCLLNodeAt(DoublyCircularLinkedList* DCLL, int index){
    if(index < 0 || index >= DCLL->totalNodes){
        printf("InvalidIndexError: Index %d is out of bounds\n", index);
        return NULL;
    }

    Node* currentNode = DCLL->head;
    for(int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }

    return currentNode;
}

void printDCLL(DoublyCircularLinkedList* DCLL){
    if(isDCLLEmpty(DCLL)){
        return;
    }

    Node* currentNode = DCLL->head;
    do{
        printf(" <-[%d]-> ", currentNode->data);
        currentNode = currentNode->next;
    }
    while(currentNode != DCLL->head);

    printf("\n");
}

void freeDCLL(DoublyCircularLinkedList* DCLL){
    while(!isDCLLEmpty(DCLL)){
        popFromDCLL(DCLL);
    }
    free(DCLL);
}

#endif