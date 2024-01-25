#include "n-aryTree.h"

int main()
{
    Node* root = getNode(20);

    insertToTree(root, 20, 15);
    insertToTree(root, 20, 10);
    insertToTree(root, 20, 25);

    insertToTree(root, 15, 11);
    insertToTree(root, 15, 12);
    insertToTree(root, 15, 13);

    insertToTree(root, 11, 40);
    insertToTree(root, 11, 45);

    insertToTree(root, 10, 100);
    insertToTree(root, 10, 110);

    insertToTree(root, 25, 250);
    
    // printTree(root, 0);
    printPath(root, 40);
    printTree(root, 0);
    return 0;
}
