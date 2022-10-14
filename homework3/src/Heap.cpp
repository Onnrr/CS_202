/*
* Title: Heaps, Priority Queues
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 3
* Description: Heap class for priority queue
*/

#include "Heap.h"
#include <iostream>
#include <string>
using namespace std;

Heap::Heap(int maxSize) : size(0) {
    items = new Request[maxSize];
    this->maxSize = maxSize;
}


bool Heap::heapIsEmpty() const {
	return (size == 0);
}


Heap::~Heap() {
    delete[] items;
}

Request* Heap::getItems() {
    return items;
}

void Heap::heapInsert(const Request& newItem) {
	if (size >= maxSize)
		return;

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place] > items[parent]) ) {
		Request temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

void Heap::heapDelete(Request&rootItem) {
	if (heapIsEmpty())
		return;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}

void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild] > items[child]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root] < items[child] ) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}
