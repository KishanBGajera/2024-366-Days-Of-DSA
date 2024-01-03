class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def set_value(self, data):
        print(f"Node({self.data}) updated/set to Node({data})")
        self.data = data

class LinkedList:
    def __init__(self, size):
        self.size = size
        self.head = None

    def add_to_linked_list(self, node):
        if not self.head:
            self.head = node
        else:
            current_node = self.head
            while current_node.next:
                current_node = current_node.next
            current_node.next = node
        print(f"Node({node.data}) added to LinkedList[{self.size}]")

    def pop_out_of_linked_list(self):
        current_node = self.head
        next_node = current_node.next

        while next_node.next:
            current_node = current_node.next
            next_node = next_node.next

        current_node.next = None
        print(f"Node({next_node.data}) popped out of LinkedList[{self.size}]")
        popped_data = next_node.data
        del next_node
        return popped_data

    def remove_from_linked_list(self, data):
        current_node = self.head
        next_node = current_node.next

        if current_node.data == data:
            self.head = next_node
            print(f"Removed Node({current_node.data}) from LinkedList[{self.size}]")
            current_node.free_memory()
            return

        while next_node and next_node.data != data:
            current_node = next_node
            next_node = next_node.next

        if next_node:
            current_node.next = next_node.next
            print(f"Removed Node({next_node.data}) from LinkedList[{self.size}]")
            next_node.free_memory()
        else:
            print(f"Node with data {data} not found in LinkedList[{self.size}]")

    def display_linked_list(self):
        current_node = self.head
        print("head -> ", end="")
        while current_node:
            print(f"{current_node.data} -> ", end="")
            current_node = current_node.next
        print()
