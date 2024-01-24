#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MaxHeap {
    int* data;
    int maxSize;
    int heapSize;
};

typedef struct MaxHeap MaxHeap;

MaxHeap* createMaxHeap(int maxSize) {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->data = (int*)malloc(sizeof(int) * maxSize);
    maxHeap->maxSize = maxSize;
    maxHeap->heapSize = 0;
    return maxHeap;
}

bool isEmpty(MaxHeap* maxHeap){
    return maxHeap->heapSize == 0;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void maxHeapify(MaxHeap* maxHeap, int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if (left < maxHeap->heapSize && maxHeap->data[left] > maxHeap->data[largest]) {
        largest = left;
    }

    if (right < maxHeap->heapSize && maxHeap->data[right] > maxHeap->data[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(maxHeap->data, index, largest);
        maxHeapify(maxHeap, largest);
    }
}

void buildMaxHeap(MaxHeap* maxHeap, int* array, int size) {
    maxHeap->heapSize = size;
    for (int i = 0; i < size; i++) {
        maxHeap->data[i] = array[i];
    }

    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(maxHeap, i);
    }
}

void insert(MaxHeap* maxHeap, int value) {
    if (maxHeap->heapSize == maxHeap->maxSize) {
        printf("Error: Heap is full.\n");
        return;
    }

    int index = maxHeap->heapSize;
    maxHeap->data[index] = value;
    maxHeap->heapSize++;

    while (index > 0 && maxHeap->data[parent(index)] < maxHeap->data[index]) {
        swap(maxHeap->data, index, parent(index));
        index = parent(index);
    }
}

int getMax(MaxHeap* maxHeap){
    return isEmpty(maxHeap) ? -1 : maxHeap->data[0];
}

int removeMax(MaxHeap* maxHeap) {
    if (maxHeap->heapSize == 0) {
        printf("Error: Heap is empty.\n");
        return -1;
    }

    int maxElement = maxHeap->data[0];
    maxHeap->data[0] = maxHeap->data[maxHeap->heapSize - 1];
    maxHeap->heapSize--;

    maxHeapify(maxHeap, 0);

    return maxElement;
}

void printMaxHeap(MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->heapSize; i++) {
        printf("%d ", maxHeap->data[i]);
    }
    printf("\n");
}

void printInHeapForm(MaxHeap* maxHeap, int level, int index){
    if(index < maxHeap->heapSize){
        printInHeapForm(maxHeap, level + 1, 2*index + 2);
        for (int i = 0; i < level; i++)
        {
            printf("    ");
        }
        printf("%d\n", maxHeap->data[index]);
        printInHeapForm(maxHeap, level + 1, 2*index + 1);
    }
}

#endif
