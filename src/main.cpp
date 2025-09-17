#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"

int main(void)
{
    std::vector<float> v = { 0.838, 0.936, 0.220, 0.132, 0.421, 0.033, 0.824, 0.321, 0.564, 0.422 };
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    bucketSort(v);
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
