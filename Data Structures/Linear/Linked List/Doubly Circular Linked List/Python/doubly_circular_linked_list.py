class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None
        self.totalNodes = 0

    def is_empty(self):
        return self.head is None

    def append(self, node):
        if self.is_empty():
            self.head = node
            node.next = node
            node.prev = node
        else:
            last_node = self.head.prev
            last_node.next = node
            node.prev = last_node
            node.next = self.head
            self.head.prev = node
        self.totalNodes += 1

    def insert_at_beginning(self, node):
        if self.is_empty():
            self.head = node
            node.next = node
            node.prev = node
        else:
            last_node = self.head.prev
            last_node.next = node
            node.prev = last_node
            node.next = self.head
            self.head.prev = node
            self.head = node
        self.totalNodes += 1

    def insert_after_node(self, reference, node):
        if self.is_empty():
            print(f"NodeNotFoundError: DCLL is empty, can't find Node({reference})")
            return
        else:
            current = self.head
            while current.data != reference:
                current = current.next
                if current == self.head:
                    print(f"NodeNotFoundError: Node({reference}) doesn't exist")
                    return
            next_node = current.next
            current.next = node
            node.prev = current
            node.next = next_node
            next_node.prev = node
            self.totalNodes += 1

    def insert_at_index(self, index, node):
        if index < 0 or index > self.totalNodes:
            print(f"InvalidIndexError: Index {index} is out of bounds")
            return
        if index == 0:
            self.insert_at_beginning(node)
        elif index == self.totalNodes:
            self.append(node)
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next
            next_node = current.next
            current.next = node
            node.prev = current
            node.next = next_node
            next_node.prev = node
            self.totalNodes += 1

    def pop(self):
        if self.is_empty():
            print("EmptyDCLLError: Can't pop from an empty DCLL")
            return -1
        data = self.head.data
        if self.totalNodes == 1:
            self.head = None
        else:
            last_node = self.head.prev
            last_node.prev.next = self.head
            self.head.prev = last_node.prev
        self.totalNodes -= 1
        return data

    def remove_head(self):
        if self.is_empty():
            print("EmptyDCLLError: Can't remove head from an empty DCLL")
            return -1
        data = self.head.data
        if self.totalNodes == 1:
            self.head = None
        else:
            new_head = self.head.next
            self.head.prev.next = new_head
            new_head.prev = self.head.prev
            self.head = new_head
        self.totalNodes -= 1
        return data

    def remove_node(self, data):
        if self.is_empty():
            print(f"EmptyDCLLError: Can't remove node from an empty DCLL")
            return
        current = self.head
        while current.data != data:
            current = current.next
            if current == self.head:
                print(f"NodeNotFoundError: Node({data}) not found")
                return
        if current == self.head:
            self.remove_head()
        else:
            current.prev.next = current.next
            current.next.prev = current.prev
            self.totalNodes -= 1

    def remove_node_at(self, index):
        if index < 0 or index >= self.totalNodes:
            print(f"InvalidIndexError: Index {index} is out of bounds")
            return -1
        if index == 0:
            return self.remove_head()
        current = self.head
        for _ in range(index):
            current = current.next
        current.prev.next = current.next
        current.next.prev = current.prev
        data = current.data
        self.totalNodes -= 1
        return data

    def search_node(self, target):
        if self.is_empty():
            return None
        current = self.head
        while True:
            if current.data == target:
                return current
            current = current.next
            if current == self.head:
                return None

    def get_node_at(self, index):
        if index < 0 or index >= self.totalNodes:
            print(f"InvalidIndexError: Index {index} is out of bounds")
            return None
        current = self.head
        for _ in range(index):
            current = current.next
        return current

    def print_list(self):
        if self.is_empty():
            return
        current = self.head
        while True:
            print(f"<-[{current.data}]->", end=" ")
            current = current.next
            if current == self.head:
                break
        print()

    def free_list(self):
        while not self.is_empty():
            self.pop()
