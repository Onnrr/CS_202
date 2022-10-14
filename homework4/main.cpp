/*
* Title: CS202 Spring 2022
* Author: Mehmet Onur Uysal
* ID: 22002609
* Section: 1
* Assignment: 4
* Description: main
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include "Graph.h"

using namespace std;

int main(int argc, char** argv)
{
    int numberOfAirports;
    int numberOfInstructions;
    fstream reader;
    string filename = argv[1];

    reader.open(filename.c_str(),ios::in);

    // Get Number of airports
    string numberOfAirportsString;
    getline (reader, numberOfAirportsString);
    stringstream temp1(numberOfAirportsString);
    temp1 >> numberOfAirports;
    // Get Number of instructions
    string numberOfInstructionsString;
    getline (reader, numberOfInstructionsString);
    stringstream temp2(numberOfInstructionsString);
    temp2 >> numberOfInstructions;


    Graph *airports = new Graph(numberOfAirports);

    for (int i = 0; i < numberOfInstructions; i++) {
        string log;
        string token;
        getline(reader, log);

        stringstream instLog(log);
        string opcode;
        getline(instLog, opcode, ' ');

        if (opcode == "I") {
            string departureString, arrivalString, durationString;
            int departure, arrival, duration;
            getline(instLog, departureString, ' ');
            getline(instLog, arrivalString, ' ');
            getline(instLog, durationString, ' ');

            stringstream temp3(departureString);
            temp3 >> departure;

            stringstream temp4(arrivalString);
            temp4 >> arrival;

            stringstream temp5(durationString);
            temp5 >> duration;

            airports->add(departure, arrival, duration);

            cout << endl;
        }
        else if (opcode == "S") {
            string departureString, arrivalString;
            int departure, arrival;
            getline(instLog, departureString, ' ');
            getline(instLog, arrivalString, ' ');
            stringstream temp3(departureString);
            temp3 >> departure;

            stringstream temp4(arrivalString);
            temp4 >> arrival;

            int duration;
            string result = airports->shortestPath(departure, arrival, duration);

            if (result == "") {
                cout << "No paths from " << departure << " to " << arrival << endl;
            }
            else {
                cout << "The shortest path from " << departure << " to " << arrival << ":";
                cout << result << endl;
                cout << "Total flight duration of path: " << duration;
            }
            cout << endl << endl;
        }
        else if (opcode == "L") {
            string airportString;
            int airport;
            getline(instLog, airportString, ' ');


            stringstream temp4(airportString);
            temp4 >> airport;
            cout << "List of flights from " << airport << ":" << endl;
            airports->list(airport);
            cout << endl;
        }
        else if (opcode == "M") {
            int oldCost, newCost;
            airports->minimize(oldCost,newCost);

            cout << "Total cost of operations before minimization: " << oldCost << endl;
            cout << "Total cost of operations after minimization: " << newCost << endl << endl;
        }

    }

    delete airports;
    reader.close();
    return 0;
}
