#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *data;
    int size;
    int top;
};

struct Stack* createStack(int size){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->data = (int*)malloc(sizeof(int)*stack->size);
    stack->top = -1;
    // printf("Stack[%d] created\n", stack->size);
    return stack;
}

void push(struct Stack* stack, int data){
    if(stack->top < stack->size - 1){
        stack->data[++stack->top] = data;
        // printf("%d pushed to stack\n", stack->data[stack->top]);
    }
    else{
        printf("StackOverFlow: maximum elements pushed, can't `push(%d)`\n", data);
    }
}

int pop(struct Stack* stack){
    if (stack->top == -1)
    {
        printf("StackUnderFlow: Stack is empty, can't `pop()`\n");
    }
    else{
        // printf("%d popped out of stack\n", stack->data[stack->top]);
        return stack->data[stack->top--];
    }
}

int peek(struct Stack* stack){
    if(stack->top == -1){
        return -1;
    }
    else{
        return stack->data[stack->top];
    }
}

void printStack(struct Stack* stack){
    if(stack->top == -1){
        printf("Stack[%d] is empty, can't `printStack()`\n", stack->size);
        return;
    }
    else{
        // printf("Stack[%d]:\n", stack->size);
        for (int i = stack->top; i >= 0; i--)
        {
            printf("| %d |\n", stack->data[i]);
        }
    }
}

void freeStackMemory(struct Stack* stack){
    free(stack->data);
    free(stack);
}

typedef struct Stack Stack;

#endif