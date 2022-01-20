/*
* Temperature.cpp
* David Misyura
* 20 Jan 2021
* HW 0 Temperature.cpp for CS 202
*/

#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::stod;
using std::strtod;

double cpp_ftoc(const char* str)
{
    return 0.0;
}

int main(int argc, char** argv)
{
    cout << "You have entered " << argc
        << " arguments:" << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}