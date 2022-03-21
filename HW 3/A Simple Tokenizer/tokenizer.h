#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <chrono>
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::chrono::high_resolution_clock;
using std::chrono::time_point;

bool checkFile(const string& filename);

struct TokenAndPosition 
{
	string _token;
	int _line;
	unsigned int _column;
};

vector<string> lineToTokens(const string& line);
vector<TokenAndPosition> readLines(istream& is);
void printTokens(ostream& os, const vector<TokenAndPosition>& tokens);

class StopWatch
{
public:
	time_point<high_resolution_clock> startTime;
	time_point<high_resolution_clock> endTime;

	StopWatch(); //default constructor
	StopWatch(const StopWatch& watch); //copy constructor
	~StopWatch(); //destructor

	void Start();
	void Stop();
	void Bandwidth(const string& fileName);
};

#endif 