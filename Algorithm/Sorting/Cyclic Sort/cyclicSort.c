#include <stdio.h>
#include "../array.h"

void cyclicSort(int arr[], int n) {
    for (int i = 0; i < n; ) {
        if (arr[i] == i + 1) {
            i++;
        } else {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {1, 2, 3, 9, 8, 7, 5, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    cyclicSort(arr, n);

    printf("Array after cyclic sort: ");
    printArray(arr, n);

    return 0;
}
