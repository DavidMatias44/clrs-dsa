#include <iostream>
#include "../include/heap.h"

Heap::Heap(std::vector<int>& v) : v(v)
{
    buildMaxHeap();
}

void Heap::buildMaxHeap()
{
    heapSize = v.size();

    for (int i = v.size()/2 - 1; i >= 0; i--) {
        maxHeapify(i);
    }
}

void Heap::maxHeapify(int index)
{
    int l = left(index);
    int r = right(index);

    int largest;
    if (l < heapSize && v[l] > v[index])
        largest = l;
    else
        largest = index;
    if (r < heapSize && v[r] > v[largest]) 
        largest = r;

    if (largest != index) {
        swap(largest, index);
        maxHeapify(largest);
    }
}

int Heap::left(int index)
{
    return 2 * index + 1;
}

int Heap::right(int index)
{
    return 2 * index + 2;
}

void Heap::swap(int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
