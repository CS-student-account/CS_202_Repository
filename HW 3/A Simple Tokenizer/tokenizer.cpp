/*
* tokenizer.cpp
* David Misyura
* 19 Mar 2022
* tokenizer.cpp for CS 202
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <random>
#include <list>
#include <deque>
#include <filesystem>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::find;
using std::stringstream;
using std::quoted;
using std::map;
using std::sort;
using std::pow;
using std::setw;
using std::left;
using std::right;
using std::setfill;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::istream_iterator;
using std::list;
using std::deque;
using std::filesystem::file_size;
using std::setprecision;

bool checkFile(const string& filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		cout << "[Cannot open file.]" << endl << endl;
		return false;
	}
	else
	{
		while (true)
		{
			string line;
			getline(fin, line);

			if (!fin)
			{
				if (fin.eof())
				{
					cout << "[Successfully read the whole file.]" << endl << endl;
					return true;
				}
				else
				{
					cout << "[Error during transmit.]" << endl << endl;
					return false;
				}
				break;
			}
		}
	}
}

vector<string> lineToTokens(const string &line)
{
	vector<string> tokenVector; //vector of string to save tokens

	stringstream tokenStream(line); //place line of string into stream

	string token; //string for individual tokens

	while (getline(tokenStream, token, ' ')) //getline with space as delimiter
	{
		if (!token.empty())
		{
			tokenVector.push_back(token);
		}
	}

	return tokenVector;
}

vector<TokenAndPosition> readLines(istream& is)
{
	vector<TokenAndPosition> tokenPositionVector;
	string tempString;
	int totalLines = 1;

	while (getline(is, tempString))
	{
		int totalColumns = 0;
		vector<string> tokenizedVector = lineToTokens(tempString);

		map<string, int> duplicateMap;
		map<string, int>::iterator mapIt;
		int mapCounter = 1;

		for (int i = 0; i < tokenizedVector.size(); ++i)
		{
			TokenAndPosition token;
			token._token = tokenizedVector[i];

			vector<string>::iterator it;
			it = find(tokenizedVector.begin(), tokenizedVector.end(), token._token);

			mapIt = duplicateMap.find(token._token);
			if (tokenizedVector[0] == token._token)
			{
				int position = (it - tokenizedVector.begin()) + 1;
				duplicateMap[token._token] = 1;
				token._column = position + totalColumns;
			}
			else if (mapIt != duplicateMap.end())
			{
				int position = i+1;
				mapIt->second = mapIt->second + 1;
				token._column = position + totalColumns;
			}
			else
			{
				int position = (it - tokenizedVector.begin()) + 1;
				duplicateMap[token._token] = 1;
				token._column = position + totalColumns;
			}
			
			token._line = totalLines;
			tokenPositionVector.push_back(token);
			totalColumns += token._token.size();
		}

		totalLines++;
	}

	return tokenPositionVector;
}

void printTokens(ostream& os, const vector<TokenAndPosition>& tokens)
{
	for (auto token : tokens)
	{
		os << "[Line " << right << setfill(' ') << setw(4) << token._line << setw(6) << ", Column " << left << setfill(' ') << setw(2) << token._column << "]: " << quoted(token._token) << endl;
	}
	cout << endl;
}

/* StopWatch Section Beginning */
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

void StopWatch::Stop() //stop timer and print duration
{
	endTime = high_resolution_clock::now();

	double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();

	//elapsed time in milliseconds
	double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

	//printing out elapsed time in both ms and s
	cout << "That took " << (elapsedMilliseconds / 1000) << " seconds, ";
}

void StopWatch::Bandwidth(const string &fileName)
{
	double fileSize = file_size(fileName);
	double MB = 1'048'576;
	double fileSizeMB = fileSize / MB;
	double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;
	double elapsedSeconds = elapsedMilliseconds / 1000;
	double megabytePerSecond = (fileSizeMB) / elapsedSeconds;
	cout << "at a bandwidth of " << setprecision(3) << megabytePerSecond << " MB/s." << endl;
}
/* StopWatch Section End */