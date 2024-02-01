#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("StackOverflow\n");
        return;
    }
    stack->items[++stack->top] = c;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("StackUnderflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

bool isOpening(char c) {
    return (c == '(' || c == '[' || c == '{');
}

bool isClosing(char c) {
    return (c == ')' || c == ']' || c == '}');
}

bool isMatching(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool checkBalancedParentheses(const char *expression) {
    Stack stack;
    initialize(&stack);

    while (*expression != '\0') {
        if (isOpening(*expression)) {
            push(&stack, *expression);
        } else if (isClosing(*expression)) {
            if (stack.top == -1 || !isMatching(pop(&stack), *expression)) {
                return false;
            }
        }
        expression++;
    }

    return stack.top == -1;
}

int main() {
    const char *expression1 = "{[()]}";
    const char *expression2 = "((())";
    
    printf("Expression1 is %sbalanced\n", checkBalancedParentheses(expression1) ? "" : "not ");
    printf("Expression2 is %sbalanced\n", checkBalancedParentheses(expression2) ? "" : "not ");
    
    return 0;
}
