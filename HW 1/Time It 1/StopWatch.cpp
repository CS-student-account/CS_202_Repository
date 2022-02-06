#include "StopWatch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using namespace std::chrono;

StopWatch::StopWatch() 
{
	cout << "Default constructor!" << endl << endl;
    startTime = high_resolution_clock::now();
    timerRunning = true;
}

StopWatch::StopWatch(const StopWatch& watch)
{
	cout << "Copy constructor!" << endl << endl;
}

StopWatch::~StopWatch()
{
	cout << "Destructor!" << endl;
}

void StopWatch::Start()
{
    startTime = high_resolution_clock::now();
    timerRunning = true;
}

void StopWatch::Stop()
{
    endTime = high_resolution_clock::now();
    timerRunning = false;
}

double StopWatch::elapsedMilliseconds()
{
    /*time_point<high_resolution_clock> elapsedTime;

    if (timerRunning)
    {
        elapsedTime = high_resolution_clock::now();
    }
    else
    {
        elapsedTime = endTime;
    }*/
    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();
    return (endTime - startTime).count()/1'000'000;
}

double StopWatch::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}