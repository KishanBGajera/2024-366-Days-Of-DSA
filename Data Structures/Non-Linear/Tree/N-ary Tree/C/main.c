#include "n-aryTree.h"

int main()
{
    Node* root = getNode(20);

    insertToTree(root, 20, 15);
    insertToTree(root, 20, 10);

    insertToTree(root, 15, 11);
    insertToTree(root, 15, 12);
    insertToTree(root, 15, 13);
    insertToTree(root, 15, 14);

    printTree(root, 0);
    return 0;
}
