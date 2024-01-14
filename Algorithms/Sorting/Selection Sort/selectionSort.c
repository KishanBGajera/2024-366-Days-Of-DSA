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
    int arr[] = {48, 45, 27, 29, 10, 18, 20, 37, 47, 13, 29, 28, 39, 32, 35, 14, 32, 11, 42, 38};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}