#include "StopWatch.h"
#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <list>
#include <deque>
using std::endl;
using std::string;
using std::cout;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::find;
using std::getline;
using std::ifstream;
using std::istream;
using std::istream_iterator;
using std::list;
using std::deque;

StopWatch::StopWatch() //default constructor
{
    startTime = high_resolution_clock::now();
}

StopWatch::StopWatch(const StopWatch& watch) //copy constructor
{
}

StopWatch::~StopWatch() //destructor
{
}

void StopWatch::Start() //restart timer
{
    startTime = high_resolution_clock::now();
}

void StopWatch::Stop() //stop timer and print duration
{
    endTime = high_resolution_clock::now();

    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();

    //elapsed time in milliseconds
    double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

    //printing out elapsed time in both ms and s
    cout << endl << "That took " << elapsedMilliseconds << " ms / "
        << (elapsedMilliseconds / 1000) << " s" << endl;
}