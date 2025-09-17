#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"

int main(void)
{
    std::vector<int> v = { 936, 220, 132, 421, 733, 824 };
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::vector<int> sol;
    radixSort(v, sol, 3);
    for (auto& e : sol) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
