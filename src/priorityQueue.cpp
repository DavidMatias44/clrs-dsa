#include "../include/priorityQueue.h"
#include <iostream>
#include <cmath>

PriorityQueue::PriorityQueue(std::vector<int>& v) : Heap(v)
{ }

int PriorityQueue::maximum()
{
    return v[0];
}

int PriorityQueue::extractMax()
{
    if (heapSize < 1) {
        std::cout << "Error: heap underflow";
    }

    int max = v[0];
    v[0] = v[--heapSize];
    maxHeapify(0);

    return max;
}

void PriorityQueue::increaseKey(int index, int key)
{
    if (key < v[index]) {
        std::cout << "Error: new key is smaller than current key";
    }

    v[index] = key;
    while (index > 0 && v[parent(index)] < v[index]) {
        swap(index, parent(index));
        index = parent(index);
    }
}

void PriorityQueue::insert(int key)
{
    if (heapSize == v.size()) {
        v.push_back(std::numeric_limits<int>::min());
    } else {
        v[heapSize] = std::numeric_limits<int>::min();
    }
    increaseKey(heapSize, key);
    heapSize++;
}

void PriorityQueue::print()
{
    for (int i = 0; i < heapSize; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
