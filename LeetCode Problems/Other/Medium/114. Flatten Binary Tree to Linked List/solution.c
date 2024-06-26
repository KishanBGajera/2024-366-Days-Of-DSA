#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* prev;

void preorder(struct TreeNode* current){
    if(!current){
        return;
    }

    if(prev){
        prev->left = NULL;
        prev->right = current;
    }

    struct TreeNode* right = current->right;
    prev = current;
    preorder(current->left);
    preorder(right);
}

void flatten(struct TreeNode* root) {
    prev = NULL;
    preorder(root);
}