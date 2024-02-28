from doubly_circular_linked_list import Node, DoublyCircularLinkedList

dcll = DoublyCircularLinkedList()

dcll.append(Node(1))
dcll.append(Node(2))
dcll.append(Node(3))

dcll.print_list()

dcll.insert_at_beginning(Node(0))

dcll.print_list()

dcll.insert_after_node(2, Node(2.5))

dcll.print_list()

dcll.remove_head()

dcll.print_list()

print(dcll.pop())

dcll.print_list()

dcll.free_list()
