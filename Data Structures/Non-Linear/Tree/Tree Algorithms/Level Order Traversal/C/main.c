#include "BST.h"

int main()
{
    Node* root = getNode(10);
    
    insertToBST(root, 15);
    insertToBST(root, 5);

    insertToBST(root, 0);
    insertToBST(root, 20);

    insertToBST(root, 12);
    insertToBST(root, 7);
    
    printTree(root, 0);

    levelOrderTraversal(root);

    return 0;
}