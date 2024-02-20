def is_opening(c):
    return c in '([{'

def is_closing(c):
    return c in ')]}'

def is_matching(opening, closing):
    return (opening == '(' and closing == ')') or \
           (opening == '[' and closing == ']') or \
           (opening == '{' and closing == '}')

class Solution:
    def isValid(self, expression: str) -> bool:
        stack = []

        for char in expression:
            if is_opening(char):
                stack.append(char)
            elif is_closing(char):
                if stack == [] or not is_matching(stack.pop(), char):
                    return False
        
        return stack == []