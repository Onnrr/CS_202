/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: header for linked list
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

using namespace std;

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool add(int airport, int nextDuration);
    void list(int airport) const;
    int getAdjacents(int* adjacents,int* durations);
    void print();
    int getSum();
    LinkedList& operator= (const LinkedList& l);
private:
    struct ListNode{
        int data;
        int duration;
        ListNode* next;
    };
    int size;
    ListNode* head;
    bool visited;
};

#endif
