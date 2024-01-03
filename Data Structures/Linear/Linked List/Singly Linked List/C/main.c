#include "LinkedList.h"

int main()
{
    LinkedList* linkedList = getLinkedList(10);
    addToLinkedList(linkedList, getNode(1));
    addToLinkedList(linkedList, getNode(2));
    addToLinkedList(linkedList, getNode(3));
    displayLinkedList(linkedList);
    popOutOfLinkedList(linkedList);
    displayLinkedList(linkedList);
    removeFromLinkedList(linkedList, 2);
    displayLinkedList(linkedList);
    return 0;
}