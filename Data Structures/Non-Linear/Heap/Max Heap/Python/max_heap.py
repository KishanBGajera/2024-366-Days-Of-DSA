class MaxHeap:
    def __init__(self, max_size) -> None:
        self.max_size = max_size
        self.data = []
        self.heap_size = 0

    def parent(self, i: int) -> int:
        return (i - 1)//2
    
    def left_child(self, i: int) -> int:
        return 2 * i + 1
    
    def right_child(self,i: int) -> int:
        return 2 * i + 2
    
    def is_full(self) -> bool:
        return self.heap_size == self.max_size
    
    def is_empty(self) -> bool:
        return self.heap_size == 0
    
    def build_max_heap(self, data):
        self.data = []
        size = len(data)
        self.heap_size = size
        for i in range(size):
            self.data.append(data[i])

        for i in range(size//2 - 1, -1, -1):
            self.max_heapify(i)
    
    def max_heapify(self, index) -> None:
        left = self.left_child(index)
        right = self.right_child(index)
        largest = index

        if left < self.heap_size and self.data[left] > self.data[largest]:
            largest = left

        if right < self.heap_size and self.data[right] > self.data[largest]:
            largest = right

        if largest != index:
            self.data[index], self.data[largest] = self.data[largest], self.data[index]
            self.max_heapify(largest)
    
    def insert(self, value):
        if self.is_full():
            print("Error: Heap is full")
            return
        index = self.heap_size
        self.data.append(value)
        self.heap_size += 1

        while index > 0 and self.data[self.parent(index)] < self.data[index]:
            self.data[index], self.data[self.parent(index)] = self.data[self.parent(index)], self.data[index]
            index = self.parent(index)

    def remove_max(self):
        if self.is_empty():
            print("Error: Heap is empty")
            return
        
        max_element = self.data[0]
        self.data[0] = self.data[-1]
        self.heap_size -= 1

        self.max_heapify(0)

        return max_element
    
    def print(self):
        print("Max Heap: ")
        for i in range(self.heap_size):
            print(self.data[i], end=' ')
        print()