#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
public:
    std::vector<int> v;
    int heapSize;

    Heap(std::vector<int>&);
    void buildMaxHeap();
    void maxHeapify(int);
    int parent(int);
    int left(int);
    int right(int);
    void swap(int, int);
};

#endif // HEAP_H
