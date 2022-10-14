/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: header for graph
*/

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Heap.h"
#include "Flight.h"
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H


class Graph {
    public:
        Graph(int numberOfAirports);
        ~Graph();

        bool add(int departure, int arrival, int duration);
        void list(int airport);
        string shortestPath(int start, int end, int& duration);
        void minimize(int& oldCost, int& newCost);

    private:
        LinkedList** lists;
        int size;
};

#endif // GRAPH_H
