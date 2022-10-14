/*
* Title: Trees
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 2
* Description: BST class with necessary methods
*/

#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::BinarySearchTree(const int& rootItem) {
    BinaryNode node(rootItem);
    root = &node;
}

BinarySearchTree::~BinarySearchTree(){
    destroyTree(root);
}

bool BinarySearchTree::add(int newEntry) {
    if (contains(newEntry)) {
        return false;
    }

    if (root == NULL) {
        BinaryNode *node = new BinaryNode(newEntry);
        root = node;
        root->incrSize();
        return true;
    }

    BinaryNode *currentNode = root;
    while (currentNode != NULL) {
        if (newEntry < currentNode->item) {
            currentNode->incrSize();
            if (currentNode->left == NULL) {
                BinaryNode *node = new BinaryNode(newEntry);
                currentNode->left = node;
                node->parent = currentNode;
                node->incrSize();
                return true;
            }

            currentNode = currentNode->left;
        }
        if (newEntry > currentNode->item) {
            currentNode->incrSize();
            if (currentNode->right == NULL) {
                BinaryNode *node = new BinaryNode(newEntry);
                currentNode->right = node;
                node->parent = currentNode;
                node->incrSize();
                return true;
            }

            currentNode = currentNode->right;
        }
    }
}

bool BinarySearchTree::contains(int anEntry) {
    BinaryNode *currentNode = root;

    while (currentNode != NULL) {
        if (anEntry == currentNode->item) {
            return true;
        }
        if (anEntry < currentNode->item) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }

    return false;
}

bool BinarySearchTree::remove(int anEntry) {
    if (!contains(anEntry)) {
        return false;
    }

    if (getNumberOfNodes() == 1) {
        delete root;
        root = NULL;
        return true;
    }
    BinaryNode *currentNode = root;
    while (currentNode != NULL) {
        if (anEntry < currentNode->item) {
            currentNode->decrSize();
            currentNode = currentNode->left;
        }
        else if (anEntry > currentNode->item) {
            currentNode->decrSize();
            currentNode = currentNode->right;
        }
        else {
            if (currentNode->parent == NULL) {
                if (currentNode->left == NULL) {
                    currentNode->right->parent = NULL;
                    root = currentNode->right;
                    currentNode->left = NULL;
                    currentNode->right = NULL;
                    currentNode->parent = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    return true;
                }
                else if (currentNode->right == NULL) {
                    currentNode->left->parent = NULL;
                    root = currentNode->left;
                    currentNode->left = NULL;
                    currentNode->right = NULL;
                    currentNode->parent = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    return true;
                }
                else {
                    int temp = findMin(currentNode->right);
                    remove(temp);
                    currentNode->item = temp;
                    return true;
                }
            }
            if (currentNode->left == NULL && currentNode->right == NULL) {
                BinaryNode *temp = currentNode->parent;
                if (currentNode->parent->left == currentNode) {
                    currentNode->parent->left = NULL;
                    currentNode->left = NULL;
                    currentNode->right = NULL;
                    currentNode->parent = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    return true;
                }
                currentNode->parent->right = NULL;
                currentNode->left = NULL;
                currentNode->right = NULL;
                currentNode->parent = NULL;
                delete currentNode;
                currentNode = NULL;
                return true;
            }
            else if (currentNode->left != NULL && currentNode->right != NULL) {
                // :(
                int temp = findMin(currentNode->right);
                for (BinaryNode* tempNode = currentNode->parent; tempNode != NULL; tempNode = tempNode->parent) {
                    tempNode->incrSize();
                }
                remove(temp);
                currentNode->item = temp;
                return true;
            }
            else {
                if (currentNode->parent->left == currentNode) {
                    if (currentNode->left != NULL) {
                        currentNode->parent->left = currentNode->left;
                        currentNode->left->parent = currentNode->parent;
                        currentNode->left = NULL;
                        currentNode->right = NULL;
                        currentNode->parent = NULL;
                        delete currentNode;
                        currentNode = NULL;
                        return true;
                    }
                    currentNode->parent->left = currentNode->right;
                    currentNode->right->parent = currentNode->parent;
                    currentNode->left = NULL;
                    currentNode->right = NULL;
                    currentNode->parent = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    return true;
                }
                if (currentNode->parent->right == currentNode) {

                    if (currentNode->left != NULL) {
                        currentNode->parent->right = currentNode->left;
                        currentNode->left->parent = currentNode->parent;
                        currentNode->left = NULL;
                        currentNode->right = NULL;
                        currentNode->parent = NULL;
                        delete currentNode;
                        currentNode = NULL;
                        return true;
                    }

                    currentNode->parent->right = currentNode->right;
                    currentNode->right->parent = currentNode->parent;
                    currentNode->left = NULL;
                    currentNode->right = NULL;
                    currentNode->parent = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    return true;
                }
            }
        }
    }
}


