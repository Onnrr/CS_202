/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: Header for the BST class
*/

#include "BinaryNode.h"
#include <iostream>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


class BinarySearchTree {
    public:
        BinarySearchTree();
        BinarySearchTree(const int& rootItem);
        BinarySearchTree(const BinarySearchTree& tree);
        ~BinarySearchTree();

        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();

        bool add(int newEntry);
        bool remove(int anEntry);
        bool contains(int anEntry);
        void inorderTraverse();
        int count(int a, int b);
        int successor(int anEntry);
        int select(int anEntry);

        int getWidth();

        int findMin(BinaryNode *node);

    private:
        BinaryNode *root;
        void inorderPrintRecursive(BinaryNode* node);
        int countRecursive(BinaryNode* node, int a, int b);
        int getHeight(BinaryNode* node);
        int findIndex(BinaryNode* node);
        void destroyTree(BinaryNode *&treePtr);
};

#endif
