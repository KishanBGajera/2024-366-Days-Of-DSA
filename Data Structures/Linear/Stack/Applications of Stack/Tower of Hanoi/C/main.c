/** 
 * Move all the disks stacked on the first tower over to the last tower using a helper tower in the middle.
 * While moving the disks, certain rules must be followed. These are : 
 * 1. Only one disk can be moved.
 * 2. A larger disk can not be placed on a smaller disk.
*/
#include <math.h>
#include "stack.h"
#define max(a, b, c) (a > b)?(a > c ? a : c):(b > c ? b : c) // program specific macro

typedef struct Stack Stack;

// Tower = Stack + name
struct Tower {
    Stack* stack;
    char name; // One character names, i.e. A, B, and C
};

typedef struct Tower Tower;

Tower* getTower(char name, int size){
    Tower* tower = (Tower*)malloc(sizeof(Tower));
    tower->name = name;
    tower->stack = createStack(size);
    return tower;
}

void printTowers(Tower* A, Tower* B, Tower* C){
    int maxTop = max(A->stack->top, B->stack->top, C->stack->top);
    maxTop++; // since, `stack->top` represents the top element's index, and we want total elems
    int counter = maxTop;
    printf("\nTowers:\n");
    for (int i = maxTop; i > 0; i--)
    {   
        counter--;

        if(i <= A->stack->top + 1){
            printf("| %d | ", A->stack->data[counter]);
        }
        else{
            printf("|   | ");
        }

        if(i <= B->stack->top + 1){
            printf("| %d | ", B->stack->data[counter]);
        }
        else{
            printf("|   | ");
        }

        if(i <= C->stack->top + 1){
            printf("| %d | ", C->stack->data[counter]);
        }
        else{
            printf("|   | ");
        }
        printf("\n");
    }
    
    printf("_____ _____ _____\n");
    printf("| %c | | %c | | %c |\n", A->name, B->name, C->name); // more about it in the README.md
}

void moveToTower(Tower* source, Tower* destination){
    int disk = pop(source->stack);
    push(destination->stack, disk);
    printf("\nDisk %d moved from Tower %c to Tower %c\n", disk, source->name, destination->name);
}

void towerOfHanoi(int n, Tower* A, Tower* B, Tower* C){
    if(n > 0){
        towerOfHanoi(n - 1, A, C, B);
        moveToTower(A, C);
        printTowers(A, B, C);
        towerOfHanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n; // number of disks
    scanf("%d", &n);

    Tower* A = getTower('A', n);
    Tower* B = getTower('B', n);
    Tower* C = getTower('C', n);

    for (int i = n; i > 0; i--)
        push(A->stack, i);
    
    towerOfHanoi(n, A, B, C);
    return 0;
}