int BinarySearchTree::findMin(BinaryNode *node) {
    while(node->left != NULL) {
        node = node->left;
    }
    return node->item;
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

int BinarySearchTree::getHeight() {
    return getHeight(root);
}

int BinarySearchTree::getHeight(BinaryNode* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int BinarySearchTree::getNumberOfNodes() {
    if (root == NULL) {
        return 0;
    }
    return root->size;
}

void BinarySearchTree::inorderTraverse() {
    inorderPrintRecursive(root);
}

void BinarySearchTree::inorderPrintRecursive(BinaryNode* node) {
    if (node != NULL) {
        inorderPrintRecursive(node->left);
        cout << "Item of current node : " << node->item << endl;
        inorderPrintRecursive(node->right);

    }
}

int BinarySearchTree::count(int a, int b) {
    return countRecursive(root, a, b);
}

int BinarySearchTree::countRecursive(BinaryNode* node, int a, int b) {
    if (node == NULL) {
        return 0;
    }
    if (node->item >= a && node->item <= b) {
        return 1 + countRecursive(node->left, a, b) + countRecursive(node->right, a, b);
    }
    if (node->item < a) {
        return countRecursive(node->right, a, b);
    }
    return countRecursive(node->left, a, b);
}

int BinarySearchTree::successor(int anEntry) {
    if (!contains(anEntry)) {
        return -1;
    }
    BinaryNode *node = root;
    while (node != NULL) {
        if (node->item == anEntry) {
            if (node->right != NULL) {
                return findMin(node->right);
            }
            BinaryNode *pNode = node->parent;
            while (pNode != NULL && node == pNode->right) {
                node = pNode;
                pNode = pNode->parent;
            }
            if (pNode == NULL) {
                return -2;
            }
            return pNode->item;
        }
        else if (anEntry < node->item) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
}


int BinarySearchTree::select(int anEntry) {
    if (!contains(anEntry)) {
        return -1;
    }
    BinaryNode *node = root;
    int index = 0;
    while (node != NULL) {
        if (node->item == anEntry) {
            return findIndex(node);
        }
        else if (anEntry < node->item) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
}

int BinarySearchTree::findIndex(BinaryNode *node) {
    if (node->left != NULL && node->parent != NULL && node == node->parent->right) {
        return 1 + node->left->size + findIndex(node->parent);
    }
    if (node->left == NULL && node->parent != NULL && node == node->parent->right) {
        return 1 + findIndex(node->parent);
    }
    if (node->left != NULL && node->parent == NULL) {
        return node->left->size;
    }
    if (node->left != NULL && node->parent != NULL && node == node->parent->left) {
        BinaryNode *p = node->parent;
        while (p->parent != NULL && p == p->parent->left) {
            p = p->parent;
        }
        if (p->parent == NULL) {
            return node->left->size;
        }
        return 1 + findIndex(p->parent) + node->left->size;
    }
    if (node->left == NULL && node->parent != NULL && node == node->parent->left) {
        BinaryNode *p = node->parent;
        while (p->parent != NULL && p == p->parent->left) {
            p = p->parent;
        }
        if (p->parent == NULL) {
            return 0;
        }
        return 1 + findIndex(p->parent);
    }
    return 0;

}

void BinarySearchTree::destroyTree(BinaryNode *&treePtr) {
		if (treePtr != NULL) {
			destroyTree(treePtr->left);
			destroyTree(treePtr->right);
			delete treePtr;
			treePtr = NULL;
		}
}
