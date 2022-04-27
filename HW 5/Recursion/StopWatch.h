#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <string>
#include <chrono>
using std::string;
using namespace std::chrono;

class StopWatch
{
private:
	time_point<high_resolution_clock> startTime;
	time_point<high_resolution_clock> endTime;

public:
	StopWatch() //default constructor
	{
		startTime = high_resolution_clock::now();
	}
	StopWatch(const StopWatch& watch) {} //copy constructor
	~StopWatch() {} //destructor

	void Start() //restart timer
	{
		startTime = high_resolution_clock::now();
	}
	void Stop() //stop timer and print duration
	{
		endTime = high_resolution_clock::now();

		double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();

		//elapsed time in milliseconds
		double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

		//printing out elapsed time in both ms and s
		cout << '\n' << "That took " << elapsedMilliseconds << " ms / "
			<< (elapsedMilliseconds / 1000) << " s" << '\n';
	}
};

#endif