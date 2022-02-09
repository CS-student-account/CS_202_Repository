#include "StopWatch.h"
#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
using std::endl;
using std::string;
using std::cout;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::binary_search;
using std::find;
using std::search_n;
using std::to_string;

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

void StopWatch::Stop() //stop timer
{
    endTime = high_resolution_clock::now();
}

double StopWatch::elapsedMilliseconds() //get elapsed ms
{
    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();
    return (endTime - startTime).count()/1'000'000;
}

double StopWatch::elapsedSeconds() //get elapsed sec
{
    return elapsedMilliseconds() / 1000;
}

// vary location of target int for each search
int randomTarget(vector<int> &temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp.size()-1);
    int random = dist(gen);
    return (random);
}

//better readability of vector size printouts
string vectorSize(int &tempInt)
{
    switch (tempInt) 
    {
    case (1'000):
        return "1,000";
        break;
    case (10'000):
        return "10,000";
        break;
    case (100'000):
        return "100,000";
        break;
    case (1'000'000):
        return "1,000,000";
        break;
    case (10'000'000):
        return "10,000,000";
        break;
    case (100'000'000):
        return "100,000,000";
        break;
    case (1'000'000'000):
        return "1,000,000,000";
        break;

    default:
        string tempString = to_string(tempInt);
        return tempString;
        break;
    }
}

void lookForInt(int &temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp*10);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "--------------------------------------------------" << endl
        << "[Vector of size " << vectorSize(temp) << " elements]" << endl;


    cout << endl << "{find algorithm}";
    vector<int> vectorFind(temp); //initialize vector
    generate(begin(vectorFind), end(vectorFind), random); //fill vector
    int target = vectorFind[randomTarget(vectorFind)]; //random int target
    StopWatch timerFind; //start timer
    for (int i = 0; i < 100; i++) //search for target int 100 times
    {
        auto findTarget = find(vectorFind.begin(), vectorFind.end(), target);
    }
    timerFind.Stop(); //stop timer
    cout << endl << "Milliseconds: " << timerFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerFind.elapsedSeconds() << endl;


    cout << endl << "{binary_search algorithm}"; //same as above, different algorithm
    vector<int> vectorBinarySearch(temp);
    generate(begin(vectorBinarySearch), end(vectorBinarySearch), random);
    target = vectorBinarySearch[randomTarget(vectorBinarySearch)];
    sort(vectorBinarySearch.begin(), vectorBinarySearch.end());
    StopWatch timerBinarySearch;
    for (int i = 0; i < 100; i++)
    {
        auto binarySearchTarget = binary_search(vectorBinarySearch.begin(),
            vectorBinarySearch.end(), target);
    }
    timerBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerBinarySearch.elapsedSeconds() << endl;


    cout << endl << "{upper_bound algorithm}"; //same as above, but different algorithm
    StopWatch timerUpperBound;
    for (int i = 0; i < 100; i++)
    {
        auto upperBoundTarget = upper_bound(vectorBinarySearch.begin(),
            vectorBinarySearch.end(), target) - vectorBinarySearch.begin();
    }
    timerUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerUpperBound.elapsedSeconds() << endl;


    cout << endl << "{search_n algorithm}"; //same as above, but different algorithm
    vector<int> vectorSearchN(temp);
    generate(begin(vectorSearchN), end(vectorSearchN), random);
    target = vectorSearchN[randomTarget(vectorSearchN)];
    StopWatch timerSearchN;
    for (int i = 0; i < 100; i++)
    {
        auto searchNTarget = search_n(vectorSearchN.begin(), vectorSearchN.end(),
            1, target);
    }
    timerSearchN.Stop();
    cout << endl << "Milliseconds: " << timerSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerSearchN.elapsedSeconds() << endl;


    cout << "--------------------------------------------------" << endl;
}
