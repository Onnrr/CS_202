/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 1
* Description: 4 different sorting algorithms with their helper methods and a method to analyse their performance
*/

#include "sorting.h"
#include <iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;

        for ( ; (loc > 0) && ++compCount && (arr[loc-1] > nextItem); --loc) {
            arr[loc] = arr[loc-1];
            moveCount++;
        }

        arr[loc] = nextItem;
        moveCount++;
    }
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    bool sorted = false;

	for (int pass = 1; (pass < size) && !sorted; ++pass) {
      sorted = true;
      for (int index = 0; index < size-pass; ++index) {
         int nextIndex = index + 1;
         if (compCount++ && arr[index] > arr[nextIndex]) {
            swap(arr[index], arr[nextIndex]);
            moveCount += 3;
            sorted = false;
         }
      }
   }
}

void swap(int* arr, int index, int nextIndex) {
    int temp = arr[index];
    arr[index] = arr[nextIndex];
    arr[nextIndex] = temp;
}

void merge(int *arr, const int size, int &compCount, int &moveCount, int first, int mid, int last){

    int *temp = new int[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    while( ( first1 <= last1) && ( first2 <= last2 ) ){
        if( compCount++ && arr[first1] < arr[first2] ){
            temp[index] = arr[first1];
            first1++;
            moveCount++;
        }
        else{
            temp[index] = arr[first2];
            first2++;
            moveCount++;
        }
        index++;
    }

    while( ( first1 <= last1) ){
        temp[index] = arr[first1];
        moveCount++;
        index++;
        first1++;
    }

    while( ( first2 <= last2) ){
        temp[index] = arr[first2];
        moveCount++;
        index++;
        first2++;
    }

    for ( index = first; index <= last; index++){
        arr[index] = temp[index];
        moveCount++;
    }
    delete [] temp;
}

void mergesort(int *arr, const int size, int first, int last, int &compCount, int &moveCount){
    if ( first < last ) {
        int mid = (first + last)/2;

        mergesort(arr, size, first, mid, compCount, moveCount);

        mergesort(arr, size, mid + 1, last, compCount, moveCount);

        merge(arr, size, compCount, moveCount, first, mid, last);
   }
}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    mergesort( arr, size, 0, size - 1, compCount, moveCount);
}



void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    quickSort(arr, 0, size-1, compCount, moveCount);
}

void quickSort(int* theArray, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quickSort(theArray, first, pivotIndex-1, compCount, moveCount);
      quickSort(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}

void partition(int* theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {

    pivotIndex = first;
    int pivot = theArray[first]; // copy pivot
    moveCount++;
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        if (++compCount && theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1]);
            moveCount += 3;
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    moveCount += 3;
    pivotIndex = lastS1;
}


void displayArray(const int *arr, const int size) {
    cout << "{ ";

    int i;
    for (i = 0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[i] << " }";
}

void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
    }

    srand((unsigned) time(NULL));

    for (int index = 0; index < size/20; index++) {
        int i;
        int j;

        i = rand() % size;
        j = rand() % size;
        swap(arr1, i, j);
        swap(arr2, i, j);
        swap(arr3, i, j);
        swap(arr4, i, j);
    }
}

void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        arr1[i] = size-i-1;
        arr2[i] = size-i-1;
        arr3[i] = size-i-1;
        arr4[i] = size-i-1;
    }

    srand((unsigned) time(NULL));

    for (int index = 0; index < size/20; index++) {
        int i;
        int j;

        i = rand() % size;
        j = rand() % size;
        swap(arr1, i, j);
        swap(arr2, i, j);
        swap(arr3, i, j);
        swap(arr4, i, j);
    }
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        int random = rand() % 100000;
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
    }
}

