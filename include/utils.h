#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T>& v)
{
    std::cout << "[ ";
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

#endif // UTILS_H
