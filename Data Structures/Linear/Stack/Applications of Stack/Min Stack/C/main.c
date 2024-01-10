#include "stack.h"

struct MinStack{
    Stack* stack;
    Stack* minStack;  
};

typedef struct MinStack MinStack;

MinStack* createMinStack(int size){
    MinStack* ms = (MinStack*)malloc(sizeof(MinStack));
    ms->stack = createStack(size);
    ms->minStack = createStack(size);
    return ms;
}

void pushToMinStack(MinStack* ms, int data){
    push(ms->stack, data);
    if((ms->minStack->top == -1) || ms->minStack->data[ms->minStack->top] > data){
        push(ms->minStack, data);
    }
}

int popFromMinStack(MinStack* ms){
    if(ms->stack->data[ms->stack->top] == ms->minStack->data[ms->minStack->top]){
        pop(ms->minStack);
    }
    return pop(ms->stack);
}

int peekMinStack(MinStack* ms){
    return peek(ms->stack);
}

int getMinFromMinStack(MinStack* ms){
    return ms->minStack->data[ms->minStack->top];
}

int main()
{
    MinStack* ms = createMinStack(10);
    pushToMinStack(ms, 2);
    pushToMinStack(ms, 5);
    pushToMinStack(ms, 4);
    pushToMinStack(ms, -1);
    pushToMinStack(ms, 10);
    pushToMinStack(ms, 3);
    pushToMinStack(ms, -2);

    printf("popped: %d\n", popFromMinStack(ms));
    printf("min: %d\n", getMinFromMinStack(ms));
    printf("popped: %d\n", popFromMinStack(ms));
    printf("popped: %d\n", popFromMinStack(ms));
    printf("popped: %d\n", popFromMinStack(ms));
    printf("min: %d\n", getMinFromMinStack(ms));
    return 0;
}
