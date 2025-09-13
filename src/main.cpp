#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"

int main(void)
{
    std::vector<int> v = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::vector<int> sol;
    countingSort(v, sol, 6);
    for (auto& e : sol) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
