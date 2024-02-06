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

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteFromBST(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteFromBST(root->left, data);

    else if (data > root->data)
        root->right = deleteFromBST(root->right, data);

    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteFromBST(root->right, temp->data);
    }
    return root;
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