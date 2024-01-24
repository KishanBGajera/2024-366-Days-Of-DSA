# Heap Sort
> refer to [Heap Data Structure](<../../../Data Structures/Non-Linear/Heap>) for a better explanation.

### Algorithm

```c
void HeapSort(array){
    BuildMaxHeap(array);
    for(i = array.heapSize - 1 to 1){
        swap(array[0], array[i]);
        MaxHeapify(array, 0);
    }
}
```