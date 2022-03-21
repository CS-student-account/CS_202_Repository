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
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main(int argc, char** argv)
{
    if (argc > 1) //check if there's at least the name of the program
    {
        if (argc >= 4) //tell the user to include no more than 2 arguments
        {
            cout << "Please don't input more than two arguments at a time." << endl;
        }
        else if (argc == 2) //print lines and columns of text file
        {
            string fileName(argv[1]);

            if (!fileName.empty())
            {
                if (checkFile(fileName)) //quick file check
                {
                    StopWatch printWatch; //start timer
                    ifstream fileStream(fileName);
                    vector<TokenAndPosition> tokenVector = readLines(fileStream); 
                    printTokens(cout, tokenVector);
                    printWatch.Stop(); //stop timer and print elapsed time
                    printWatch.Bandwidth(fileName); //print bandwidth of file operation
                }
            }
            else
            {
                cout << "Your first argument, 'argv[1]', wasn't understood." << endl;
            }
        }
        else if (argc == 3) //print only lines of text file
        {
            string fileName(argv[1]); 
            string lineOnlyOption(argv[2]);

            if (!fileName.empty())
            {
                if (!lineOnlyOption.empty())
                {
                    if (lineOnlyOption == "--lineonly")
                    {
                        if (checkFile(fileName)) //quick file check
                        {
                            StopWatch lineOnlyWatch; //start timer
                            ifstream fileStream(fileName);
                            vector<TokenAndPosition> tokenVectorLineOnly = readLines(fileStream);
                            lineOnlyWatch.Stop(); //stop timer and print elapsed time
                            lineOnlyWatch.Bandwidth(fileName); //print bandwidth of file operation
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