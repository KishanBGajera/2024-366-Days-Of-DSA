#ifndef N_ARYTREE_H
#define N_ARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node** children;
    int totalChildren;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->totalChildren = 0;
    node->children = (Node**)malloc(sizeof(Node*)*node->totalChildren);
    return node;
}

Node* searchNode(Node* root, int data){
    if(root->data == data){
        return root;
    }
    else{
        for (int i = 0; i < root->totalChildren; i++)
        {
            Node* result = searchNode(root->children[i], data);
            if(result){
                return result;
            }
        }
    }
    return NULL;
}

void insertToTree(Node* root, int parent, int child){
    if(!root){
        return;
    }
    else{
        Node* parentNode = searchNode(root, parent);
        if(!parentNode){
            printf("ParentNotFoundError: couldn't find Node(%d)\n", parent);
            return;
        }
        parentNode->children = realloc(parentNode->children, sizeof(Node*)*(++parentNode->totalChildren));
        parentNode->children[parentNode->totalChildren-1] = getNode(child);
    }
}

void printTree(Node* root, int level){
    if(!root){
        return;
    }
    else{
        for (int i = 0; i < level; i++)
        {
            printf("\t");
        }
        printf("%4d\n", root->data);
        for (int i = 0; i < root->totalChildren; i++)
        {            
            printTree(root->children[i], level + 1);
        }
    }
}

bool findPath(Node* root, int target, int path[], int* pathLength) {
    if (root == NULL) {
        return false;
    }

    path = realloc(path, sizeof(int)*(++(*pathLength)));
    path[*pathLength - 1] = root->data;

    if (root->data == target) {
        return true;
    }

    for (int i = 0; i < root->totalChildren; i++) {
        if (findPath(root->children[i], target, path, pathLength)) {
            return true;
        }
    }

    (*pathLength)--;
    path = realloc(path, sizeof(int)*(*pathLength));
    return false;
}

void printPath(Node* root, int target) {
    int pathLength = 0;
    int *path = (int*)malloc(sizeof(int)*pathLength);

    if (findPath(root, target, path, &pathLength)) {
        printf("Path to Node(%d): ", target);
        for (int i = 0; i < pathLength; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Node(%d) not found in the tree.\n", target);
    }
}

#endif