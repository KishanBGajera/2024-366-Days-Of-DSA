#ifndef ARRAY_H /* Because, DRY (Don't Repeat Yourself) */
#define ARRAY_H

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif