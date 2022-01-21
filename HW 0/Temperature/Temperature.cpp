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
    string inputF = str;
    double inputFDouble = stod(inputF);
    double outputC = (((inputFDouble - 32) * 5) / 9);
    return outputC;
}

double c_ctof(const char* str)
{
    string inputC = str;
    char* end;
    double inputCDouble = strtod(str, &end);
    double outputF = (((inputCDouble * 9) / 5) + 32);
    return outputF;
}

bool isNumber(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false)
        {
            if (s.find('.') != string::npos)
            {
                return true;
            }
            else return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    string inputCommand(argv[1]);
    string inputTemp(argv[2]);

    if (argc > 0)
    {
        if (isNumber(inputTemp))
        {
            if (inputCommand == "--ftoc")
            {
                const char* inputF = argv[2];

                cout << argv[2] << " degrees Fahrenheit is " << cpp_ftoc(inputF)
                    << " degrees Celsius!" << endl;
            }
            else if (inputCommand == "--ctof")
            {
                const char* inputC = argv[2];

                cout << argv[2] << " degrees Celsius is " << c_ctof(inputC)
                    << " degrees Fahrenheit!" << endl;
            }
            else
            {
                cout << "Your first parameter, 'argv[1]', wasn't understood." << endl;
            }
        }
        else
        {
            cout << "Your second parameter, 'argv[2]', wasn't understood." << endl;
        }
    }

    return 0;
}