#include "../include/sorting.h"

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
