/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 1
* Description: Header of sorting algorithms and helper methods
*/

#ifndef SORTING_H
#define SORTING_H
using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void partition(int* theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void quickSort(int* theArray, int first, int last, int &compCount, int &moveCount);
void swap(int* arr, int index, int nextIndex);
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void mergesort(int *arr, const int size, int first, int last, int &compCount, int &moveCount);

void performanceAnalysis();

#endif
