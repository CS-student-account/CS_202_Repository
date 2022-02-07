/*
* Time It 1.cpp
* David Misyura
* 5 Feb 2022
* HW 1 for CS 202
*/

#include "StopWatch.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::this_thread::sleep_for;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::search;
using std::binary_search;
using std::find;
using std::fill;
using std::search_n;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]() 
    {
        return dist(gen);
    };
    


    cout << endl << "------------------------------" << endl << "[Vector of size 10 elements]" << endl;

    cout << endl << "!find algorithm!";
    vector<int> vectorTenFind(10);
    generate(begin(vectorTenFind), end(vectorTenFind), random);
    int targetTen = vectorTenFind[vectorTenFind.size()/2];
    StopWatch timerTenFind;
    for (int i = 0; i < 5; i++)
    {
        auto findTen = find(vectorTenFind.begin(), vectorTenFind.end(), targetTen);
    }
    timerTenFind.Stop();
    cout << endl << "Milliseconds: " << timerTenFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenFind.elapsedSeconds() << endl;

    cout << endl << "!binary_search algorithm!";
    vector<int> vectorTenBinarySearch(10);
    generate(begin(vectorTenBinarySearch), end(vectorTenBinarySearch), random);
    targetTen = vectorTenBinarySearch[vectorTenBinarySearch.size() / 2];
    StopWatch timerTenBinarySearch;
    sort(vectorTenBinarySearch.begin(), vectorTenBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchTen = binary_search(vectorTenBinarySearch.begin(), vectorTenBinarySearch.end(), targetTen);
    }
    timerTenBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerTenBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenBinarySearch.elapsedSeconds() << endl;

    cout << endl << "!upper_bound algorithm!";
    vector<int> vectorTenUpperBound(10);
    generate(begin(vectorTenUpperBound), end(vectorTenUpperBound), random);
    targetTen = vectorTenUpperBound[vectorTenUpperBound.size() / 2];
    StopWatch timerTenUpperBound;
    sort(vectorTenUpperBound.begin(), vectorTenUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundTen = upper_bound(vectorTenUpperBound.begin(), vectorTenUpperBound.end(), targetTen) - vectorTenUpperBound.begin();
    }
    timerTenUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerTenUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenUpperBound.elapsedSeconds() << endl;

    cout << endl << "!search_n algorithm!";
    vector<int> vectorTenSearchN(10);
    generate(begin(vectorTenSearchN), end(vectorTenSearchN), random);
    targetTen = vectorTenSearchN[vectorTenSearchN.size() / 2];
    StopWatch timerTenSearchN;
    for (int i = 0; i < 5; i++)
    {
        vector<int>::iterator searchNTen;
        searchNTen = search_n(vectorTenSearchN.begin(), vectorTenSearchN.end(), 1, targetTen);
    }
    timerTenSearchN.Stop();
    cout << endl << "Milliseconds: " << timerTenSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;

    /*vector<int> vectorHundred(100);
    int targetHundred;
    for (int i = 0; i < 100; i++)
    {
        int random = dist(gen);
        hundred.push_back(random);
        if (i == 50)
        {
            targetHundred = i;
        }
    }
    StopWatch timerHundred;
    auto findHundred = find(vectorHundred.begin(), vectorHundred.end(), targetHundred);
    timerHundred.Stop();


    vector<int> thousand(1'000);
    int targetThousand;
    for (int i = 0; i < 1'000; i++)
    {
        int random = dist(gen);
        thousand.push_back(random);
        if (i == 500)
        {
            targetThousand = i;
        }
    }
    StopWatch timerThousand;
    auto findThousand = find(thousand.begin(), thousand.end(), targetThousand);
    timerThousand.Stop();


    vector<int> tenThousand(10'000);
    int targetTenThousand;
    for (int i = 0; i < 10'000; i++)
    {
        int random = dist(gen);
        tenThousand.push_back(random);
        if (i == 5'000)
        {
            targetTenThousand = i;
        }
    }
    StopWatch timerTenThousand;
    auto findTenThousand = find(tenThousand.begin(), tenThousand.end(), targetTenThousand);
    timerTenThousand.Stop();


    vector<int> hundredThousand(100'000);
    int targetHundredThousand;
    for (int i = 0; i < 100'000; i++)
    {
        int random = dist(gen);
        hundredThousand.push_back(random);
        if (i == 50'000)
        {
            targetHundredThousand = i;
        }
    }
    StopWatch timerHundredThousand;
    auto findHundredThousand = find(hundredThousand.begin(), hundredThousand.end(), targetHundredThousand);
    timerHundredThousand.Stop();


    vector<int> million(1'000'000);
    for (int i = 0; i < 1'000'000; i++)
    {
        int random = dist(gen);
        million.push_back(random);
        if (i == 500'000)
        {
            targetMillion = i;
        }
    }
    generate(begin(billion), end(billion), random);
    int targetMillion;
    StopWatch timerMillion;
    auto findMillion = find(million.begin(), million.end(), targetMillion);
    timerMillion.Stop();


    vector<int> tenMillion(10'000'000);
    int targetTenMillion;
    for (int i = 0; i < 10'000'000; i++)
    {
        int random = dist(gen);
        tenMillion.push_back(random);
        if (i == 5'000'000)
        {
            targetTenMillion = i;
        }
    }
    StopWatch timerTenMillion;
    auto findTenMillion = find(tenMillion.begin(), tenMillion.end(), targetTenMillion);
    timerTenMillion.Stop();


    vector<int> hundredMillion(100'000'000);
    int targetHundredMillion;
    for (int i = 0; i < 100'000'000; i++)
    {
        int random = dist(gen);
        hundredMillion.push_back(random);
        if (i == 50'000'000)
        {
            targetHundredMillion = i;
        }
    }
    StopWatch timerHundredMillion;
    auto findHundredMillion = find(hundredMillion.begin(), hundredMillion.end(), targetHundredMillion);
    timerHundredMillion.Stop();*/


    /*vector<int> billion(1'000'000'000);
    int targetBillion;
    generate(begin(billion), end(billion), random);
    for (int i = 0; i < 1'000'000'000; i++)
    {
        //int random = dist(gen);
        billion.push_back(random);
        if (i == 500'000'000)
        {
            targetBillion = i;
        }
    }
    StopWatch timerBillion;
    auto findBillion = find(billion.begin(), billion.end(), targetBillion);
    timerBillion.Stop();*/



    //cout << endl << "Milliseconds: " << timerHundred.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerHundred.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerThousand.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerThousand.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerTenThousand.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerTenThousand.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerHundredThousand.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerHundredThousand.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerMillion.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerMillion.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerTenMillion.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerTenMillion.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerHundredMillion.elapsedMilliseconds() 
    // << endl << "Seconds: " << timerHundredMillion.elapsedSeconds() << endl;
    //cout << endl << "Milliseconds: " << timerBillion.elapsedMilliseconds() 
    //<< endl << "Seconds: " << timerBillion.elapsedSeconds() << endl;
	return 0;
}