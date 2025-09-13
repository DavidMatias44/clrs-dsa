#ifndef SORTING_H
#define SORTING_H

#include<vector>

void insertionSort(std::vector<int>&);

void mergeSort(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);

void heapSort(std::vector<int>&);

void quickSort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);

void randomizedQuickSort(std::vector<int>&, int, int);
int randomizedPartition(std::vector<int>&, int, int);

void swap(std::vector<int>&, int, int);

#endif // SORTING_H
