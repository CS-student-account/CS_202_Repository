/*
* Memory List.cpp
* David Misyura
* 27 Feb 2022
* HW 2 for CS 202
*/

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int staticData;

int main()
{
    const int codeData = 1;

    int* freeMemory = nullptr;
    freeMemory = new int;

    int stackData;

    if (&staticData > &stackData)
    {
        cout << "Static data is in higher memory than the Stack." << endl;

        if (&staticData > &codeData)
        {
            cout << "Static data is in higher memory than Code data." << endl;
        }

        if (&staticData > freeMemory)
        {
            cout << "Static data is in higher memory than the free memory." << endl;
        }
    }

    if (&stackData > &codeData)
    {
        cout << "Stack is in higher memory than the Code data." << endl;

        if (&stackData < freeMemory)
        {
            cout << "Stack is in lower memory than the free memory." << endl;
        }
    }

    if (&codeData < freeMemory)
    {
        cout << "Code data is in lower memory than the free memory." << endl;
    }

    cout << endl << "Thus, the memory layout of this program is: " << endl
        << "static data > " << "free memory > " << "stack > " << "code data" << endl;

    delete freeMemory;
    return 0;
}