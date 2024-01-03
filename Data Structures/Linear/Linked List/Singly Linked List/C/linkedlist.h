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
    printf("Node(%d) created\n", data);
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
    struct Node* head;
    int size;
};

typedef struct LinkedList LinkedList;

LinkedList* getLinkedList(int size){
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->size = size;
    linkedList->head = NULL;
    printf("LinkedList[%d] created\n", linkedList->size);
    return linkedList;
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
    printf("Node(%d) added to LinkedList[%d]\n", node->data, linkedList->size);
}

int popOutOfLinkedList(LinkedList* linkedList){
    Node* currentNode = linkedList->head;
    Node* nextNode = currentNode->next;

    while(nextNode->next){
        currentNode = currentNode->next;
        nextNode = nextNode->next;
    }

    currentNode->next = NULL;
    printf("Node(%d) popped out of LinkedList[%d]\n", nextNode->data, linkedList->size);
    int poppedData = nextNode->data;
    free(nextNode);
    return poppedData;
}

void removeFromLinkedList(LinkedList* linkedList, int data){
    Node* currentNode = linkedList->head;
    Node* nextNode = currentNode->next;

    if (currentNode->data == data) {
        linkedList->head = nextNode;
        printf("Removed Node(%d) from LinkedList[%d]\n", currentNode->data, linkedList->size);
        freeNodeMemory(currentNode);
        return;
    }

    while(nextNode && nextNode->data != data){
        currentNode = nextNode;
        nextNode = nextNode->next;
    }

    if (nextNode) {
        currentNode->next = nextNode->next;
        printf("Removed Node(%d) from LinkedList[%d]\n", nextNode->data, linkedList->size);
        freeNodeMemory(nextNode);
    } else {
        printf("Node with data %d not found in LinkedList[%d]\n", data, linkedList->size);
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