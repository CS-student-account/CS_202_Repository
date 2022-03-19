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
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

int main()
{
	cout << "Enter the name of the book you want to tokenize: " << endl;
	string book;
	cin >> book;
	readFile(book);

	return 0;
}