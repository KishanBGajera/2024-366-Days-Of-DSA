#include<stdio.h>
#include "../array.h"

void merge(int* arr, int l, int m, int h){
    int n1 = m - l + 1, n2 = h - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}

void mergeSort(int* arr, int l, int h){
    if(l < h){
        int m = (l + h)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main()
{
    int arr[] = {9, 7, 3, 6, 1, 7, 8, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    printf("Before: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);
    
    printf("After: ");
    printArray(arr, n);
    
    return 0;
}