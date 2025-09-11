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

    PriorityQueue pq(v);

    pq.print();
    std::cout << std::endl;

    int pqMax = pq.extractMax();
    std::cout << "max: " << pqMax << std::endl;
    pq.print();
    std::cout << std::endl;

    pq.insert(112);
    pq.print();
    std::cout << std::endl;

    pq.insert(28);
    pq.print();
    std::cout << std::endl;

    pqMax = pq.extractMax();
    std::cout << "max: " << pqMax << std::endl;
    pq.print();
    std::cout << std::endl;

    return 0;
}
