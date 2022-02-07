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
    lookForTen();
    lookForHundred();
    lookForThousand();
    lookForTenThousand();
    lookForHundredThousand();
    lookForMillion();
    lookForTenMillion();
    lookForHundredMillion();
    lookForBillion();

	return 0;
}