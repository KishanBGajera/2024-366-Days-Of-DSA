class Stack:
    def __init__(self, size: int = None) -> None:
        self.size = size
        self.top = -1
        self.data = []
        print(f"Stack[{self.size}] created")
    
    def set_size(self, size: int) -> None:
        self.size = size
        print(f"Stack size set to {size}")

    def push(self, data: int) -> None:
        if not self.size:
            print(f"Stack size not set, can't perform `push({data})`")
            return
        if self.top < self.size - 1:
            self.top += 1
            self.data.insert(self.top, data)
            print(f"{data} pushed to stack")
        else:
            print(f"StackOverFlow: maximum elements pushed, can't `push({data})`")

    def pop(self) -> int:
        if self.top == -1:
            print("StackUnderFlow: Stack is empty, can't `pop()`")
        else:
            print(f"{self.data[self.top]} popped out of stack")
            self.top -= 1
            return self.data[self.top + 1]
        
    def peek(self) -> int:
        if self.top == -1:
            return -1
        else:
            return self.data[self.top]
        
    def print_stack(self) -> None:
        if self.top == -1:
            print(f"Stack[{self.size}] is empty, can't `printStack()`")
        else:
            print(f"Stack[{self.size}]:")
            for i in range(self.top, -1, -1):
                print(f"| {self.data[i]} |")