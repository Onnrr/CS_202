/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: Header for analyze class
*/

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <cstdlib>

#ifndef ANALYZE_H
#define ANALYZE_H



    void analyzeBST();
    void createRandomArray(int *&arr1, int size);
    void swap(int *a, int *b);
    void shuffle(int *&arr, int size);

#endif // ANALYZE_H
