from string import ascii_letters

class Stack:
    def __init__(self) -> None:
        self.data = []

    def is_empty(self) -> bool:
        return not self.data

    def push(self, data: chr) -> None:
        self.data.append(data)

    def pop(self) -> chr:
        if self.data:
            return self.data.pop()
    
    def peek(self) -> chr:
        return self.data[-1]

def priority(c: chr):
    match(c):
        case '&':
            return -1
        case '|':
            return -1
        case '(':
            return 0
        case '+':
            return 1
        case '-':
            return 1
        case '*':
            return 2
        case '/':
            return 2
        case '^':
            return 3

def isalnum(c: chr):
    if ord(c) in range(48, 59) or c in ascii_letters:
        return True
    return False

def is_operator(c: chr):
    if c in "+-*/^":
        return True
    return False

def infix_to_postfix(infix_expr: str) -> str:
    stack = Stack()
    postfix_expr = ''
    for c in infix_expr:
        if isalnum(c):
            postfix_expr += c

        elif c == '(':
            stack.push(c)

        elif is_operator(c):
            if stack.is_empty():
                stack.push(c)
            else:
                while not stack.is_empty() and priority(stack.peek()) >= priority(c):
                    postfix_expr += stack.pop()
                stack.push(c)

        elif c == ')':
            while stack.peek() != '(':
                postfix_expr += stack.pop()
            stack.pop()
        
        print(c.center(len(infix_expr)), end='|')
        print("".join(stack.data).center(len(infix_expr)), end='|')
        print(postfix_expr.center(len(infix_expr)), end='|')
        print()

    while not stack.is_empty():
        postfix_expr += stack.pop()

    return postfix_expr

def infix_to_prefix(infix_expr: str) -> str:
    pass

infix_expr = "a*(b+c)"
postfix_expr = infix_to_postfix(infix_expr)
print(postfix_expr)
# prefix_expr = infix_to_prefix(infix_expr)            
# print(prefix_expr)
