/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: Class for nodes in the BST
*/

#include <iostream>

#include "BinaryNode.h"
#include <iostream>
using namespace std;


BinaryNode::BinaryNode(int nodeItem) {
    size = 0;
    item = nodeItem;
    parent = NULL;
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode(){}

void BinaryNode::incrSize() {
    size++;
}

void BinaryNode::decrSize() {
    size--;
}
