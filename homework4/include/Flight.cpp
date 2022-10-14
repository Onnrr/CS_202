/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: flight class
*/

#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight(int departure, int arrival, int duration) {
    this->departure = departure;
    this->arrival = arrival;
    this->duration = duration;
}

Flight::Flight() {
    departure = 0;
    arrival = 0;
    duration = 0;
}


Flight::~Flight() {
}

int Flight::getDeparture() {
    return departure;
}

int Flight::getArrival() {
    return arrival;
}

int Flight::getDuration() {
    return duration;
}

bool Flight::operator> (const Flight &R ) {
    if (duration < R.duration) {
        return false;
    }

    return true;
}

bool Flight::operator< (const Flight &R ) {
    if (duration > R.duration) {
        return false;
    }

    return true;
}
