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
using std::search;


int main()
{
    random_device rd;
    mt19937 gen(rd());  // PRNG, randomly seeded
    uniform_int_distribution<int> dist(1, 1'000'000);
    

    //int target = dist;
    vector<int> ten;

    
    StopWatch timer;
    //auto findTen = find(ten.begin(), ten.end(), random);
    for (int i=0; i<10; i++)
    {
        int random = dist(gen);
        ten.push_back(random);
        
    }
    for (auto i : ten)
    {
        cout << i << " ";
    }
    timer.Stop();

    vector<int> hundred(100);
    vector<int> thousand(1000);
    vector<int> ten_thousand(10'000);
    vector<int> hundred_thousand(100'000);
    vector<int> million(1'000'000);
    vector<int> ten_million(10'000'000);
    vector<int> hundred_million(100'000'000);
    vector<int> billion(1'000'000'000);

    cout << endl << "Milliseconds: "  << timer.elapsedMilliseconds() << endl << "seconds: " << timer.elapsedSeconds() << endl;

	return 0;
}