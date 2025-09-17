#ifndef SORTING_H
#define SORTING_H

#include<vector>

template <typename T>
void insertionSort(std::vector<T>&);

void mergeSort(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);

void heapSort(std::vector<int>&);

void quickSort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);

void randomizedQuickSort(std::vector<int>&, int, int);
int randomizedPartition(std::vector<int>&, int, int);

void swap(std::vector<int>&, int, int);

void countingSort(std::vector<int>&, std::vector<int>&, int, int=0);

void radixSort(std::vector<int>&, std::vector<int>&, int);

void bucketSort(std::vector<float>&);

#endif // SORTING_H
