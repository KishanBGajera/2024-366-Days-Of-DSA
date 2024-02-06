#include "BST.h"

int height(Node *root)
{
    if(!root)
    {
        return -1;
    }
    else{
        return 1 + max(height(root->left), height(root->right));
    }
}

int main()
{
    Node* root = getNode(10);

    insertToBST(root, 20);
    insertToBST(root, 5);
    insertToBST(root, 25);
    insertToBST(root, 30);

    printf("Height of %d: %d\n", root->data, height(root));

    return 0;
}
