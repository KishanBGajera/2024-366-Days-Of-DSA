#include "./doublyLinkedList.h"

int main(){
    DoublyLinkedList* DLL = getDoublyLinkedList();
    
    appendToList(DLL, getNode(10));
    appendToList(DLL, getNode(20));
    appendToList(DLL, getNode(30));
    
    insertAtBeginning(DLL, getNode(-10));
    insertAtBeginning(DLL, getNode(-20));
    
    insertAt(5, DLL, getNode(40));
    insertAt(4, DLL, getNode(3));
    insertAt(0, DLL, getNode(0));
    
    printList(DLL);
    
    int idx = searchNode(DLL, 30);
    
    printf("%d\n", idx);
    
    int target_idx = 3;
    Node* node = getNodeAt(DLL, target_idx);
    printf("DLL[%d] = %d\n", target_idx, node->data);

    removeNode(DLL, 20);
    printList(DLL);
    return 0;
}
