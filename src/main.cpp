#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"
#include "../include/algorithms.h"
#include "../include/stack.h"
#include "../include/queue.h"

int main(void)
{
    Queue q(4);

    q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
    q.print();
    q.enqueue(5);
    q.print();

    q.dequeue();
    q.print();

    q.enqueue(6);
    q.print();
    q.enqueue(7);
    q.print();

    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();

    return 0;
}
