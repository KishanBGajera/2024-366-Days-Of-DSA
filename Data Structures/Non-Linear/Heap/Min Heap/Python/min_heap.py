class MinHeap:
    def __init__(self, max_size) -> None:
        self.max_size = max_size
        self.data = []
        self.heap_size = 0

    def is_empty(self):
        return self.heap_size == 0
    
    def is_full(self):
        return self.heap_size == self.max_size
    
    def parent(self, i: int) -> int:
        return (i - 1)//2
    
    def left_child(self, i: int) -> int:
        return 2 * i + 1
    
    def right_child(self,i: int) -> int:
        return 2 * i + 2
    
    def min_heapify(self, index):
        left = self.left_child(index)
        right = self.right_child(index)
        smallest = index

        if left < self.heap_size and self.data[left] < self.data[smallest]:
            smallest = left

        if right < self.heap_size and self.data[right] < self.data[smallest]:
            smallest = right

        if smallest != index:
            self.data[index], self.data[smallest] = self.data[smallest], self.data[index]
            self.min_heapify(smallest)

    def build_min_heap(self, data):
        self.data = []
        size = len(data)
        self.heap_size = size

        for i in range(size):
            self.data.append(data[i])

        for i in range(size//2 - 1, -1, -1):
            self.min_heapify(i)

    def insert(self, value):
        if self.is_full():
            print("Error: Heap is full")
            return
        index = self.heap_size
        self.data.append(value)
        self.heap_size += 1

        while index > 0 and self.data[self.parent(index)] > self.data[index]:
            self.data[index], self.data[self.parent(index)] = self.data[self.parent(index)], self.data[index]
            index = self.parent(index)

    def get_min(self):
        return -1 if self.is_empty() else self.data[0]
    
    def remove_min(self):
        if self.is_empty():
            print("Error: Heap is empty")
            return
        
        min_element = self.data[0]
        self.data[0] = self.data[-1]
        self.heap_size -= 1

        self.min_heapify(0)

        return min_element
    
    def print(self):
        print("Min Heap: ")
        for i in range(self.heap_size):
            print(self.data[i], end=' ')
        print()
