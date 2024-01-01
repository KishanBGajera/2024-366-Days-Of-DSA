from stack import Stack

stk = Stack(5)

for i in range(0, stk.size):
    stk.push((i + 1) * 10)

stk.print_stack()
stk.pop()
stk.print_stack()