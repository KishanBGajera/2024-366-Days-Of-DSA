#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct Item {
    int value;
    int priority;
};

typedef struct Item Item;

Item createItem(int value, int priority) {
    Item item;
    item.value = value;
    item.priority = priority;
    return item;
}

struct PriorityQueue {
    Item* items;
    int maxSize;
    int currentSize;
};

typedef struct PriorityQueue PriorityQueue;

PriorityQueue* getPriorityQueue(int maxSize) {
    PriorityQueue* prq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    prq->maxSize = maxSize;
    prq->items = (Item*)malloc(sizeof(Item) * (prq->maxSize));
    prq->currentSize = 0;
    return prq;
}

bool isPRQFull(PriorityQueue* prq) {
    return prq->currentSize == prq->maxSize;
}

void insertToPRQ(PriorityQueue* prq, Item item) {
    if (!isPRQFull(prq)) {
        prq->items[prq->currentSize++] = item;
    }
}

int peekPRQ(PriorityQueue* prq) {
    int highestPriority = INT_MIN;
    int ind = -1;

    Item* items = prq->items;

    for (int i = 0; i < prq->currentSize; i++) {
        if (highestPriority == items[i].priority && ind > -1 && items[ind].value < items[i].value) {
            highestPriority = items[i].priority;
            ind = i;
        }
        else if (highestPriority < items[i].priority) {
            highestPriority = items[i].priority;
            ind = i;
        }
    }

    return ind;
}

void dequeueFromPRQ(PriorityQueue* prq) {
    int ind = peekPRQ(prq);

    for (int i = ind; i < prq->currentSize - 1; i++) {
        prq->items[i] = prq->items[i + 1];
    }

    prq->currentSize--;
}

void printPRQ(PriorityQueue* prq){
    for (int i = 0; i < prq->currentSize; i++)
    {
        printf("Item: %d, Priority: %d\n", prq->items[i].value, prq->items[i].priority);
    }
}

#endif
