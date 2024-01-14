#include<stdio.h>
#include "../array.h"

void insertionSort(int* arr, int n){
    int i, key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {9, 7, 2, 3, 1, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}