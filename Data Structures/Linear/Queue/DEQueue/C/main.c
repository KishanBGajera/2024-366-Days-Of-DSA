#include "dequeue.h"

int main() {
    Dequeue* dq = getDequeue(10);

    for (int i = 1; i <= 5; ++i) {
        DQ_EnqueueFront(dq, i);
    }

    for (int i = 6; i <= 10; ++i) {
        DQ_EnqueueRear(dq, i);
    }
    printDQ(dq);

    for (int i = 1; i <= 3; ++i) {
        DQ_dequeueFront(dq);
    }
    printDQ(dq);

    for (int i = 1; i <= 2; ++i) {
        DQ_dequeueRear(dq);
    }

    printDQ(dq);
    freeDQ(dq);

    return 0;
}
