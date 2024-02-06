#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) (a > b ? a : b)

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertToBST(Node* root, int data){
    if(!root){
        return getNode(data);
    }
    else if(root->data > data){
        root->left = insertToBST(root->left, data);
    }
    else if(root->data < data){
        root->right = insertToBST(root->right, data);
    }
    return root;
}

int height(Node *root)
{
    if(!root)
    {
        return 0;
    }
    else{
        return 1 + max(height(root->left), height(root->right));
    }
}

void preorderTraversal(Node* root){
    if(root){
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node* root){
    if(root){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root){
    if(root){
        postorderTraversal(root->right);
        postorderTraversal(root->left);
        printf("%d ", root->data);
    }
}

int level(Node* root, int data){
    int nodeAtLevel = 0;
    Node* currentNode = root;
    while(currentNode && currentNode->data != data){
        nodeAtLevel += 1;
        if(currentNode->data > data){
            currentNode = currentNode->left;
        }
        else{
            currentNode = currentNode->right;
        }
    }
    if(currentNode->data == data){
        return nodeAtLevel;
    }
    else{
        return -1;
    }
}

void printGivenLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 0){
        printf("%d ", root->data);
    }
    else if(level > 0){
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(Node* root){
    int heightOfTree = height(root);
    Node* currentNode = root;
    Node* parentNode = NULL;
    int currentLevel = 0;

    while(heightOfTree != currentLevel){
        printf("Level %d: ", currentLevel);
        printGivenLevel(root, currentLevel);
        printf("\n");
        currentLevel++;
    }
}

void printTree(Node* root, int level){
    if(root){
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            printf("\t");
        }
        printf("%4d\n", root->data);
        printTree(root->left, level + 1);
    }
}

#endif