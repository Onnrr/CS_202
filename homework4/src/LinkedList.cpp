/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: linked list class
*/

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = NULL;
    size = 0;
    visited = false;
}

LinkedList::~LinkedList() {
    ListNode *temp = NULL;
    for (ListNode *ptr = head; ptr != NULL; ptr = temp) {
        temp = ptr->next;
        delete ptr;
    }
}

bool LinkedList::add(int airport, int nextDuration) {
    if (isEmpty()) {
        head = new ListNode;
        head->data = airport;
        head->next = NULL;
        head->duration = nextDuration;
        size++;
        return true;
    }

    ListNode *newNode = new ListNode;
    newNode->data = airport;
    newNode->next = NULL;
    newNode->duration = nextDuration;

    newNode->next = head;
    head = newNode;
    size++;
    return true;
}

void LinkedList::list(int airport) const {
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << "  " << airport << " to " << ptr->data << " with a duration " << ptr->duration << endl;
        ptr = ptr->next;
    }
    cout << "  The number of flights is " << getLength() << endl;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

int LinkedList::getLength() const {
    return size;
}

int LinkedList::getAdjacents(int* adjacents, int* durations) {
    ListNode *ptr = head;
    int unvisitedSize = 0;
    for (int i = 0; i < size; i++) {
        adjacents[unvisitedSize] = ptr->data;
        durations[unvisitedSize] = ptr->duration;
        unvisitedSize++;

        ptr = ptr->next;
    }

    return unvisitedSize;
}

void LinkedList::print() {
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
        cout << ptr->data << endl;
    }
}

int LinkedList::getSum() {
    int sum = 0;
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
        sum += ptr->duration;
    }
    return sum;
}

LinkedList& LinkedList::operator= (const LinkedList& l)
{
    for (ListNode *ptr = l.head; ptr != NULL; ptr = ptr->next) {
        add(ptr->data, ptr->duration);
    }
    return *this;
}

