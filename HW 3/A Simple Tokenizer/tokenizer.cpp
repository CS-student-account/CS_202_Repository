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
#include <ranges>
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
using std::views::join;

bool readLine(string &str)
{
	cout << "Please type in some text: ";
	if (getline(cin, str)) //accept a string input from the user and save it as the string str
	{
		return true; //if a string is accepted, return true
	}
	else return false; //if no string is accepted, return false
}

unsigned stringToTokenWS(const string &input, vector<string> &tokens)
{
	istringstream instream(input); //reads the string passed in through istringstream
	string token;

	while (instream >> token) //pushes each of the tokens from the string separated by a space into the vector of strings
	{
		tokens.push_back(token);
	}

	tokens.push_back(" "); //at the end of each line, push a whitespace
	return tokens.size(); //returns how many tokens there are
}

void analyzeTokens(const vector<string> &tokens)
{
	vector<string> final; //a tempoorary vector for pushing in final printouts

	for (const auto &i : tokens) //iterate through each string in the vector
	{
		for (const int &character : i) //iterate through each character of each string
		{
			if (character <= 122 && character >= 97)
			{
				final.push_back("[identifier] \"" + i + "\"" + ' ');
				break;
			}

			if (character <= 57 && character >= 48)
			{
				final.push_back("[integer] \"" + i + "\"" + ' ');
				break;
			}

			if (character == 34)
			{
				final.push_back("[quote] " + i + ' ');
				break;
			}

			if (character >= 33 && character <= 47)
			{
				final.push_back("[other] \"" + i + "\"" + ' ');
				break;
			}

			if (character >= 58 && character <= 64)
			{
				final.push_back("[other] \"" + i + "\"" + ' ');
				break;
			}

			if (character == 32)
			{
				final.push_back("[whitespace] \"\"");
				break;
			}
		}
	}

	if (tokens[tokens.size() - 2] == "end") //if "end" is input, this program will print out the identified strings
	{
		for (int j = 0; j < final.size() - 2; j++)
		{
			cout << endl << final[j] << endl;
		}
	}
}

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

string excerpt(const string &filename)
{
	ifstream fin(filename);

	int total_lines = 0; //total number of lines in book
	vector<string> lines; //vector of strings to place words

	while (true)
	{
		string line;
		getline(fin, line);
		total_lines++;
		lines.push_back(line);

		if (!fin)
		{
			if (fin.eof())
			{
				cout << "excerptinator has completed." << endl << endl;
				return lines[150]; //return a random line of text
			}
			else
			{
				return "Error during transmit.";
			}
			break;
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
		tokenVector.push_back(token);
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

		for (const string tokenString : tokenizedVector)
		{
			TokenAndPosition token;
			token._token = tokenString;

			vector<string>::iterator it;
			it = find(tokenizedVector.begin(), tokenizedVector.end(), tokenString);
			int position = (it - tokenizedVector.begin()) + 1;
			token._column = position + totalColumns;
			
			token._line = totalLines;

			tokenPositionVector.push_back(token);

			totalColumns += tokenString.size();
		}
		totalLines++;
	}

	return tokenPositionVector;
}

void printTokens(ostream& os, const vector<TokenAndPosition>& tokens)
{
	for (TokenAndPosition i : tokens)
	{
		os << "[Line " << i._line << ", Column " << i._column << "]: " << quoted(i._token) << endl;
	}
}