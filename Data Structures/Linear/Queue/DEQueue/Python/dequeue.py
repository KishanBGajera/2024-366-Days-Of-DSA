class Dequeue:
    def __init__(self, size):
        self.size = size
        self.data = [None] * self.size
        self.front = -1
        self.rear = -1

    def is_empty(self):
        return self.front == -1

    def is_full(self):
        return (self.front == 0 and self.rear == self.size - 1) or (self.front == self.rear + 1)

    def enqueue_front(self, element):
        if self.is_full():
            print("Overflow: Dequeue is full.")
            return

        if self.is_empty():
            self.front = 0
            self.rear = 0
        elif self.front == 0:
            self.front = self.size - 1
        else:
            self.front -= 1

        self.data[self.front] = element
        print(f"Enqueued {element} to the front.")

    def enqueue_rear(self, element):
        if self.is_full():
            print("Overflow: Dequeue is full.")
            return

        if self.is_empty():
            self.front = 0
            self.rear = 0
        elif self.rear == self.size - 1:
            self.rear = 0
        else:
            self.rear += 1

        self.data[self.rear] = element
        print(f"Enqueued {element} to the rear.")

    def dequeue_front(self):
        if self.is_empty():
            print("Underflow: Dequeue is empty.")
            return -1

        element = self.data[self.front]

        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        elif self.front == self.size - 1:
            self.front = 0
        else:
            self.front += 1

        print(f"Dequeued {element} from the front.")
        return element

    def dequeue_rear(self):
        if self.is_empty():
            print("Underflow: Dequeue is empty.")
            return -1

        element = self.data[self.rear]

        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        elif self.rear == 0:
            self.rear = self.size - 1
        else:
            self.rear -= 1

        print(f"Dequeued {element} from the rear.")
        return element

    def print_dequeue(self):
        if self.is_empty():
            print("Dequeue is empty.")
            return

        i = self.front
        print("Dequeue elements:", end=" ")
        while True:
            print(self.data[i], end=" ")

            if i == self.rear:
                break

            if i == self.size - 1:
                i = 0
            else:
                i += 1

        print()
