from queue import Queue

q = Queue()

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)

print("Queue size:", q.size())

print("Peek:", q.peek())

print("Dequeue:", q.dequeue()) 
