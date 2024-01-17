#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Dequeue {
    int size;
    int* data;
    int front;
    int rear;
};

typedef struct Dequeue Dequeue;

// protypes

Dequeue* getDequeue(int size);
bool isDQEmpty(Dequeue* dq);
bool isDQFull(Dequeue* dq);

void DQ_EnqueueFront(Dequeue* dq, int element);
void DQ_EnqueueRear(Dequeue* dq, int element);

int DQ_dequeueFront(Dequeue* dq);
int DQ_dequeueRear(Dequeue* dq);

void printDQ(Dequeue* dq);
void freeDQ(Dequeue* dq);

Dequeue* getDequeue(int size) {
    Dequeue* dequeue = (Dequeue*)malloc(sizeof(Dequeue));
    dequeue->size = size;
    dequeue->data = (int*)malloc(sizeof(int) * dequeue->size);
    dequeue->front = -1;
    dequeue->rear = -1;
    return dequeue;
}

bool isDQEmpty(Dequeue* dq) {
    return dq->front == -1;
}

bool isDQFull(Dequeue* dq) {
    return (dq->front == 0 && dq->rear == dq->size - 1) || (dq->front == dq->rear + 1);
}

void DQ_EnqueueFront(Dequeue* dq, int element) {
    if (isDQFull(dq)) {
        printf("Overflow: Dequeue is full.\n");
        return;
    }

    if (isDQEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->size - 1;
    } else {
        dq->front--;
    }

    dq->data[dq->front] = element;
    printf("Enqueued %d to the front.\n", element);
}

void DQ_EnqueueRear(Dequeue* dq, int element) {
    if (isDQFull(dq)) {
        printf("Overflow: Dequeue is full.\n");
        return;
    }

    if (isDQEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == dq->size - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->data[dq->rear] = element;
    printf("Enqueued %d to the rear.\n", element);
}

int DQ_dequeueFront(Dequeue* dq) {
    if (isDQEmpty(dq)) {
        printf("Underflow: Dequeue is empty.\n");
        return -1;
    }

    int element = dq->data[dq->front];

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == dq->size - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    printf("Dequeued %d from the front.\n", element);
    return element;
}

int DQ_dequeueRear(Dequeue* dq) {
    if (isDQEmpty(dq)) {
        printf("Underflow: Dequeue is empty.\n");
        return -1;
    }

    int element = dq->data[dq->rear];

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->size - 1;
    } else {
        dq->rear--;
    }

    printf("Dequeued %d from the rear.\n", element);
    return element;
}

void printDQ(Dequeue* dq) {
    if (isDQEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    int i = dq->front;

    printf("Dequeue elements: ");
    while (1) {
        printf("%d ", dq->data[i]);

        if (i == dq->rear)
            break;

        if (i == dq->size - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}

void freeDQ(Dequeue* dq){
    free(dq->data);
    free(dq);
}

#endif
