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
#include <chrono>
#include <filesystem>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;
using std::ostream;
using std::istream;
using std::find;
using std::stringstream;
using std::quoted;
using std::map;
using std::sort;
using std::setw;
using std::left;
using std::right;
using std::setfill;
using namespace std::chrono;
using std::filesystem::file_size;
using std::setprecision;

bool checkFile(const string& filename) //simple file check
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

//tokenize a single line of string
vector<string> lineToTokens(const string &line)
{
	vector<string> tokenVector; //vector of string to save tokens

	stringstream tokenStream(line); //place line of string into stream

	string token; //string for individual tokens

	while (getline(tokenStream, token, ' ')) //getline with space as delimiter
	{
		if (!token.empty()) //push tokens into vector until none remain
		{
			tokenVector.push_back(token);
		}
	}
	
	return tokenVector; //return vector of tokens
}

//assign each token a line and column
vector<TokenAndPosition> readLines(istream& is)
{
	vector<TokenAndPosition> tokenPositionVector;
	string tempString;
	int totalLines = 1; //start line counter at 1

	while (getline(is, tempString))
	{
		int totalColumns = 0; //start column counter at 0
		vector<string> tokenizedVector = lineToTokens(tempString);

		map<string, int> duplicateMap; //map to track duplicates
		map<string, int>::iterator mapIt; //iterator for map
		int mapCounter = 1; //start map counter at 1

		//iterate through vector and assign labels to each token
		for (int i = 0; i < tokenizedVector.size(); ++i)
		{
			TokenAndPosition token;
			token._token = tokenizedVector[i]; //set string value of token
			vector<string>::iterator it;
			it = find(tokenizedVector.begin(), tokenizedVector.end(), token._token);
			mapIt = duplicateMap.find(token._token);

			if (mapIt != duplicateMap.end()) //duplicate tokens
			{
				int position = i+1; //base position off previous token
				mapIt->second = mapIt->second + 1;
				token._column = position + totalColumns;
			}
			else //non-duplicate tokens
			{
				int position = (it - tokenizedVector.begin()) + 1;
				duplicateMap[token._token] = 1;
				token._column = position + totalColumns;
			}
			
			token._line = totalLines; //set line value of token
			tokenPositionVector.push_back(token);
			totalColumns += token._token.size(); //account for token size
												 //in column tracker
		}

		totalLines++;
	}

	return tokenPositionVector;
}

//print out all the labeled tokens
void printTokens(ostream& os, const vector<TokenAndPosition>& tokens)
{
	for (auto token : tokens) //iterate through entire vector
	{
		os << "[Line " << right << setfill(' ') << setw(4) << token._line << setw(6) 
			<< ", Column " << left << setfill(' ') << setw(2) << token._column << "]: " 
			<< quoted(token._token) << endl;
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

	//elapsed time in milliseconds
	double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

	//printing out elapsed time in both ms and s
	cout << "That took " << (elapsedMilliseconds / 1000) << " seconds, ";
}

//print out speed at which the file was processed
void StopWatch::Bandwidth(const string &fileName)
{
	double fileSize = file_size(fileName); //file size in bytes
	double MB = 1'048'576; //size of MB
	double fileSizeMB = fileSize / MB; //file size from bytes to MB
	double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;
	double elapsedSeconds = elapsedMilliseconds / 1'000;
	double megabytePerSecond = fileSizeMB / elapsedSeconds;
	cout << "at a bandwidth of " << setprecision(3) << megabytePerSecond << " MB/s." << endl;
}
/* StopWatch Section End */