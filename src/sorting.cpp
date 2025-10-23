#include "../include/heap.h"
#include "../include/sorting.h"
#include "insertionSort.h"
#include <cmath>
#include <iostream>

void heapSort(std::vector<int>& v)
{
    Heap heap(v);

    for (int i = heap.heapSize - 1; i >= 1; i--) {
        heap.swap(0, i);
        heap.heapSize--;
        heap.maxHeapify(0);
    }

    v = heap.v;
}

void quickSort(std::vector<int>& v, int start, int end)
{
    if (start < end) {
        int q = partition(v, start, end);
        quickSort(v, start, q - 1);
        quickSort(v, q + 1, end);
    }
}

int partition(std::vector<int>& v, int start, int end)
{
    int x = v[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (v[j] < x) {
            swap(v, ++i, j);
        }
    }
    swap(v, ++i, end);

    return i;
}

void randomizedQuickSort(std::vector<int>& v, int start, int end)
{
    if (start < end) {
        int q = randomizedPartition(v, start, end);
        randomizedQuickSort(v, start, q - 1);
        randomizedQuickSort(v, q + 1, end);
    }
}

int randomizedPartition(std::vector<int>& v, int start, int end)
{
    int i = rand() % (end + 1);
    swap(v, i, end);
    return partition(v, start, end);
}

void swap(std::vector<int>& v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void countingSort(std::vector<int>& v, std::vector<int>& w, int k, int e)
{   
    std::vector<int> c;
    for (int i = 0; i <= k; i++) {
        c.push_back(0);
    }

    if (e < 1) {
        for (int j = 0; j < v.size(); j++) {
            c[v[j]]++;
            w.push_back(0);
        }
        
        for (int i = 1; i <= k; i++) {
            c[i] = c[i] + c[i - 1];
        }
        
        for (int j = v.size() - 1; j >= 0; j--) {
            w[ c[v[j]] - 1 ] = v[j];
            c[v[j]]--;
        }

        return;
    }

    for (int j = 0; j < v.size(); j++) {
        c[ (v[j] / e) % k ]++;
        if (w.size() < v.size())
            w.push_back(0);
    }

    for (int i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }

    for (int j = v.size() - 1; j >= 0; j--) {
        int pos = (v[j] / e) % k;
        w[ c[pos] - 1 ] = v[j];
        c[pos]--;
    }
}

void radixSort(std::vector<int>& v, std::vector<int>& w, int d)
{
    for (int i = 1; i < pow(10, d); i *= 10) {
        countingSort(v, w, 10, i);
        
        for (int i = 0; i < v.size(); i++) {
            v[i] = w[i];
        }
    }
}

void bucketSort(std::vector<float>& v)
{
    std::vector<std::vector<float>> w {0};
    int n = v.size();

    for (int i = 0; i < n; i++) {
        w.emplace_back();
    }

    for (int i =0; i < n; i++) {
        w[ floor(n * v[i]) ].push_back(v[i]);
    }

    v.clear();
    for (int i = 0; i < n; i++) {
        insertionSort(w[i]);
        for (auto& e : w[i]) {
            v.push_back(e);
        }
    }
}
