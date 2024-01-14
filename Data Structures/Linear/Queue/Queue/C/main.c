#include "queue.h"

int main()
{
    Queue* queue = getQueue(10);
    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 8);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    enqueue(queue, 10);
    printQueue(queue);
    return 0;
}

