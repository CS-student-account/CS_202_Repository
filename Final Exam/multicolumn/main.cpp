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

    if (argc > 6) //tell the user to include no more than 2 arguments
    {
        cout << "Please don't input more than 2 arguments at a time." << '\n';
    }
    else if (argc == 6) //print only lines of text file
    {
        const string fileName(argv[1]);
        const string linesPerPageString(argv[2]);
        const int linesPerPage = stoi(linesPerPageString);
        const string charPerLineString(argv[3]);
        const int charPerLine = stoi(charPerLineString);
        const string colPerPageString(argv[4]);
        const int colPerPage = stoi(colPerPageString);
        const string spaceBetweenColString(argv[5]);
        const int spaceBetweenCol = stoi(spaceBetweenColString);

        if (!fileName.empty())
        {
            if (!linesPerPageString.empty())
            {
                if (!charPerLineString.empty())
                {
                    if (!colPerPageString.empty())
                    {
                        if (!spaceBetweenColString.empty())
                        {
                            if (checkFile(fileName)) //quick file check
                            {
                                textWrap(cout, readLines(fileName), linesPerPage, charPerLine, colPerPage, spaceBetweenCol);

                                cout << "\n\n" << "prettyprinted " << fileName
                                    << " with word wrap size of " << charPerLine << " characters";
                            }
                        }
                        else cout << "Your fifth argument, space between columns, wasn't understood." << '\n';
                    }
                    else cout << "Your fourth argument, columns per page, wasn't understood." << '\n';
                }
                else cout << "Your third argument, characters per line', wasn't understood." << '\n';
            }
            else cout << "Your second argument, lines per page, wasn't understood." << '\n';
        }
        else cout << "Your first argument, file name, wasn't understood." << '\n';
    }
    else cout << "Not enough arguments." << '\n';

    return 0;
}