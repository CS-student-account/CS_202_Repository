#include "StopWatch.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

StopWatch::StopWatch()
{
	cout << "Default constructor!" << endl << endl;
}

StopWatch::StopWatch(const StopWatch& watch)
{
	cout << "Copy constructor!" << endl << endl;
}

StopWatch::~StopWatch()
{
	cout << "Destructor!" << endl;
}
