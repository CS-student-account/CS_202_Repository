/*
* tokenizer.cpp
* David Misyura
* 28 Mar 2022
* tokenizer.cpp for CS 202
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cctype>
using std::cout;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;
using std::ostream;
using std::stringstream;

bool checkFile(const string &filename) //simple file check
{
	ifstream fin(filename);

	if (!fin)
	{
		cout << "[Cannot open file.]" << '\n';
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
					return true;
				}
				else
				{
					cout << "[Error during transmit.]" << '\n';
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
		//simple bool to check for spaces and similar things
		bool hasspace = find_if(token.begin(), token.end(), ::isspace) != token.end();

		if (!hasspace) 
		{
			tokenVector.push_back(token + ' '); //push tokens into vector until none remain
		}
	}

	return tokenVector; //return vector of tokens
}

//add tokenized strings into a vector
vector<string> readLines(const string &fileName)
{
	ifstream fileStream(fileName);
	string streamToken;
	vector<string> outputTokenVector;

	//iterate line-by-line through file
	while (getline(fileStream, streamToken))
	{
		vector<string> intermediateTokenVector = lineToTokens(streamToken);

		//iterate through vector and push tokens into output vector
		for (auto &i : intermediateTokenVector)
		{
			string token;
			token = i; //set string value of token
			outputTokenVector.push_back(token);
		}
	}
	return outputTokenVector;
}

//wrap vector of tokens
void textWrap(ostream &os, const vector<string> &inputTokens, const int &wordWrap)
{
	vector<string> tokenVector = {""}; //empty vector to allow appending to
	int skippedLines = 0;

	for (auto &token : inputTokens) //iterate through vector of tokens
	{
		//add token if under wrap size
		if ((tokenVector[skippedLines].size() + token.size()) <= wordWrap)
		{
			tokenVector[skippedLines].append(token); //add a token to the line
		}
		else 
		{
			skippedLines++; //iterate total lines skipped
			tokenVector.emplace_back("\n"); //move to next line to continue printing
			tokenVector[skippedLines].append(token); //print leftover tokens to new line
		}
	}

	for (auto &line : tokenVector) //iterate through word-wrapped vector of strings
	{
		os << line;
	}
}