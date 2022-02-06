#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <string>
#include <chrono>
using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::time_point;

class StopWatch
{
private:
	time_point<high_resolution_clock> startTime;
	time_point<high_resolution_clock> endTime;
	bool timerRunning;

public:
	StopWatch(); //default constructor
	StopWatch(const StopWatch& watch); //copy constructor
	~StopWatch(); //destructor

	void Start();
	void Stop();
	double elapsedMilliseconds();
	double elapsedSeconds();
};
#endif