#include "../../include/sorting/mergeSort.h"
#include "../../include/utils.h"

int main(void)
{
    std::cout << std::endl;
    std::vector<int> integerVector = { 53, 212, 28, 14, 1, 58 };
    std::cout << "       Integer vector: ";
    printVector(integerVector);
    std::cout << "Sorted integer vector: ";
    mergeSort(integerVector, 0, integerVector.size() - 1);
    printVector(integerVector);

    std::cout << std::endl;
    std::vector<float> floatVector = { 4.1, 52.5, 97.2, 5.7, 12.4, 8.4 };
    std::cout << "       Float vector: ";
    printVector(floatVector);
    std::cout << "Sorted float vector: ";
    mergeSort(floatVector, 0, floatVector.size() - 1);
    printVector(floatVector);
    std::cout << std::endl;

    return 0;
}