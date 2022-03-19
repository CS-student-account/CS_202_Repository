/*
* A Simple Tokenizer.cpp
* David Misyura
* 18 Mar 2022
* HW 3 for CS 202
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
using std::getline;

int main()
{
	string bookName = "book1.txt";

	if (checkFile(bookName))
	{
		ifstream bookStream(bookName);
		string line;

		while (getline(bookStream, line))
		{
			vector<string> lineToken = lineToTokens(line);
			for (int i = 0; i < lineToken.size(); i++)
			{
				cout << lineToken[i] << endl;
			}
		}
	}


	

	return 0;
}