/*
* Time It 1.cpp
* David Misyura
* 5 Feb 2022
* HW 1 for CS 202
*/

#include "StopWatch.h"
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <thread>
#include <chrono>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::this_thread::sleep_for;
using namespace std::chrono;

int main()
{
    StopWatch timer;
    sleep_for(1s);
    timer.Stop();
    cout << "Milliseconds: " << timer.elapsedMilliseconds() << "seconds: " << timer.elapsedSeconds() << endl;
    timer.Start();
    sleep_for(2s);
    timer.Stop();
    cout << "Milliseconds: " << timer.elapsedMilliseconds() << "seconds: " << timer.elapsedSeconds() << endl;

    //cout << counter << endl;
    //cout << "Milliseconds: "  << timer.elapsedMilliseconds() << "seconds: " << timer.elapsedSeconds() << endl;

	return 0;
}