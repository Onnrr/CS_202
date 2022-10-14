/*
* Title: Heaps, Priority Queues
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 3
* Description: Header for heap class
*/

#ifndef HEAP_H
#define HEAP_H

#include "Request.h"
typedef Request HeapItemType;

class Heap {
public:
	Heap(int maxSize);
	~Heap();
	bool heapIsEmpty() const;
	void heapInsert(const Request& newItem);
	void heapDelete(Request& rootItem);
	Request* getItems();

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	Request* items;	// array of heap items
	int          size;            	// number of heap items
	int maxSize;
};


#endif // HEAP_H
