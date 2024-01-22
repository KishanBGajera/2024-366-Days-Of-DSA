from priority_queue import PriorityQueue, Item

prq = PriorityQueue(max_size=5)
prq.insert(Item(value=10, priority=3))
prq.insert(Item(value=5, priority=2))
prq.insert(Item(value=8, priority=3))

print("Before dequeue()")
prq.print_queue()

print("\nAfter dequeue() x2")
prq.dequeue()
prq.dequeue()
prq.print_queue()