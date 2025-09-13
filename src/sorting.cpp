#include "../include/heap.h"
#include "../include/sorting.h"
#include <cmath>
#include <iostream>

void insertionSort(std::vector<int>& v)
{
    for (int j = 1; j < v.size(); j++) {
        int key = v[j];
        int i = j - 1;

        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }

        v[i + 1] = key;
    }
}

void mergeSort(std::vector<int>& v, int start, int end)
{
    if (start < end) {
        int mid = floor((start + end) / 2);
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

void merge(std::vector<int>& v, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < n1; i++)
        left.push_back(v[start + i]);
    left.push_back(std::numeric_limits<int>::max());

    for (int i = 0; i < n2; i++) 
        right.push_back(v[mid + i + 1]);
    right.push_back(std::numeric_limits<int>::max());

    int i = 0;
    int j = 0;
    for (int k = start; k <= end; k++) {
        if (left[i] <= right[j])
            v[k] = left[i++];
        else
            v[k] = right[j++];
    }
}

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

void countingSort(std::vector<int>& v, std::vector<int>& w, int k)
{
    std::vector<int> c;
    for (int i = 0; i <= k; i++) {
        c.push_back(0);
    }

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
}
