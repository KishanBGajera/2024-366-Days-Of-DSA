#include<stdio.h>
#include "../array.h"

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]); // if elem at the next index is greater, then swap
            }
        }
    }
}

int main()
{
    int arr[] = {48, 45, 27, 29, 10, 18, 20, 37, 47, 13, 29, 28, 39, 32, 35, 14, 32, 11, 42, 38};
    int size = sizeof(arr)/sizeof(int);

    printf("Before sorting: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("After sorting : ");
    printArray(arr, size);
    return 0;
}