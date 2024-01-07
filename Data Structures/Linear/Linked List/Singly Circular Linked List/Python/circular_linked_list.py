class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.total_nodes = 0

    def node_added(self) -> None:
        self.total_nodes += 1

    def node_removed(self) -> None:
        self.total_nodes -= 1

    def is_empty(self) -> bool:
        return self.head == None
    
    def append(self, node: Node) -> None:
        if not self.head:
            self.head = node
            self.head.next = self.head
        else:
            current_node = self.head
            while current_node.next != self.head:
                current_node = current_node.next
            
            current_node.next = node
            node.next = self.head
        self.node_added()

    def insert_at_beginning(self, node: Node) -> None:
        if self.is_empty():
            self.head = node
        else:
            current_node = self.head
            while current_node.next != self.head:
                current_node = current_node.next
            current_node.next = node
            node.next = self.head
            self.head = node
        self.node_added()

    def insert_after_node(self, reference: int, node: Node):
        if self.is_empty():
            return
        else:
            current_node = self.head
            while current_node.next != self.head and current_node.data != reference:
                current_node = current_node.next

            if current_node.data == reference:
                node.next = current_node.next
                current_node.next = node
                self.node_added()

    def insert_at(self, index: int, node: Node):
        if self.total_nodes - 1 < index:
            self.append(node)
        else:
            if index == 0:
                self.insert_at_beginning(node)

    def pop(self) -> int:
        if self.is_empty():
            return -1
        else:
            data = 0
            if self.total_nodes == 1:
                data = self.head.data
                del self.head
                self.head = None
            else:
                current_node = self.head

                while current_node.next.next != self.head:
                    current_node = current_node.next
                
                data = current_node.next.data
                current_node.next = self.head

            self.node_removed()
            return data
        
    def remove_head(self):
        if self.is_empty():
            return
        else:
            data = self.head.data
            current_node = self.head

            while current_node.next != self.head:
                current_node = current_node.next

            head = self.head
            current_node.next = head.next
            self.head = head.next

            return data
        
    def remove_node(self, data: int):
        if self.is_empty():
            return
        else:
            current_node = self.head
            while current_node.next != self.head and current_node.next.data != data:
                current_node = current_node.next

            if current_node.next.data == data:
                node = current_node.next
                current_node.next = node.next
                
                self.node_removed()          
    
    def remove_node_at(self, index: int):
        if self.is_empty():
            return -1
        else:
            data = 0
            if index == 0:
                data = self.remove_head()

            else:
                count = 0
                current_node = self.head
                while count != index:
                    count += 1
                    current_node = current_node.next

                node = current_node.next
                data = node.data
                current_node.next = node.next

                return data
            
    def search(self, target: int) -> int:
        if self.is_empty():
            return -1
        else:
            index = 0
            current_node = self.head

            while current_node.next != self.head and current_node.data != target:
                index += 1
                current_node = current_node.next

            if current_node.data == target:
                return index
            
            return -1
        
    def get_node_at(self, index):
        if self.is_empty():
            return -1
        else:
            counter = 0
            current_node = self.head

            while current_node.next != self.head and counter != index:
                counter += 1
                current_node = current_node.next

            if counter == index:
                return current_node
            
            return -1
        
    def print(self):
        if self.is_empty():
            return
        else:
            current_node = self.head
            while current_node.next != self.head:
                print(f"{current_node.data} -> ", end='')
                current_node = current_node.next
            
            print(f"{current_node.data} -> head")

