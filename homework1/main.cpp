/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 1
* Description: This code creates an array and sorts with different algorithms and analyses their performance
*/

#include <iostream>
#include "sorting.h"

using namespace std;

int main()
{

    int initialArr[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int arr[16];

    int arrSize = 16;
    int compCount = 0;
    int moveCount = 0;

    for (int i = 0; i < arrSize; i++) {
        arr[i] = initialArr[i];
    }

    cout << "Initial Array" << endl;
    displayArray(arr, arrSize);
    cout << endl;

    insertionSort(arr, arrSize, compCount, moveCount);
    cout << endl;
    cout << "-------- Insertion Sort -------" << endl;
    displayArray(arr, arrSize);
    cout << endl;
    cout << "Number of key comparisons : " << compCount << endl;
    cout << "Number of data moves : " << moveCount << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < arrSize; i++) {
        arr[i] = initialArr[i];
    }
    compCount = 0;
    moveCount = 0;

    bubbleSort(arr, arrSize, compCount, moveCount);
    cout << endl;
    cout << "-------- Bubble Sort -------" << endl;
    displayArray(arr, arrSize);
    cout << endl;
    cout << "Number of key comparisons : " << compCount << endl;
    cout << "Number of data moves : " << moveCount << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < arrSize; i++) {
        arr[i] = initialArr[i];
    }
    compCount = 0;
    moveCount = 0;

    mergeSort(arr, arrSize,compCount,moveCount);
    cout << endl;
    cout << "-------- Merge Sort -------" << endl;
    displayArray(arr, arrSize);
    cout << endl;
    cout << "Number of key comparisons : " << compCount << endl;
    cout << "Number of data moves : " << moveCount << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < arrSize; i++) {
        arr[i] = initialArr[i];
    }
    compCount = 0;
    moveCount = 0;

    quickSort(arr, arrSize, compCount, moveCount);
    cout << endl;
    cout << "-------- Quick Sort -------" << endl;
    displayArray(arr, arrSize);
    cout << endl;
    cout << "Number of key comparisons : " << compCount << endl;
    cout << "Number of data moves : " << moveCount << endl;
    cout << "---------------------------" << endl;

    cout << endl;
    performanceAnalysis();

    //cout << endl;
    //cout << "After instertion sort";
    //cout << endl;
    //cout << compCount << endl;
    //cout << moveCount << endl;
    //displayArray(arr, arrSize);


    return 0;
}
