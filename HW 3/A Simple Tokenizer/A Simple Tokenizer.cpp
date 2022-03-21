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
using std::stringstream;
using std::ifstream;
using std::getline;
using std::ostream;

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
            string bookName(argv[1]);

            if (!bookName.empty())
            {
                if (checkFile(bookName))
                {
                    StopWatch printWatch;
                    ifstream bookStream(bookName);
                    vector<TokenAndPosition> tokenVector = readLines(bookStream);
                    printTokens(cout, tokenVector);
                    printWatch.Stop();
                }
            }
            else
            {
                cout << "Your first argument, 'argv[1]', wasn't understood." << endl;
            }
        }
        else if (argc == 3)
        {
            string bookName(argv[1]); //print only lines of text file
            string lineOnlyOption(argv[2]);

            if (!bookName.empty())
            {
                if (!lineOnlyOption.empty())
                {
                    if (lineOnlyOption == "--lineonly")
                    {
                        if (checkFile(bookName))
                        {
                            StopWatch lineOnlyWatch;
                            ifstream bookStream(bookName);
                            vector<TokenAndPosition> tokenVectorLineOnly = readLines(bookStream);
                            lineOnlyWatch.Stop();
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