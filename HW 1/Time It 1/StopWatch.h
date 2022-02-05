#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <string>
using std::string;

class StopWatch
{
private:

public:
	StopWatch(); //default constructor
	StopWatch(const StopWatch& watch); //copy constructor
	~StopWatch(); //destructor
};
#endif