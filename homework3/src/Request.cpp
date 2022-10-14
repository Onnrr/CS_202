/*
* Title: Heaps, Priority Queues
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 3
* Description: Request class that stores request information
*/

#include "Request.h"
#include <iostream>
#include <string>
using namespace std;

Request::Request(int ID, int priority, int requestTime, int processTime) {
    id = ID;
    this->priority = priority;
    this->requestTime = requestTime;
    this->processTime = processTime;
    wait = 0;
}

Request::Request() {
    id = -1;
    priority = -1;
    requestTime = -1;
    processTime = -1;
}


Request::~Request() {}

int Request::getPriority() const {
    return priority;
}

int Request::getId() const {
    return id;
}

int Request::getRequestTime() const {
    return requestTime;
}

int Request::getProcessTime() const {
    return processTime;
}

int Request::getWait() const {
    return wait;
}

void Request::incrWait() {
    wait++;
}

bool Request::operator> (const Request &R ) {
    if (getPriority() > R.getPriority()) {
        return true;
    }
    if (getPriority() == R.getPriority()) {
        if (getRequestTime() < R.getRequestTime()) {
            return true;
        }
    }
    return false;
}

bool Request::operator< (const Request &R ) {
    if (getPriority() > R.getPriority()) {
        return false;
    }
    if (getPriority() == R.getPriority()) {
        if (getRequestTime() < R.getRequestTime()) {
            return false;
        }
    }
    return true;
}
