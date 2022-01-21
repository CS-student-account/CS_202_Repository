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

int main(int argc, char** argv)
{
    string inputString(argv[1]);

    if (argc > 0)
    {
        if (inputString == "--ftoc")
        {
            const char* inputF = argv[2];

            cout << argv[2] << " degrees Fahrenheit is " << cpp_ftoc(inputF) 
                << " degrees Celsius!" << endl;
        }
        else if (inputString == "--ctof")
        {
            const char* inputC = argv[2];

            cout << argv[2] << " degrees Celsius is " << c_ctof(inputC)
                << " degrees Fahrenheit!" << endl;
        }
        else
        {
            cout << "Your input wasn't understood." << endl;
        }
    }




    return 0;
}