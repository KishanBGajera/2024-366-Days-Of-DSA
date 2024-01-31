#include "DoublyCircularLinkedList.h"

int main() {
    DoublyCircularLinkedList* DCLL = getDoublyCircularLinkedList();

    for (int i = 1; i <= 5; ++i) {
        Node* newNode = getNode(i * 10);
        appendToDCLL(DCLL, newNode);
    }

    printf("Initial Doubly Circular Linked List:\n");
    printDCLL(DCLL);

    insertAfterDCLLNode(DCLL, 30, getNode(555));

    insertAtDCLLBeginning(DCLL, getNode(999));

    insertAtDCLL(DCLL, 2, getNode(777));

    printf("\nDoubly Circular Linked List after Insertions:\n");
    printDCLL(DCLL);

    removeDCLLNode(DCLL, 40);
    removeDCLLNodeAt(DCLL, 2);

    printf("\nDoubly Circular Linked List after Removals:\n");
    printDCLL(DCLL);

    freeDCLL(DCLL);

    return 0;
}
