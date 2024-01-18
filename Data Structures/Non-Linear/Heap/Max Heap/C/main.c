#include "maxheap.h"

int main()
{
    MaxHeap* maxHeap = createMaxHeap(10);
    for (int i = 0; i < 10; i++)
    {
        insert(maxHeap, i+1);
    }
    printMaxHeap(maxHeap);

    removeMax(maxHeap);
    printMaxHeap(maxHeap);

    int arr[] = {9, 8, 1, 2, 7, 6};
    int size = sizeof(arr)/sizeof(int);
    
    buildMaxHeap(maxHeap, arr, size);
    printMaxHeap(maxHeap);

    return 0;
}
