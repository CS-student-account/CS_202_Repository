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
#include <filesystem>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::stringstream;
using std::ifstream;
using std::getline;
using std::ostream;
using namespace std::chrono;
using std::filesystem::file_size;
using std::setprecision;

int main(int argc, char** argv)
{
    if (argc > 1) //check if there's at least the name of the program
    {
        if (argc >= 4) //tell the user to only include 2 arguments
        {
            cout << "Please don't input more than two arguments at a time." << endl;
        }
        else if (argc == 2) //print lines and columns of text file
        {
            string fileName(argv[1]);

            if (!fileName.empty())
            {
                if (checkFile(fileName))
                {
                    StopWatch printWatch;
                    ifstream fileStream(fileName);
                    vector<TokenAndPosition> tokenVector = readLines(fileStream);
                    printTokens(cout, tokenVector);
                    printWatch.Stop();
                    printWatch.Bandwidth(fileName);
                }
            }
            else
            {
                cout << "Your first argument, 'argv[1]', wasn't understood." << endl;
            }
        }
        else if (argc == 3)
        {
            string fileName(argv[1]); //print only lines of text file
            string lineOnlyOption(argv[2]);

            if (!fileName.empty())
            {
                if (!lineOnlyOption.empty())
                {
                    if (lineOnlyOption == "--lineonly")
                    {
                        if (checkFile(fileName))
                        {
                            StopWatch lineOnlyWatch;
                            ifstream fileStream(fileName);
                            vector<TokenAndPosition> tokenVectorLineOnly = readLines(fileStream);
                            lineOnlyWatch.Stop();
                            lineOnlyWatch.Bandwidth(fileName);
                        }
                    }
                    else
                    {
                        cout << "Your second argument, 'argv[2]', wasn't understood." << endl;
                    }
                }
                else
                {
                    cout << "Your second argument, 'argv[2]', wasn't understood." << endl;
                }
            }
            else
            {
                cout << "Your first argument, 'argv[1]', wasn't understood." << endl;
            }
        }
        else cout << "Not enough arguments." << endl;
    }

	return 0;
}