#include "bst.h"

int main() {
    Node* root = insertToBST(root, 10);
    insertToBST(root, 5);
    insertToBST(root, 15);
    insertToBST(root, 3);
    insertToBST(root, 7);
    insertToBST(root, 12);
    insertToBST(root, 18);
    insertToBST(root, 20);

    printf("Tree Structure:\n");
    printTree(root, 0);

    int tree_diameter = diameter(root);
    printf("Diameter of the tree: %d\n", tree_diameter);

    return 0;
}
