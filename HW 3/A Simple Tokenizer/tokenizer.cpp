/*
* tokenizer.cpp
* David Misyura
* 10 Oct 2020
* tokenizer.cpp for CS201
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

bool ReadLine(std::string &str)
{
	cout << "Please type in some text: ";
	if (getline(cin, str)) //accept a string input from the user and save it as the string str
	{
		return true; //if a string is accepted, return true
	}
	else return false; //if no string is accepted, return false
}

unsigned StringToTokenWS(const std::string &input, std::vector<std::string> &tokens)
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

void AnalyzeTokens(const std::vector<std::string> &tokens)
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