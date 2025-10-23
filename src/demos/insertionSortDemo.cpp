#include "../../include/insertionSort.h"
#include "../../include/utils.h"

int main(void)
{
    std::cout << std::endl;
    std::vector<int> integerVector = { 53, 212, 28, 14, 1, 58 };
    std::cout << "       Integer vector: ";
    printVector(integerVector);
    std::cout << "Sorted integer vector: ";
    insertionSort(integerVector);
    printVector(integerVector);

    std::cout << std::endl;
    std::vector<float> floatVector = { 4.1, 52.5, 97.2, 5.7, 12.4, 8.4 };
    std::cout << "       Float vector: ";
    printVector(floatVector);
    std::cout << "Sorted float vector: ";
    insertionSort(floatVector);
    printVector(floatVector);
    std::cout << std::endl;

    return 0;
}
