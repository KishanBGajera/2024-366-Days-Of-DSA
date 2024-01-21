#include "minHeap.h"

int main(){
    MinHeap* minHeap = createMinHeap(10);
    
    for (int i = 10; i > 0; i--)
    {
        insert(minHeap, i);
    }
    
    printMinHeap(minHeap);

    printf("Min: %d\n", getMin(minHeap));
    removeMin(minHeap);

    printMinHeap(minHeap);

    int arr[] = {10, 11, 20, 2, 30, 40, 5, 34};
    int size = sizeof(arr)/sizeof(int);
    buildMinHeap(minHeap, arr, size);

    printMinHeap(minHeap);

    return 0;
}
