#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"
#include "../include/algorithms.h"

int main(void)
{
    std::vector<int> v = { 534, 5, 15, 54, 25, 18, 12, 3, 6 };
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "minimum: " << minimum(v) << std::endl;
    std::cout << "maximum: " << maximum(v) << std::endl;
    std::cout << "3th smaller: " << randomizedSelect(v, 0, v.size() - 1, 3) << std::endl;;

    return 0;
}
