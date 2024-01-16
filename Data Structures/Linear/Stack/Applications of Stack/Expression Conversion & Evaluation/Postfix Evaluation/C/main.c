#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prec(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

char* infixToPostfix(char infixExpr[]) {
    int len = strlen(infixExpr);
    char *postfixExpr = (char*)malloc(sizeof(char) * (len + 1));
    int p = 0;
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = infixExpr[i];

        if (isalnum(c)) {
            postfixExpr[p++] = c;
        } else if (c == '(') {
            stack[++stackIndex] = c;
        } else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                postfixExpr[p++] = stack[stackIndex--];
            }
            stackIndex--;
        } else {
            while (stackIndex >= 0 && (prec(infixExpr[i]) <= prec(stack[stackIndex]))) {
                postfixExpr[p++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    while (stackIndex >= 0) {
        postfixExpr[p++] = stack[stackIndex--];
    }

    postfixExpr[p] = '\0';

    return postfixExpr;
}

double evaluatePostfix(char* postfixExpr) {
    int len = strlen(postfixExpr);
    double stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        if (isdigit(postfixExpr[i])) {
            stack[++stackIndex] = postfixExpr[i] - '0';
        } else {
            double operand2 = stack[stackIndex--];
            double operand1 = stack[stackIndex--];

            switch (postfixExpr[i]) {
                case '+':
                    stack[++stackIndex] = operand1 + operand2;
                    break;
                case '-':
                    stack[++stackIndex] = operand1 - operand2;
                    break;
                case '*':
                    stack[++stackIndex] = operand1 * operand2;
                    break;
                case '/':
                    stack[++stackIndex] = operand1 / operand2;
                    break;
            }
        }
    }
    return stack[0];
}
int main(int argc, char const *argv[])
{
    char* expr = "1+2-3*4";
    char* postfixExpr = infixToPostfix(expr);
    double evaluation = evaluatePostfix(postfixExpr);
    printf("%f", evaluation);
    return 0;
}

