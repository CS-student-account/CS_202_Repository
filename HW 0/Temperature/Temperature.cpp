/*
* temperature.cpp
* David Misyura
* 20 Jan 2021
* HW 0 temperature.cpp for CS 202
*/

#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::stod;
using std::strtod;
using std::string;

double cpp_ftoc(const char* str)
{
    double inputF = stod(str);
    double outputC = (inputF - 32) * (5 / 9);
    return outputC;
}

int main(int argc, char** argv)
{
    string inputString(argv[1]);

    if (argc > 0)
    {
        if (inputString == "ftoc")
        {
            const char* inputF = argv[2];
            cout << "argv 1 found!" << endl;
            cout << cpp_ftoc(inputF) << endl;
            for (int i = 0; i < argc; ++i)
            {
                cout << argv[i] << endl;
            }
        }
    }




    return 0;
}