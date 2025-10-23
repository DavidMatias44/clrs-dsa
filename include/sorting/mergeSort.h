#ifndef MERGESORT_H
#define MERGESROT_H

#include <vector>
#include <limits>
#include <cmath>


template <typename T>
void merge(std::vector<T>& v, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<T> left;
    std::vector<T> right;

    for (int i = 0; i < n1; i++)
        left.push_back(v[start + i]);
    left.push_back(std::numeric_limits<T>::max());

    for (int i = 0; i < n2; i++) 
        right.push_back(v[mid + i + 1]);
    right.push_back(std::numeric_limits<T>::max());

    int i = 0;
    int j = 0;
    for (int k = start; k <= end; k++) {
        if (left[i] <= right[j])
            v[k] = left[i++];
        else
            v[k] = right[j++];
    }
}
    
template <typename T>
void mergeSort(std::vector<T>& v, int start, int end)
{
    if (start < end) {
        int mid = floor((start + end) / 2);
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}
    
#endif // MERGESORT_H
    