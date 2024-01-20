#include<stdio.h>

int interpolationSearch(int arr[], int target, int low, int high){
    if(low < high && arr[low] <= target <= arr[high]){
        int position = low + ((high - low)/(arr[high] - arr[low]))*(target - arr[low]);
        if(arr[position] == target){
            return position;
        }
        else if (arr[position] < target){
            return interpolationSearch(arr, target, position + 1, high);
        }
        else{
            return interpolationSearch(arr, target, low, position - 1);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int size = sizeof(arr)/sizeof(int);

    int n = 12;

    int position = interpolationSearch(arr, n, 0, size - 1);
    printf("%d at index %d\n", n, position);
    return 0;
}