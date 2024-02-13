#include "AVLTree.h"

int main(int argc, char const *argv[])
{
    AVLNode* root = getAVLNode(10);

    root = insertIntoAVL(root, 20);
    root = insertIntoAVL(root, 30);

    root = insertIntoAVL(root, 40);
    root = insertIntoAVL(root, 50);

    root = insertIntoAVL(root, 60);

    printTree(root, 0);

    return 0;
}
