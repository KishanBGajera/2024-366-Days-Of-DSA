from typing import List

def is_operator(c: chr):
    if c in "+-*/":
        return True
    return False

def operate(op2, op1, operator) -> float:
    match operator:
        case '+':
            return op1 + op2
        case '-':
            return op1 - op2
        case '*':
            return op1 * op2
        case '/':
            return int(op1 / op2)

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operands = []

        for c in tokens:
            if not is_operator(c):
                operands.append(int(c))
            else:
                operands.append(operate(operands.pop(), operands.pop(), c))
        
        return operands[-1]