#include "BST.h"

int main()
{
    Node* root = getNode(10);

    insertToBST(root, 20);
    insertToBST(root, 0);

    insertToBST(root, 5);
    insertToBST(root, -5);
    insertToBST(root, 15);

    printTree(root, 0);

    deleteFromBST(root, 0);
    printf("After Deletion:\n");
    printTree(root, 0);

    return 0;
}