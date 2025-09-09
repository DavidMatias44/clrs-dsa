#include <iostream>
#include "../include/sorting.h"

int main(void)
{
    std::vector<int> v = {31, 41, 59, 26, 41, 58};
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // insertionSort(v);
    // for (auto& e : v) {
    //     std::cout << e << " ";
    // }
    // std::cout << std::endl;

    // mergeSort(v, 0, v.size() - 1);
    // for (auto& e : v) {
    //     std::cout << e << " ";
    // }
    // std::cout << std::endl;

    heapSort(v);
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
