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
	//cout << "Enter the name of the book you want to tokenize: " << endl;
	string bookName = "book1.txt";
	//cin >> book;
	//readFile(book);

	ifstream inputStream(bookName);

	while (true)
	{
		string line;
		getline(inputStream, line);
		lineToTokens(line);

		if (!inputStream)
		{
			if (inputStream.eof())
			{
				cout << "Successfully read the whole file." << endl;
			}
			else
			{
				cout << "Error during transmit." << endl;
			}
			break;
		}
	}

	return 0;
}