#include "stack.h"

int main()
{
    struct Stack* stack = createStack(8);
    for (int i = 0; i < stack->size; i++)
    {
        push(stack, (i+1)*10);
    }
    printStack(stack);
    push(stack, 90);
    
    int peeked = peek(stack);
    printf("peek: %d\n", peeked);

    while(stack->top!=-1){
        pop(stack);
    }
    printStack(stack);
    pop(stack);
    return 0;
}