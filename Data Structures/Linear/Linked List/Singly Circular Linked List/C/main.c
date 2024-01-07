#include "CircularLinkedList.h"

int main() {
    CircularLinkedList* cll = getCircularLinkedList();

    appendToCLL(cll, getNode(1));
    appendToCLL(cll, getNode(2));
    appendToCLL(cll, getNode(3));

    printf("Original Circular Linked List:\n");
    printCLL(cll);

    insertAfterCLLNode(cll, 2, getNode(4));

    printf("\nCircular Linked List after Insertion:\n");
    printCLL(cll);

    removeCLLNode(cll, 2);

    printf("\nCircular Linked List after Removal:\n");
    printCLL(cll);

    freeCircularLinkedList(cll);

    return 0;
}
