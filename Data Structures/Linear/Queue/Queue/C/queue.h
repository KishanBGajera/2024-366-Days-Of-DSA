#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int *data;
    int size;
    int front;
    int rear;
};

typedef struct Queue Queue;

Queue* getQueue(int size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->data = (int*)malloc(sizeof(int)*queue->size);
    queue->front = -1;
    queue->rear = -1;
    printf("Queue[%d] created\n", queue->size);
    return queue;
}

bool isEmpty(Queue* queue){
    return queue->front == queue->rear;
}

bool isFull(Queue* queue){
    return queue->rear == queue->size - 1;
}

void enqueue(struct Queue* queue, int data){
    if(queue->rear - queue->front == queue->size - 1){
        if(queue->front != 0){
            queue->size += queue->front;
            queue->data[++(queue->rear)] = data;
        }
        else{
            printf("QueueOverFlow: Queue is full, can't `enqueue(%d)`\n", data);
            return;
        }
    }
    else{
        if(queue->front == -1){
            queue->data[++(queue->rear)] = data;
            queue->front++;
        }
        else{
            queue->data[++(queue->rear)] = data;
        }
    }
    printf("%d enqueued\n", data);
}

int dequeue(struct Queue* queue){
    if(queue->front == -1 || queue->front == queue->rear){
        if(queue->front == 0 && queue->rear == 0){
            int dequeued = queue->data[queue->front];
            printf("%d dequeued\n", queue->data[queue->front]);
            queue->front = -1;
            queue->rear = -1;
            return dequeued;
        }
        else{
            printf("QueueUnderFlow: Queue is empty, can't `dequeue()`\n");
        }
        return -1;
    }
    else{
        printf("%d dequeued\n", queue->data[queue->front]);
        return queue->data[queue->front++];
    }
}

int queueFront(struct Queue* queue){
    if(queue->front == -1){
        return -1;
    }
    return queue->data[queue->front];
}

int queueRear(struct Queue* queue){
    if(queue->rear == -1){
        return -1;
    }
    return queue->data[queue->rear];
}

void printQueue(struct Queue* queue){
    printf("\nfront-> ");
    for (int i = queue->front; i < queue->rear + 1; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("<-rear\n");
}

void freeQueueMemory(struct Queue* queue){
    free(queue->data);
    free(queue);
}

#endif