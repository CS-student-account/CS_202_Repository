/*
* tokenizer.cpp
* David Misyura
* 28 April 2022
* CS 202
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <cmath>
using std::cout;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;
using std::ostream;
using std::stringstream;
using std::remove_if;
using std::setw;
using std::setfill;
using std::floor;
using std::left;

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
		//remove whitespaces from each token
		token.erase(remove_if(token.begin(), token.end(), isspace), token.end());

		if (!token.empty()) //ignore the large whitespaces that are somehow left behind
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
void textWrap(ostream &os, const vector<string> &inputTokens, const int &linesPerPage, const int &charPerLine, const int &colPerPage, const int &spaceBetweenCol)
{
	int charPerCol = floor((charPerLine-(spaceBetweenCol*(colPerPage-1)))/colPerPage);
	int pageSeparatorLength = ((charPerCol*colPerPage) + (colPerPage*spaceBetweenCol));
	vector<string> tokenVector = {""}; //empty vector to allow appending to
	int skippedLines = 0;

	for (int i = 0; i < inputTokens.size(); i++) //iterate through vector of tokens
	{
		//add token if under wrap size
		if ((tokenVector[skippedLines].size() + inputTokens[i].size()) <= charPerCol)
		{
			tokenVector[skippedLines].append(inputTokens[i]); //add a token to the line
			
		}
		else
		{
			skippedLines++; //iterate total lines skipped
			tokenVector.push_back("\n"); //move to next line to continue printing
			tokenVector[skippedLines].append(inputTokens[i]); //print leftover tokens to new line
		}

	}

	for (int i = 0; i < tokenVector.size(); i++) //iterate through word-wrapped vector of strings
	{
		if (((i % linesPerPage) == 0) && (i!=0))
		{
			os << '\n' << setfill('-') << setw(pageSeparatorLength) << '-';
		}

		os << setfill(' ') << setw(charPerCol) << left << tokenVector[i] << '|';
	}
}