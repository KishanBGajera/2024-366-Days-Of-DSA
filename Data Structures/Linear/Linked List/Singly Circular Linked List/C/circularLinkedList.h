#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Node functions' prototypes
Node* getNode(int data);
void freeNodeMemory(Node* node);

// definitions
Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "Memory allocation failed for Node(%d)\n", data);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void freeNodeMemory(Node* node){
    free(node);
}

struct CircularLinkedList {
    Node* head;
    int totalNodes;
};

typedef struct CircularLinkedList CircularLinkedList;

// CLL functions' prototypes
CircularLinkedList* getCircularLinkedList();
bool isCLLEmpty(CircularLinkedList* CLL);

void appendToCLL(CircularLinkedList* CLL, Node* node);
void insertAfterCLLNode(CircularLinkedList* CLL, int reference, Node* node);
void insertAtCLLBeginning(CircularLinkedList* CLL, Node* node);
void insertAtCLL(CircularLinkedList* CLL, int index, Node* node);

int popFromCLL(CircularLinkedList* CLL);
int removeCLLHead(CircularLinkedList* CLL);
void removeCLLNode(CircularLinkedList* CLL, int data);
int removeCLLNodeAt(CircularLinkedList* CLL, int index);

int searchCLLNode(CircularLinkedList* CLL, int target);
Node* getCLLNodeAt(CircularLinkedList* CLL, int index);

// to-be-added
void reverseCLL(CircularLinkedList* CLL);
CircularLinkedList* mergeCLLs(CircularLinkedList* CLL1, CircularLinkedList* CLL2);
void sortCLL(CircularLinkedList*);

void printCLL(CircularLinkedList* CLL);
void freeCircularLinkedList(CircularLinkedList* CLL);

// definitions
CircularLinkedList* getCircularLinkedList(){
    CircularLinkedList* circularLinkedList = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if(!circularLinkedList){
        fprintf(stderr, "Memory allocation failed for CircularLinkedList\n");
    }
    circularLinkedList->head = NULL;
    circularLinkedList->totalNodes = 0;
    return circularLinkedList;
}

bool isCLLEmpty(CircularLinkedList* CLL){
    return CLL->head == NULL;
}

void nodeAdded(CircularLinkedList* CLL, Node* node){
    printf("Node(%d) added to CLL\n", node->data);
    CLL->totalNodes++;
}

void nodeRemoved(CircularLinkedList* CLL){
    printf("Node removed from CLL\n");
    CLL->totalNodes--;
}

void appendToCLL(CircularLinkedList* CLL, Node* node){
    if(isCLLEmpty(CLL)){
        CLL->head = node;
        CLL->head->next = CLL->head;
    }
    else{
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head){
            currentNode = currentNode->next;
        }
        currentNode->next = node;
        node->next = CLL->head;
    }
    nodeAdded(CLL, node);
}

void insertAfterCLLNode(CircularLinkedList* CLL, int reference, Node* node){
    if(isCLLEmpty(CLL)){
        printf("ListUnderFlow: List is empty.\n");
    }
    else{
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head && currentNode->data != reference){
            currentNode = currentNode->next;
        }
        if(currentNode->data == reference){
            node->next = currentNode->next;
            currentNode->next = node;
            nodeAdded(CLL, node);
        }
    }
}

void insertAtCLLBeginning(CircularLinkedList* CLL, Node* node){
    if(isCLLEmpty(CLL)){
        CLL->head = node;
    }
    else{
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head){
            currentNode = currentNode->next;
        }
        currentNode->next = node;
        node->next = CLL->head;
        CLL->head = node;
    }
    nodeAdded(CLL, node);
}

void insertAtCLL(CircularLinkedList* CLL, int index, Node* node){
    if(CLL->totalNodes - 1 < index){
        appendToCLL(CLL, node);
    }
    else{
        if(index == 0){
            insertAtCLLBeginning(CLL, node);
            return;
        }
        
        int count = 0;
        Node* currentNode = CLL->head;
        while(count != index - 1){
            currentNode = currentNode->next;
        }
        node->next = currentNode->next;
        currentNode->next = node;
    }
}

int popFromCLL(CircularLinkedList* CLL){
    if(isCLLEmpty(CLL)){
        printf("CLLUnderFlow: Can't `popFromCLL()`\n");
        return -1;
    }
    else{
        int data;
        if(CLL->totalNodes == 1){
            data = CLL->head->data;
            freeNodeMemory(CLL->head);
            CLL->head = NULL;
        }
        else{
            Node* currentNode = CLL->head;
            while(currentNode->next->next != CLL->head){
                currentNode = currentNode->next;
            }
            data = currentNode->next->data;
            freeNodeMemory(currentNode->next);
            currentNode->next = CLL->head;
        }
        nodeRemoved(CLL);
        return data;
    }
}

int removeCLLHead(CircularLinkedList* CLL){
    if(isCLLEmpty(CLL)){
        printf("ListUnderFlow: CLL is empty\n");
        return -1;
    }
    else{
        int data = CLL->head->data;
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head){
            currentNode = currentNode->next;
        }
        Node* head = CLL->head;
        currentNode->next = head->next;
        CLL->head = head->next;
        freeNodeMemory(head);
        return data;
    }
}

void removeCLLNode(CircularLinkedList* CLL, int data){
    if(isCLLEmpty(CLL)){
        printf("ListUnderFlow: CLL is empty\n");
        return;
    }
    else{
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head && currentNode->next->data != data){
            currentNode = currentNode->next;
        }
        if(currentNode->next->data == data){
            Node* node = currentNode->next;
            currentNode->next = node->next;
            freeNodeMemory(node);
            nodeRemoved(CLL);
        }
    }
}

int removeCLLNodeAt(CircularLinkedList* CLL, int index){
    if(isCLLEmpty(CLL)){
        printf("ListUnderFlow: List is empty\n");
        return -1;
    }
    else{
        int data;
        if(index == 0){
            data = removeCLLHead(CLL);
            return data;
        }
        else{
            int count = 0;
            Node* currentNode = CLL->head;
            while(count - 1 != index){
                currentNode = currentNode->next;
            }
            Node* node = currentNode->next;
            data = node->data;
            currentNode->next = node->next;
            freeNodeMemory(node);
            return data;
        }
    }
}

int searchCLLNode(CircularLinkedList* CLL, int target){
    if(isCLLEmpty(CLL)){
        return -1;
    }
    else{
        int index = 0;
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head && currentNode->data != target){
            index++;
            currentNode = currentNode->next;
        }
        if(currentNode->data == target){
            return index;
        }
        return -1;
    }
}

Node* getCLLNodeAt(CircularLinkedList* CLL, int index){
    if(isCLLEmpty(CLL) || index > CLL->totalNodes - 1){
        return NULL;
    }
    else{
        int counter = 0;
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head && counter != index){
            currentNode = currentNode->next;
        }
        if (counter == index){
            return currentNode;
        }
        return NULL;
    }
}

void printCLL(CircularLinkedList* CLL){
    if(isCLLEmpty(CLL)){
        return;
    }
    else{
        Node* currentNode = CLL->head;
        while(currentNode->next != CLL->head){
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("%d -> head", currentNode->data);
        printf("\n");
    }
}

void freeCircularLinkedList(CircularLinkedList* CLL){
    while (!isCLLEmpty(CLL)) {
        popFromCLL(CLL);
    }
    free(CLL);
}

#endif