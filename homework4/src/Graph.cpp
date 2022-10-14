/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: graph class with required methods
*/

#include "Graph.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(int numberOfAirports) {
    size = numberOfAirports;
    lists = new LinkedList*[size];
    for (int i = 0; i < size; i++) {
        lists[i] = new LinkedList();
    }
}

Graph::~Graph() {
    for (int i = 0; i < size; i++) {
        delete lists[i];
    }
    delete[] lists;
}

bool Graph::add(int departure, int arrival, int duration) {
    if (departure > size || arrival > size) {
        return false;
    }
    lists[departure]->add(arrival,duration);
    lists[arrival]->add(departure,duration);

    cout << "Inserted a new flight between " << departure << " and " << arrival << "." << endl;

    cout << "  The number of flights from " << departure << " is " << lists[departure]->getLength() << endl;
    return true;
}

void Graph::list(int airport) {
    if (airport > size) {
        return;
    }
    lists[airport]->list(airport);
}

string Graph::shortestPath(int start, int end, int& duration) {
    int* adjacents = new int[size];
    int* durations = new int[size];
    double* shortestPaths = new double[size];
    int* visited = new int[size];
    int visitedSize = 0;

    for (int i = 0; i < size; i++) {
        if (i == start) {
            shortestPaths[i] = 0;
        }
        else {
            shortestPaths[i] = std::numeric_limits<double>::infinity();
        }
    }

    string* results = new string[size];
    for (int i = 0; i < size; i++) {
        results[i] = "";
    }

    int numberOfAdjacents = lists[start]->getAdjacents(adjacents, durations);

    for (int i = 0; i < numberOfAdjacents; i++) {
        shortestPaths[adjacents[i]] = durations[i];

        stringstream ss1, ss2, ss3;
        ss1 << start;
        ss2 << adjacents[i];
        ss3 << durations[i];
        results[adjacents[i]] = "\n  " + ss1.str() + " to " + ss2.str() + " with a duration of " + ss3.str();
    }

    visited[0] = start;
    visitedSize++;

    bool no = false;
    for (int i = 1; i < size; i++) {
        int index = 0;
        double min = std::numeric_limits<double>::infinity();
        for (int m = 0; m < size; m++) {
            for (int k = 0; k < visitedSize; k++) {
                if (visited[k] == m) {
                    no = true;
                }
            }
            if (!no && shortestPaths[m] < min) {
                index = m;
                min = shortestPaths[m];
            }
            no = false;
        }

        visited[visitedSize] = index;
        visitedSize++;

        if (index != start) {
            numberOfAdjacents = lists[index]->getAdjacents(adjacents, durations);
            for (int j = 0; j < numberOfAdjacents; j++) {
                if (shortestPaths[index] + durations[j] < shortestPaths[adjacents[j]]) {
                    shortestPaths[adjacents[j]] = shortestPaths[index] + durations[j];
                    stringstream ss1, ss2, ss3;
                    ss1 << index;
                    ss2 << adjacents[j];
                    ss3 << durations[j];
                    results[adjacents[j]] = results[index] + "\n  " + ss1.str() + " to " + ss2.str() + " with a duration of " + ss3.str();
                }

            }
        }
    }
    duration = shortestPaths[end];
    delete[] durations;
    delete[] adjacents;
    delete[] shortestPaths;
    delete[] visited;
    string final = results[end];
    delete[] results;
    return final;
}

void Graph::minimize(int& oldCost, int& newCost) {
    int heapSize = size * (size-1) / 2;
    Heap queue(heapSize);
    int* visited = new int[size];
    int visitedSize = 0;
    int index = 0;
    int sum = 0;
    int* adjacents;
    int* durations;

    for (int i = 0; i < size; i++) {
        sum += lists[i]->getSum();
    }
    oldCost = sum / 2;
    Graph *newGraph = new Graph(size);
    visited[index] = 1;
    visitedSize++;

    while (visitedSize != size) {

        adjacents = new int[size];
        durations = new int[size];

        int adjacentSize = lists[index]->getAdjacents(adjacents, durations);
        for (int i = 0; i < adjacentSize; i++) {
            if (visited[adjacents[i]] != 1) {
                Flight f(index, adjacents[i], durations[i]);
                queue.heapInsert(f);
            }
        }

        Flight f;
        queue.heapDelete(f);

        while (visited[f.getArrival()] == 1 && !queue.heapIsEmpty()) {
            queue.heapDelete(f);
        }

        newGraph->add(f.getDeparture(),f.getArrival(),f.getDuration());

        visited[index] = 1;
        visitedSize++;
        index = f.getArrival();
    }
    for (int i = 0; i < size; i++) {
        delete lists[i];
        lists[i] = newGraph->lists[i];
    }
    delete newGraph;

    sum = 0;

    for (int i = 0; i < size; i++) {
        sum += lists[i]->getSum();
    }
    newCost = sum / 2;
    delete[] adjacents;
    delete[] durations;
    delete[] visited;
}