void performanceAnalysis() {
    int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6, *arr7, *arr8, *arr9, *arr10, *arr11, *arr12, *arr13,*arr14, *arr15, *arr16;
    int *arr17, *arr18, *arr19, *arr20, *arr21, *arr22, *arr23, *arr24, *arr25, *arr26, *arr27, *arr28, *arr29,*arr30, *arr31, *arr32;
    int compCount;
    int moveCount;
    int time;;

    createRandomArrays(arr1, arr2, arr3, arr4, 5000);
    createRandomArrays(arr5, arr6, arr7, arr8, 10000);
    createRandomArrays(arr9, arr10, arr11, arr12, 15000);
    createRandomArrays(arr13, arr14, arr15, arr16, 20000);
    createRandomArrays(arr17, arr18, arr19, arr20, 25000);
    createRandomArrays(arr21, arr22, arr23, arr24, 30000);
    createRandomArrays(arr25, arr26, arr27, arr28, 35000);
    createRandomArrays(arr29, arr30, arr31, arr32, 40000);

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------- Analysis with random arrays --------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    clock_t startTime = clock();
    insertionSort(arr1, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr5, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr9, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr13, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr17, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr21, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr25, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr29, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms          " << compCount << "     " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr2, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr6, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr10, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr14, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr18, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr22, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr26, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr30, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr3, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "         " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr7, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr11, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr15, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr19, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr23, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr27, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr31, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms            " << compCount << "        " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr4, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "         " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr8, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr12, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr16, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr20, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr24, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr28, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr32, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;
    delete[] arr16;
    delete[] arr17;
    delete[] arr18;
    delete[] arr19;
    delete[] arr20;
    delete[] arr21;
    delete[] arr22;
    delete[] arr23;
    delete[] arr24;
    delete[] arr25;
    delete[] arr27;
    delete[] arr28;
    delete[] arr29;
    delete[] arr30;
    delete[] arr31;
    delete[] arr32;

    createAlmostSortedArrays(arr1, arr2, arr3, arr4, 5000);
    createAlmostSortedArrays(arr5, arr6, arr7, arr8, 10000);
    createAlmostSortedArrays(arr9, arr10, arr11, arr12, 15000);
    createAlmostSortedArrays(arr13, arr14, arr15, arr16, 20000);
    createAlmostSortedArrays(arr17, arr18, arr19, arr20, 25000);
    createAlmostSortedArrays(arr21, arr22, arr23, arr24, 30000);
    createAlmostSortedArrays(arr25, arr26, arr27, arr28, 35000);
    createAlmostSortedArrays(arr29, arr30, arr31, arr32, 40000);

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------- Analysis with almost sorted arrays -------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr1, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr5, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr9, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr13, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr17, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr21, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr25, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr29, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms           " << compCount << "      " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr2, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr6, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr10, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr14, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr18, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr22, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr26, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr30, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr3, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "         " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr7, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr11, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr15, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr19, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr23, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr27, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr31, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr4, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr8, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr12, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr16, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr20, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr24, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr28, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr32, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;
    delete[] arr16;
    delete[] arr17;
    delete[] arr18;
    delete[] arr19;
    delete[] arr20;
    delete[] arr21;
    delete[] arr22;
    delete[] arr23;
    delete[] arr24;
    delete[] arr25;
    delete[] arr27;
    delete[] arr28;
    delete[] arr29;
    delete[] arr30;
    delete[] arr31;
    delete[] arr32;

    createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, 5000);
    createAlmostUnsortedArrays(arr5, arr6, arr7, arr8, 10000);
    createAlmostUnsortedArrays(arr9, arr10, arr11, arr12, 15000);
    createAlmostUnsortedArrays(arr13, arr14, arr15, arr16, 20000);
    createAlmostUnsortedArrays(arr17, arr18, arr19, arr20, 25000);
    createAlmostUnsortedArrays(arr21, arr22, arr23, arr24, 30000);
    createAlmostUnsortedArrays(arr25, arr26, arr27, arr28, 35000);
    createAlmostUnsortedArrays(arr29, arr30, arr31, arr32, 40000);


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------- Analysis with almost unsorted arrays -------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr1, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms            " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr5, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr9, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr13, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr17, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms           " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr21, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr25, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    insertionSort(arr29, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms          " << compCount << "     " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr2, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr6, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms           " << compCount << "      " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr10, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr14, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr18, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr22, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr26, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms          " << compCount << "     " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    bubbleSort(arr30, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms          " << compCount << "     " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr3, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "         " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr7, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr11, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr15, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr19, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr23, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr27, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms            " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    mergeSort(arr31, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms            " << compCount << "        " << moveCount << endl;


    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array size     Elapsed Time     compCount     moveCount" << endl;
    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr4, 5000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "5000           " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr8, 10000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "10000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr12, 15000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "15000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr16, 20000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000          " << time << " ms             " << compCount << "        " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr20, 25000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "25000          " << time << " ms             " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr24, 30000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "30000          " << time << " ms             " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr28, 35000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "35000          " << time << " ms            " << compCount << "       " << moveCount << endl;

    compCount = 0;
    moveCount = 0;
    time = 0;
    startTime = clock();
    quickSort(arr32, 40000, compCount, moveCount);
    time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000          " << time << " ms           " << compCount << "      " << moveCount << endl;


}
