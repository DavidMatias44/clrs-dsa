#include "../include/algorithms.h"
#include "../include/sorting.h"

int minimum(const std::vector<int>& v)
{
    int min = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (min > v[i]) {
            min = v[i];
        }
    }
    return min;
}

int maximum(const std::vector<int>& v) 
{
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }
    return max;
}

int randomizedSelect(std::vector<int>& v, int start, int end, int index)
{
    if (start == end) {
        return v[start];
    }

    int q = randomizedPartition(v, start, end);
    int k = q - start + 1;
    if (index == k) {
        return v[k];
    } else if (index < k) {
        return randomizedSelect(v, start, q - 1, index);
    } else {
        return randomizedSelect(v, q + 1, end, index - k);
    }
}
