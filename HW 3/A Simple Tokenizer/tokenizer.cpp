/*
* tokenizer.cpp
* David Misyura
* 10 Oct 2020
* tokenizer.cpp for CS201
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
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

bool readFile(const string& filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		cout << "Cannot open file." << endl;
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
					cout << "Successfully read the whole file." << endl;
					return true;
				}
				else
				{
					cout << "Error during transmit." << endl;
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

	int numlines = 25;

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
				return lines[55]; //return a random line of text
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
	ifstream inputStream(line);
	string outputString;
	getline(inputStream, outputString);

	string token;
	vector<string> tokens;

	while (inputStream >> token) //pushes each of the tokens from the string separated by a space into the vector of strings
	{
		tokens.push_back(token);
	}

	tokens.push_back(" "); //at the end of each line, push a whitespace
	return tokens; //returns how many tokens there are

}

vector<TokenAndPosition> readLines(istream &is);

void printTokens(ostream &os, const vector<TokenAndPosition> &tokens);