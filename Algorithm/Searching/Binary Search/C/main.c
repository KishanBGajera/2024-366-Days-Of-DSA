#include<stdio.h>

int binarySearch(int* arr, int target, int l, int h){
    if(l <= h){
        int m = (l + h)/2;
        if(arr[m] == target){
            return m;
        }
        else if(arr[m] < target){
            l = m + 1;
            return binarySearch(arr, target, l, h);
        }
        else{
            h = m - 1;
            return binarySearch(arr, target, l, h);
        }
    }
    return -1; // sentinel value for TargetNotFound
}

int main()
{
    int arr[] = {1, 2, 3, 6, 9, 13, 17, 19, 25, 31, 36, 40, 50, 63}; // comment this
    int size = sizeof(arr)/sizeof(int);
    int target;
    scanf("%d", &target);
    int idx = binarySearch(arr, target, 0, size - 1);
    printf("idx: %d", idx);

    
    // int size;
    // printf("Enter size: ");
    // scanf("%d", &size);
    // 
    // int arr[size];
    // for(int i = 0; i < size; i++){
    //      scanf("%d", arr[i]);
    // }
    //
    // int target;
    // scanf("%d", &target);
    // int idx = binarySearch(arr, target, 0, size - 1);
    // printf("idx: %d", idx);
    
    return 0;
}