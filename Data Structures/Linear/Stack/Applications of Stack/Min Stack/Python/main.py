class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, x):
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self):
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        return self.stack.pop()

    def top(self):
        return self.stack[-1]

    def getMin(self):
        return self.min_stack[-1]
    
minStack = MinStack()

minStack.push(2)
minStack.push(5)
minStack.push(4)
minStack.push(-1)
minStack.push(10)
minStack.push(3)
minStack.push(-2)

print(minStack.pop())
print(minStack.getMin())
print(minStack.pop())
print(minStack.pop())
print(minStack.pop())
print(minStack.getMin())
