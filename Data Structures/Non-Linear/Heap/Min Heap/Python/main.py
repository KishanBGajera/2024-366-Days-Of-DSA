from min_heap import MinHeap

minheap = MinHeap(10)

for i in range(10, 0, -1):
    minheap.insert(i)

minheap.print()

print(f"Min: {minheap.get_min()}")

minheap.remove_min()

minheap.print()

arr = [0, 9, -1, 2, 4, 20, 10, 45, -20]
minheap.build_min_heap(arr)

minheap.print()
