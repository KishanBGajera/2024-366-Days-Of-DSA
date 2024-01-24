#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// prototypes
TreeNode* getTreeNode(int data);
TreeNode* searchNode(TreeNode* root, int target);
void insertToBinTree(TreeNode* root, int parent, int child, int whichChild);
void printTree(TreeNode* treeNode, int level, int target);
void freeTreeNodeMemory(TreeNode* treeNode);

// definitions
TreeNode* getTreeNode(int data){
    TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode* searchNode(TreeNode* root, int target){
    if(root){
        if(root->data == target){
            return root;
        }

        TreeNode* leftResult = searchNode(root->left, target);
        if(leftResult){
            return leftResult;
        }

        TreeNode* rightResult = searchNode(root->right, target);
        if(rightResult){
            return rightResult;
        }
    }
    return NULL;
}

void insertToBinTree(TreeNode* root, int parent, int child, int whichChild){
    TreeNode* parentNode = searchNode(root, parent);
    if(!parentNode){
        printf("NodeNotInTreeError: Node(%d) couldn't be found the given Tree(root: %d)\n", parent, root->data);
        return;
    }
    switch (whichChild)
    {
        case -1:
            parentNode->left = getTreeNode(child);
            break;
        case 1:
            parentNode->right = getTreeNode(child);
            break;
        default:
            break;
    }
}

void printTree(TreeNode* treeNode, int level, int target){
    if(treeNode){
        printTree(treeNode->right, level+1, target);
        for (int i = 0; i < level; i++)
            printf("    ");
        
        if (treeNode->data == target)
            printf("*");
        
        printf("%d\n", treeNode->data);

        printTree(treeNode->left, level+1, target);
    }
}

void freeTreeNodeMemory(TreeNode* treeNode){
    free(treeNode);
}

#endif