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
    node->children = (Node**)malloc(sizeof(Node*)*5);
    return node;
}

Node* searchNode(Node* root, int data){
    if(root->data == data){
        return root;
    }
    else if (root->children > 0){
        for (int i = 0; i < root->totalChildren; i++)
        {
            return searchNode(root->children[i], data);
        }
    }
    else{
        return NULL;
    }
}

void insertToTree(Node* root, int parent, int child){
    if(!root){
        return;
    }
    else{
        Node* parentNode = searchNode(root, parent);
        parentNode->children[parentNode->totalChildren++] = getNode(child);
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

// void printPath(Node* root, int target){
//     // char* path[0];
//     if(root->data == target){
//         return root;
//     }
//     else if (root->children > 0){
//         for (int i = 0; i < root->totalChildren; i++)
//         {
//             return searchNode(root->children[i], target);
//         }
//     }
//     else{
//         return NULL;
//     }
// }

#endif