// sample program

#include <stdio.h>

#define HASH_TABLE_SIZE 10

int hash(int key) {
    return key % HASH_TABLE_SIZE;
}

int main() {
    int data[] = {12, 25, 6, 38, 17, 52, 33};
    int i;

    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        int hashed_value = hash(data[i]);
        printf("Data: %d, Hashed Value: %d\n", data[i], hashed_value);
    }

    return 0;
}
