#include "linkedList.h"

Node* findMidNode(LinkedList* ll){
    Node* fast = ll->head;
    Node* slow = ll->head;

    while(fast){
        if(!fast->next){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    LinkedList* ll = getLinkedList(10);
    for (int i = 0; i < 10; i++)
    {
        addToLinkedList(ll, getNode(i));
    }
    
    displayLinkedList(ll);

    printf("Mid: %d", findMidNode(ll)->data);

    return 0;
}