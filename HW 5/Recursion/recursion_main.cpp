/*
* recursion_main.cpp
* David Misyura
* 26 Apr 2022
* HW 5 for CS 202
*/

#include "recursion.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

int main()
{
    cout << "Recursive fibonacci: fib(n)" << '\n';
    cout << fib(0) << " " << fib(1) << ' ' << fib(2) << ' ' << fib(3) 
        << ' ' << fib(4) << ' ' << fib(5) << ' ' << fib(6) << '\n';
    return 0;
}