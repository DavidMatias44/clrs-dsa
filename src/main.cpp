#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"

int main(void)
{
    std::vector<int> v = {31, 41, 59, 26, 41, 58};
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    quickSort(v, 0, v.size() - 1);
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
