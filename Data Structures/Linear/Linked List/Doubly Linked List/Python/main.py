from doubly_linked_list import Node, doubly_linked_list

dll = doubly_linked_list()

dll.append_to_list(Node(1))
dll.append_to_list(Node(2))
dll.print_list()

dll.insert_at_beginning(Node(3))
dll.print_list()

dll.insert_at(10, Node(5))
dll.insert_at(2, Node(9))
dll.print_list()

dll.pop_from_list()
dll.print_list()

dll.remove_node(5)
dll.print_list()

idx = dll.search_node(9)
print(idx)

print(dll.get_node_at(1).data)
