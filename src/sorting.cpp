#include "../include/sorting.h"
#include <cmath>

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
