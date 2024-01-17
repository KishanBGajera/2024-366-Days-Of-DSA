from dequeue import Dequeue

dequeue_size = 10
dq = Dequeue(dequeue_size)

for i in range(1, 6):
    dq.enqueue_front(i)

for i in range(6, 11):
    dq.enqueue_rear(i)

dq.print_dequeue()

for _ in range(3):
    dq.dequeue_front()

dq.print_dequeue()

for _ in range(2):
    dq.dequeue_rear()

dq.print_dequeue()
