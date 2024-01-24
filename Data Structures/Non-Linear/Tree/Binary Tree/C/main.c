#include "binaryTree.h"

int main()
{
    TreeNode* root = getTreeNode(10);

    insertToBinTree(root, 10, 5, -1);
    insertToBinTree(root, 10, 15, 1);
    insertToBinTree(root, 5, 0, -1);
    insertToBinTree(root, 5, 7, 1);

    printTree(root, 0, 1);

    return 0;
}
