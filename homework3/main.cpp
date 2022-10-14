/*
* Title: Heaps, Priority Queues
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 3
* Description: Main method for simulation
*/

#include <iostream>
#include "Request.h"
#include "Heap.h"
#include <fstream>
#include <ios>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    string filename = argv[1];
    string averageString = argv[2];
    double avgwaitingtime;
    stringstream convert(averageString);
    convert >> avgwaitingtime;


    string log;
    int numberOfRequests = 0;

    int elapsedTime;
    int numberOfComputers = 1;
    bool done;
    int* computers;
    Heap* requests;

    int currentNumberOfRequests = 0;
    while (!done) {
        elapsedTime = 1;
        fstream reader;
        reader.open(filename.c_str(),ios::in);
        computers = new int[numberOfComputers];
        for (int i = 0; i < numberOfComputers; i++) {
            computers[i] = 0;
        }

        string numberOfRequestsString;
        getline (reader, numberOfRequestsString);

        stringstream temp(numberOfRequestsString);
        temp >> numberOfRequests;
        requests = new Heap(numberOfRequests);

        double waitAvg = 0;

        getline(reader, log);
        stringstream requestLog(log);
        string token;
        getline(requestLog, token, ' ');
        stringstream temp1(token);
        int id = 0;
        temp1 >> id;

        getline(requestLog, token, ' ');
        stringstream temp2(token);
        int priority = 0;
        temp2 >> priority;

        getline(requestLog, token, ' ');
        stringstream temp3(token);
        int requestTime = 0;
        temp3 >> requestTime;

        getline(requestLog, token, ' ');
        stringstream temp4(token);
        int processTime = 0;
        temp4 >> processTime;

        Request nextReq(id, priority, requestTime, processTime);
        while (true) {
            while (nextReq.getRequestTime() == elapsedTime) {
                requests->heapInsert(nextReq);
                currentNumberOfRequests++;
                getline (reader, log);
                stringstream requestLog(log);
                string token;
                getline(requestLog, token, ' ');
                stringstream temp1(token);
                int id = 0;
                temp1 >> id;

                getline(requestLog, token, ' ');
                stringstream temp2(token);
                int priority = 0;
                temp2 >> priority;

                getline(requestLog, token, ' ');
                stringstream temp3(token);
                int requestTime = 0;
                temp3 >> requestTime;

                getline(requestLog, token, ' ');
                stringstream temp4(token);
                int processTime = 0;
                temp4 >> processTime;

                nextReq = Request(id, priority, requestTime, processTime);

            }
            Request current;
            bool process = false;
            for (int i = 0; i < numberOfComputers; i++) {
                if (computers[i] != 0) {
                    computers[i]--;
                    process = true;
                }
                if (computers[i] == 0 && !requests->heapIsEmpty()) {
                    requests->heapDelete(current);
                    computers[i] = current.getProcessTime();
                    waitAvg += current.getWait();
                    currentNumberOfRequests--;
                }

            }
            for (int i = 0; i < currentNumberOfRequests; i++) {
                requests->getItems()[i].incrWait();
            }
            if (requests->heapIsEmpty() && !process && reader.peek() == EOF) {
                break;
            }
            elapsedTime++;
        }
        waitAvg /= numberOfRequests;
        done = waitAvg < avgwaitingtime;
        if (!done) {
            numberOfComputers++;
        }
        reader.close();
        delete [] computers;
        delete requests;
    }

    /////////////////////////////////////////////////////////////////////////////////////

    cout << "Simulation with " << numberOfComputers << " computers:" << endl;
    elapsedTime = 1;
    fstream reader;
    reader.open(filename.c_str(),ios::in);
    computers = new int[numberOfComputers];
    for (int i = 0; i < numberOfComputers; i++) {
        computers[i] = 0;
    }

    string numberOfRequestsString;
    getline (reader, numberOfRequestsString);

    stringstream temp(numberOfRequestsString);
    temp >> numberOfRequests;
    requests = new Heap(numberOfRequests);

    int wait = 0;
    double waitAvg = 0;

    getline(reader, log);
    stringstream requestLog(log);
    string token;
    getline(requestLog, token, ' ');
    stringstream temp1(token);
    int id = 0;
    temp1 >> id;

    getline(requestLog, token, ' ');
    stringstream temp2(token);
    int priority = 0;
    temp2 >> priority;

    getline(requestLog, token, ' ');
    stringstream temp3(token);
    int requestTime = 0;
    temp3 >> requestTime;

    getline(requestLog, token, ' ');
    stringstream temp4(token);
    int processTime = 0;
    temp4 >> processTime;

    Request nextReq(id, priority, requestTime, processTime);
    while (true) {
        while (nextReq.getRequestTime() == elapsedTime) {
            requests->heapInsert(nextReq);
            currentNumberOfRequests++;
            getline (reader, log);
            stringstream requestLog(log);
            string token;
            getline(requestLog, token, ' ');
            stringstream temp1(token);
            int id = 0;
            temp1 >> id;

            getline(requestLog, token, ' ');
            stringstream temp2(token);
            int priority = 0;
            temp2 >> priority;

            getline(requestLog, token, ' ');
            stringstream temp3(token);
            int requestTime = 0;
            temp3 >> requestTime;

            getline(requestLog, token, ' ');
            stringstream temp4(token);
            int processTime = 0;
            temp4 >> processTime;

            nextReq = Request(id, priority, requestTime, processTime);

        }
        Request current;
        bool process = false;
        for (int i = 0; i < numberOfComputers; i++) {
            bool found = false;
            if (computers[i] != 0) {
                computers[i]--;
                process = true;
            }
            if (computers[i] == 0 && !requests->heapIsEmpty()) {
                requests->heapDelete(current);
                cout << "Computer " << i << " takes request " << current.getId() << " at ms " << elapsedTime << " (wait : " << current.getWait() << "ms)" << endl;
                computers[i] = current.getProcessTime();
                waitAvg += current.getWait();
                found = true;
                currentNumberOfRequests--;
                }
        }
        for (int i = 0; i < currentNumberOfRequests; i++) {
            requests->getItems()[i].incrWait();
        }
        if (requests->heapIsEmpty() && !process && reader.peek() == EOF) {
            break;
        }
        elapsedTime++;
    }
    waitAvg /= numberOfRequests;
    cout << "Average wait : " << waitAvg << endl;
    done = waitAvg < avgwaitingtime;
    numberOfComputers++;
    delete [] computers;
    delete requests;
    reader.close();
    return 0;
}
