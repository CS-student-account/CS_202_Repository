/*
* temperature.cpp
* David Misyura
* 20 Jan 2021
* HW 0 temperature.cpp for CS 202
*/

#include <string>
#include <iostream>
using std::endl;
using std::stod;
using std::strtod;
using std::string;
using std::cout;

/* function for converting F to C with the C++ function "stod" */
double cpp_ftoc(const char* str)
{
    string inputF = str; 
    double inputFDouble = stod(inputF);
    double outputC = (((inputFDouble - 32) * 5) / 9);
    return outputC;
}

/* function for converting C to F with the C function "strtod" */
double c_ctof(const char* str)
{
    string inputC = str;
    char* end;
    double inputCDouble = strtod(str, &end);
    double outputF = (((inputCDouble * 9) / 5) + 32);
    return outputF;
}

/* function for quickly checking whether a string
    is "likely" to be an int or double */
bool isNumber(string &s)
{
    for (int i = 0; i < s.length(); i++) //iterate through all char of string
    {
        if (isdigit(s[i]) == false) //if a char is not a digit
        {
            if (s.find('.') != string::npos) //if a "." is found, it might belong to a double
            {
                return true;
            }
            else return false; //otherwise, this string might not be an int or double
        }
    }

    return true; //if all char are digits, then the string is likely an int
}

/* main function with command-line arguments */
int main(int argc, char** argv)
{
    string inputCommand(argv[1]); //argument for which conversion-function to use
    string inputTemp(argv[2]); //argument for what temperature in degrees to convert

    if (argc > 1) //check if there's at least the name of the program
    {
        if (argc >= 4) //tell the user to only include 2 arguments
        {
            cout << "Please don't input more than two arguments at a time." << endl;
        }
        else if (isNumber(inputTemp)) //if everything is normal, check what conversion-function the user wants
        {
            if (inputCommand == "--ftoc") //the user wants to convert F to C
            {
                const char* inputF = argv[2]; //store the user's temp input as a const char*

                cout << argv[2] << " degrees Fahrenheit is " << cpp_ftoc(inputF)
                    << " degrees Celsius!" << endl; //print out the user's temp value and the conversion
            }
            else if (inputCommand == "--ctof") //the user wants to convert C to F
            {
                const char* inputC = argv[2]; //store the user's temp input as a const char*

                cout << argv[2] << " degrees Celsius is " << c_ctof(inputC)
                    << " degrees Fahrenheit!" << endl; //print out the user's temp value and the conversion
            }
            else
            {
                //the user's first argument is likely to be incorrect, if the program gets to this point
                cout << "Your first argument, 'argv[1]', wasn't understood." << endl;
            }
        }
        else cout << "Your second argument, 'argv[2]', wasn't understood." << endl;
    }

    return 0;
}