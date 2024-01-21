#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MinHeap{
    int* data;
    int maxSize;
    int heapSize;
};

typedef struct MinHeap MinHeap;

MinHeap* createMinHeap(int maxSize){
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->data = (int*)malloc(sizeof(int) * maxSize);
    minHeap->maxSize = maxSize;
    minHeap->heapSize = 0;
    return minHeap;
}

bool isEmpty(MinHeap* minHeap){
    return minHeap->heapSize == 0;
}

bool isFull(MinHeap* minHeap){
    return minHeap->heapSize == minHeap->maxSize;
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

void minHeapify(MinHeap* minHeap, int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;

    if (left < minHeap->heapSize && minHeap->data[left] < minHeap->data[smallest]) {
        smallest = left;
    }

    if (right < minHeap->heapSize && minHeap->data[right] < minHeap->data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(minHeap->data, index, smallest);
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(MinHeap* minHeap, int* array, int size) {
    minHeap->heapSize = size;
    for (int i = 0; i < size; i++) {
        minHeap->data[i] = array[i];
    }

    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

void insert(MinHeap* minHeap, int value){
    if (isFull(minHeap)){
        printf("Error: Heap is full.\n");
        return;
    }

    int index = minHeap->heapSize;
    minHeap->data[index] = value;
    minHeap->heapSize++;

    while(index > 0 && minHeap->data[parent(index)] > minHeap->data[index]){
        swap(minHeap->data, index, parent(index));
        index = parent(index);
    }
}

int getMin(MinHeap* minHeap){
    return isEmpty(minHeap) ? -1 : minHeap->data[0];
}

int removeMin(MinHeap* minHeap){
    if(isEmpty(minHeap)){
        printf("Error: Heap is empty.\n");
        return -1;
    }

    int minElement = minHeap->data[0];
    minHeap->data[0] = minHeap->data[minHeap->heapSize - 1];
    minHeap->heapSize--;

    minHeapify(minHeap, 0);

    return minElement;
}

void printMinHeap(MinHeap* minHeap){
    printf("Min Heap: ");
    for (int i = 0; i < minHeap->heapSize; i++) {
        printf("%d ", minHeap->data[i]);
    }
    printf("\n");
}

#endif