from linked_list import Node, LinkedList

def main():
    ll = LinkedList(10)
    ll.add_to_linked_list(Node(11))
    ll.add_to_linked_list(Node(12))
    
    ll.display_linked_list()

    ll.pop_out_of_linked_list()
    ll.add_to_linked_list(Node(13))

    ll.display_linked_list()

if __name__ == "__main__":
    main()