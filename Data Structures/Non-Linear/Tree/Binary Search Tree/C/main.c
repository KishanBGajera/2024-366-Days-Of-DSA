#include "BST.h"
#include <time.h>

int main()
{
    Node* root = getNode(50);
    
    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        insertToBST(root, rand()%100);
    }
    

    printTree(root, 0);
    inorderTraversal(root);
    return 0;
}