#include "./stack.h"

void printMenu() {
    printf(">>> Choose an operator:\n");
    printf("...\t\t +: addition\n");
    printf("...\t\t -: subtraction\n");
    printf("...\t\t *: multiplication\n");
    printf("...\t\t /: division\n");
    printf("...\t\t u: undo\n");
    printf("...\t\t r: redo\n");
    printf("...\t\t e: EXIT\n");
}

void getUserInput(char* choice, int* operand) {
    fflush(stdin);
    printf(">>> Enter choice: ");
    scanf(" %c", choice);

    if (*choice != 'u' && *choice != 'r' && *choice != 'e') {
        printf(">>> Enter another operand: ");
        scanf("%d", operand);
    }
}

void operate(int *mainOperand, int anotherOperand, char operator, Stack* undo, Stack* redo){
    if (operator == 'r') {
        push(undo, *mainOperand);
        *mainOperand = pop(redo);
        return;
    }

    if (operator == 'u') {
        push(redo, *mainOperand);
        *mainOperand = pop(undo);
        return;
    }

    else{
        push(undo, *mainOperand);
        
        switch (operator)
        {
            case '+':
                *mainOperand += anotherOperand;
                break;
            case '-':
                *mainOperand -= anotherOperand;
                break;
            case '*':
                *mainOperand *= anotherOperand;
                break;
            case '/':
                *mainOperand /= anotherOperand;
                break;
            default:
                printf("Invalid Operator\n");
                pop(undo);
                break;
        }
    }
}

int main(){
    Stack* undo = createStack(10);
    Stack* redo = createStack(10);
    
    int currentValue = 0;

    while (1) {
        printf(">>> Current Value: %d\n", currentValue);
        printMenu();

        char choice;
        int anotherOperand = 0;

        getUserInput(&choice, &anotherOperand);

        if (choice != 'e') {
            operate(&currentValue, anotherOperand, choice, undo, redo);
        } else {
            break;
        }
    }

    return 0;
}
