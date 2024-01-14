#include<stdio.h>

int linearSearch(int *arr, int size, int target){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target){
            return i;
        }
    }
    return -1; // sentinel value
}

int main()
{
    int arr[] = {7, 26, 47, 3, 43, 6, 50, 4, 33, 19, 11, 28, 23, 32, 25, 12, 15, 18, 12, 41}; // or any random array
    int size = sizeof(arr)/sizeof(int);
    
    int target, idx;
    printf("Enter an element: ");
    scanf("%d", &target);
    
    idx = linearSearch(arr, size, target);
    printf("index:%d\n", idx);
    return 0;
}