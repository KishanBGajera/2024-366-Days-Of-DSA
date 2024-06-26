#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *prev;
    void preorder(TreeNode* current){
        if(!current) return;
        
        if(prev){
            prev->right = current;
            prev->left = NULL;
        }

        TreeNode* right = current->right;
        prev = current;
        preorder(current->left);
        preorder(right);
    }

    void flatten(TreeNode* root) {
        prev = NULL;
        preorder(root);
    }
};