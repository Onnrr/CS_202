/*
* Title: Heaps, Priority Queues
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 3
* Description: Header for request class
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>
using namespace std;

class Request {

public:
    Request(int ID, int priority, int requestTime, int processTime);
    Request();
    ~Request();
    int getPriority() const;
    int getId() const;
    int getRequestTime() const;
    int getProcessTime() const;
    int getWait() const;
    void incrWait();
    bool operator<(const Request &R);
    bool operator>(const Request &R);


private:
    int id;
    int priority;
    int requestTime;
    int processTime;
    int wait;

};

#endif // REQUEST_H
