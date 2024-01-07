from circular_linked_list import Node, CircularLinkedList

def main():
    cll = CircularLinkedList()

    cll.append(Node(1))
    cll.append(Node(2))
    cll.append(Node(3))

    print("Original Circular Linked List:")
    cll.print()

    cll.insert_after_node(2, Node(4))

    print("\nCircular Linked List after Insertion:")
    cll.print()

    cll.remove_node(2)

    print("\nCircular Linked List after Removal:")
    cll.print()

    popped_data = cll.pop()
    print("\nPopped Node Data:", popped_data)

    print("Circular Linked List after Pop:")
    cll.print()

    target_index = cll.search(3)
    print("\nIndex of Node with Data 3:", target_index)

    node_at_index = cll.get_node_at(1)
    try:
        print("Node at Index 1:", node_at_index.data)
    except AttributeError:
        print("Node doesn't exist")

if __name__ == "__main__":
    main()
