#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

template <typename T>
void insertionSort(std::vector<T>& v)
{
    for (size_t j = 1; j < v.size(); j++) {
        T key = v[j];
        int i = j - 1;

        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }

        v[i + 1] = key;
    }
}

#endif // INSERTIONSORT_H
