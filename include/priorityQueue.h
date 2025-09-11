#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "heap.h"

class PriorityQueue : public Heap
{
public:
    PriorityQueue(std::vector<int>&);
    int maximum();
    int extractMax();
    void increaseKey(int, int);
    void insert(int);
    void print();
};

#endif // PRIORITYQUEUE_H
