class Item:
    def __init__(self, value, priority):
        self.value = value
        self.priority = priority

class PriorityQueue:
    def __init__(self, max_size):
        self.items = []
        self.max_size = max_size
        self.current_size = 0

    def is_full(self):
        return self.current_size == self.max_size

    def insert(self, item):
        if not self.is_full():
            self.items.append(item)
            self.current_size += 1

    def peek(self):
        highest_priority = float('-inf')
        index = -1

        for i, item in enumerate(self.items):
            if highest_priority == item.priority and index > -1 and self.items[index].value < item.value:
                highest_priority = item.priority
                index = i
            elif highest_priority < item.priority:
                highest_priority = item.priority
                index = i

        return index

    def dequeue(self):
        index = self.peek()

        if index != -1:
            del self.items[index]
            self.current_size -= 1

    def print_queue(self):
        for item in self.items:
            print(f"Item: {item.value}, Priority: {item.priority}")

