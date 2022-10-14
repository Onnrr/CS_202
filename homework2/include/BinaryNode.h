/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: Header for binary node class
*/

#include <iostream>

#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
    public:
        BinaryNode(int nodeItem);
        ~BinaryNode();

    private:
        int item;
        int size;
        BinaryNode *parent;
        BinaryNode *left;
        BinaryNode *right;

        void incrSize();
        void decrSize();

    friend class BinarySearchTree;

};

#endif
