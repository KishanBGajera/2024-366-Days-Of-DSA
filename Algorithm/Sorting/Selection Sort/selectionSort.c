#include<stdio.h>
#include "../array.h"

int min(int arr[], int from, int to){
    int min = from;
    for (int i = from + 1; i < to; i++)
    {
        if(arr[i] < arr[min]){
            min = i;
        }
    }
    return min;
}

void selectionSort(int arr[], int size){
    int min_idx;
    for (int i = 0; i < size; i++)
    {
        min_idx = min(arr, i, size);
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[] = {3, 4, 2, 7, 8, -1, 2};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}