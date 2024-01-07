# Singly Linked List

- Singly Linked List is a [Linked List](../notes.md) which has `data` and `next` data member, which means it only points to the next `Node`.

### Node

```c
// in C
struct Node{
    int data;
    struct Node* next;
}
```

```python
# in Python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
```

