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

int main()
{
	const string fname = "A Tale of Two Cities by Charles Dickens.txt";  // File to write & read

	readFile(fname);
	// Wait for user
	cout << "Press ENTER to quit ";
	string dummyline;
	getline(cin, dummyline);

    return 0;
}