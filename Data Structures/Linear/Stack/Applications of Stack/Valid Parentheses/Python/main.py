class Stack:
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if not self.items:
            print("StackUnderflow")
            return None
        return self.items.pop()
    
    def is_empty(self):
        return len(self.items) == 0

def is_opening(c):
    return c in '([{'

def is_closing(c):
    return c in ')]}'

def is_matching(opening, closing):
    return (opening == '(' and closing == ')') or \
           (opening == '[' and closing == ']') or \
           (opening == '{' and closing == '}')

def check_balanced_parentheses(expression):
    stack = Stack()

    for char in expression:
        if is_opening(char):
            stack.push(char)
        elif is_closing(char):
            if stack.is_empty() or not is_matching(stack.pop(), char):
                return False
    
    return stack.is_empty()

def main():
    expression1 = "1 + 2 * [3 + 4 / (5 + 6)]"
    expression2 = "(1+2"
    
    print("Expression1 is {}balanced".format("" if check_balanced_parentheses(expression1) else "not "))
    print("Expression2 is {}balanced".format("" if check_balanced_parentheses(expression2) else "not "))

if __name__ == "__main__":
    main()
