#include "linkedList.h"
#include <stdbool.h>

bool cycleExists(LinkedList* ll){
    Node *fast, *slow;
    fast = slow = ll->head;
    slow = slow->next;
    fast = fast->next->next;

    while(fast != slow){
        fast = fast->next->next;
        slow = slow->next;

        if(!fast->next){
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    LinkedList* ll = getLinkedList();
    Node* node1 = getNode(10);
    Node* node2 = getNode(20);
    Node* node3 = getNode(30);
    Node* node4 = getNode(40);
    Node* node5 = getNode(50);
    Node* node6 = getNode(60);

    addToLinkedList(ll, node1);
    addToLinkedList(ll, node2);
    addToLinkedList(ll, node3);
    addToLinkedList(ll, node4);
    addToLinkedList(ll, node5);

    printf("Before adding a Cycle: ");
    if(cycleExists(ll)){
        printf("Cycle exists\n");
    }
    else{
        printf("Cycle doesn't exist\n");
        displayLinkedList(ll);
    }

    cycleIt(node5, node3);

    printf("After adding a Cycle: ");
    if(cycleExists(ll)){
        printf("Cycle exists\n");
    }
    else{
        printf("Cycle doesn't exist\n");
    }

    return 0;
}
