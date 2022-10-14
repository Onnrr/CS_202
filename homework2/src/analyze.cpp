/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: Class to analyze the efficiency of BST
*/

#include "analyze.h"
#include <iostream>
#include <cstdlib>

#include "BinarySearchTree.h"
#include "BinaryNode.h"
using namespace std;

void analyzeBST() {
    int *arr;
    int size = 10000;
    createRandomArray(arr, size);

    BinarySearchTree *BST = new BinarySearchTree();
    cout << "----------------------------------------------" << endl;
    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        BST->add(arr[i]);

        if ((i+1) % 100 == 0) {
            cout << BST->getNumberOfNodes() << "  " << BST->getHeight() << endl;
        }
    }
    shuffle(arr, size);
    cout << "----------------------------------------------" << endl;
    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        BST->remove(arr[i]);
        if ((i+1) % 100 == 0) {
            cout << BST->getNumberOfNodes() << "  " << BST->getHeight() << endl;
        }
    }

    delete[] arr;
    delete BST;
}

void createRandomArray(int *&arr1, int size) {
    arr1 = new int[size];

    for (int i = 0; i < size; i++) {
        int random = rand() % 1000000000000;
        arr1[i] = random;
    }
}

void shuffle(int *&arr, int size) {
    //srand (time(NULL));
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
