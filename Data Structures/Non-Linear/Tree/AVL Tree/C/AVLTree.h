#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) (a > b ? a : b)

struct AVLNode{
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

typedef struct AVLNode AVLNode;

AVLNode* getAVLNode(int value){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int heightOfNode(AVLNode* node){
    if(!node){
        return 0;
    }
    else{
        return 1 + max(heightOfNode(node->left), heightOfNode(node->right));
    }
}

int getBalance(AVLNode* node){
    if(!node){
        return 0;
    }
    else{
        return heightOfNode(node->left) - heightOfNode(node->right);
    }
}

AVLNode* rightRotate(AVLNode* root){
    AVLNode* left = root->left;
    AVLNode* rightOfLeft = left->right;

    left->right = root;
    root->left = rightOfLeft;

    root->height = 1 + max(heightOfNode(root->left), heightOfNode(root->right));
    left->height = 1 + max(heightOfNode(left->left), heightOfNode(left->right));

    return left; // new root
}

AVLNode* leftRotate(AVLNode* root){
    AVLNode* right = root->right;
    AVLNode* leftOfRight = right->left;

    right->left = root;
    root->right = leftOfRight;

    root->height = 1 + max(heightOfNode(root->left), heightOfNode(root->right));
    right->height = 1 + max(heightOfNode(right->left), heightOfNode(right->right));

    return right;
}

AVLNode* insertIntoAVL(AVLNode* root, int data){
    if(!root){
        return getAVLNode(data);
    }

    if(data < root->value){
        root->left = insertIntoAVL(root->left, data);
    }
    else if (data > root->value){
        root->right = insertIntoAVL(root->right, data);
    }
    else{
        return root;
    }

    root->height = 1 + max(heightOfNode(root->left), heightOfNode(root->right));

    int balance = getBalance(root);

    if(balance > 1 && data < root->left->value){
        return rightRotate(root);
    }

    if(balance < -1 && data > root->right->value){
        return leftRotate(root);
    }

    if(balance > 1 && data > root->left->value){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && data < root->right->value){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printTree(AVLNode* root, int level){
    if(root){
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            printf("    ");
        }
        printf("%d\n", root->value);
        printTree(root->left, level + 1);
    }
}

#endif
