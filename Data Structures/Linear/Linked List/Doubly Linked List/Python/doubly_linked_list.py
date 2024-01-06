class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.prev = None
        self.next = None

class doubly_linked_list:
    def __init__(self) -> None:
        self.head = None
        self.total_nodes = 0

    def is_empty(self) -> bool:
        return self.head == None
    
    def node_added(self):
        self.total_nodes += 1
    
    def node_removed(self):
        self.total_nodes -= 1
    
    def append_to_list(self, node: Node) -> None:
        if self.is_empty():
            self.head = node
        else:
            current_node = self.head
            while current_node.next:
                current_node = current_node.next
            node.prev = current_node
            current_node.next = node
        
        self.node_added()

    def insert_at_beginning(self, node: Node) -> None:
        if self.is_empty():
            self.head = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

        self.node_added()

    def insert_at(self, index: int, node: Node) -> None:
        if self.total_nodes - 1 < index:
            self.append_to_list(node)
            return
        else:
            if index == 0:
                self.insert_at_beginning(node)
                return
            counter = 0
            current_node = self.head
            
            while counter != index - 1:
                current_node = current_node.next
                counter += 1
            
            node.prev = current_node
            node.next = current_node.next
            current_node.next = node
            self.node_added()

    def pop_from_list(self):
        if self.is_empty():
            return -1
        
        data = 0
        if not self.head.next:
            data = self.head.data
            self.head = None
        else:
            current_node = self.head
            while current_node.next.next:
                current_node = current_node.next
            
            data = current_node.next.data
            current_node.next = None
        self.node_removed()
        return data
    
    def remove_node(self, data):
        if self.is_empty():
            return
       
        current_node = self.head
        while current_node.next and current_node.next.data == data:
            current_node = current_node.next

        if current_node.next.data == data:
            current_node.next.prev = current_node
            target = current_node.next
            current_node.next = current_node.next.next
            self.node_removed()

    def search_node(self, target):
        counter = 0
        current_node = self.head

        while current_node and current_node.data != target:
            current_node = current_node.next
            counter += 1

        if current_node and current_node.data == target:
            return counter
        
        return -1
    
    def get_node_at(self, index):
        if index > self.total_nodes:
            return -1
        
        current_node = self.head
        counter = 0

        while current_node and counter != index:
            current_node = current_node.next
            counter += 1

        if counter == index:
            return current_node
        
        return -1
    
    def print_list(self):
        if self.is_empty():
            return
        
        print(f"DLL[{self.total_nodes}]: ", end='')
        current_node = self.head
        while current_node:
            print(f" <-[{current_node.data}]-> ", end='')
            current_node = current_node.next
        print('\n')