/*
* excerptinator.cpp
* David Misyura
* 20 Jan 2021
* HW 0 excerptinator.cpp for CS 202
*/

#include <string>
#include <iostream>
#include <fstream>
using std::endl;
using std::string;
using std::cout;
using std::ifstream;

bool readFile(const string& filename)
{

}

int main()
{
    string line;
    ifstream myfile("example.txt");
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}