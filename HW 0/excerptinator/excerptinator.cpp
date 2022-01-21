/*
* excerptinator.cpp
* David Misyura
* 20 Jan 2021
* HW 0 excerptinator.cpp for CS 202
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <time.h>
#include <stdlib.h>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;

bool readFile(const string &filename)
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

	random_device rd;
	mt19937 gen(rd());  // PRNG, randomly seeded
	uniform_int_distribution<int> dist(1, 1000);
	int numlines = dist(gen);

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
				return lines[dist(gen)]; //return a random line of text
			}
			else
			{
				return "Error during transmit.";
			}
			break;
		}
	}
}

int main()
{
	const string fname = "A Tale of Two Cities by Charles Dickens.txt";  // File to write & read

	if (readFile(fname))
	{
		cout << excerpt(fname) << endl;
	}

	// Wait for user
	cout << "Press ENTER to quit ";
	string dummyline;
	getline(cin, dummyline);

    return 0;
}