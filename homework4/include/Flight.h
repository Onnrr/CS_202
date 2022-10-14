/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: header for fligh
*/

#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
using namespace std;

class Flight
{
    public:
        Flight(int departure, int arrival, int duration);
        Flight();
        ~Flight();
        int getDuration();
        int getArrival();
        int getDeparture();
        bool operator<(const Flight &f);
        bool operator>(const Flight &f);

    private:
        int departure;
        int arrival;
        int duration;
        int priority;
};

#endif // FLIGHT_H
