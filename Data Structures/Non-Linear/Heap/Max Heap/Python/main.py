from max_heap import MaxHeap

mheap = MaxHeap(10)

for i in range(10):
    mheap.insert(i+1)

mheap.print()

mheap.remove_max()
mheap.print()

arr = [9, 8, 1, 2, 7, 6]
mheap.build_max_heap(arr)

mheap.print()
