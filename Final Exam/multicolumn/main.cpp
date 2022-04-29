/*
* main.cpp
* David Misyura
* 28 April 2022
* CS 202
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <locale>
using std::cout;
using std::string;
using std::vector;
using std::stoi;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "en_US.utf8"); //cross-platform UTF-8 encoding support

    if (argc > 1) //check if there's at least the name of the program
    {
        if (argc >= 4) //tell the user to include no more than 2 arguments
        {
            cout << "Please don't input more than 2 arguments at a time." << '\n';
        }
        else if (argc == 3) //print only lines of text file
        {
            const string fileName(argv[1]); 
            const string wordWrapString(argv[2]);
            const int wordWrap = stoi(wordWrapString);

            if (!fileName.empty())
            {
                if (!wordWrapString.empty())
                {
                    if (checkFile(fileName)) //quick file check
                    {
                        textWrap(cout, readLines(fileName), wordWrap);

                        cout << "\n\n" << "prettyprinted " << fileName 
                            << " with word wrap size of " << wordWrap << " characters";
                    }
                    else cout << "Your second argument, 'argv[2]', wasn't understood." << '\n';
                }
                else cout << "Your second argument, 'argv[2]', wasn't understood." << '\n';
            }
            else cout << "Your first argument, 'argv[1]', wasn't understood." << '\n';
        }
        else cout << "Not enough arguments." << '\n';
    }
	return 0;
}