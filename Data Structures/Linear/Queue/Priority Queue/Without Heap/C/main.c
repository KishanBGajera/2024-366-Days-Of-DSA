#include "priorityQueue.h"

int main()
{
    PriorityQueue* prq = getPriorityQueue(10);

    for (int i = 0; i < 10; i++)
    {
        if(i%2 == 0){
            insertToPRQ(prq, createItem(i*10, i+2));
        }
        else{
            insertToPRQ(prq, createItem(i*10, i-2));
        }
    }

    printPRQ(prq);
    
    for (int i = 0; i < 10; i++)
    {
        printf("Highest Priority Index: %d\n", peekPRQ(prq));
        dequeueFromPRQ(prq);
    }
    

    return 0;
}

