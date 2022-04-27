/*
* recursion_main.cpp
* David Misyura
* 26 Apr 2022
* HW 5 for CS 202
*/

#include "recursion.h"
#include "StopWatch.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

int main()
{
    cout << "Recursive fibonacci: fib(0) to fib(6)" << '\n';
    cout << fib(0) << " " << fib(1) << ' ' << fib(2) << ' ' << fib(3) 
        << ' ' << fib(4) << ' ' << fib(5) << ' ' << fib(6)
        << ' ' << fib(7) << ' ' << fib(8) << ' ' << fib(9) << "\n\n";

    cout << "Looping fibonacci: fib_loop(0) to fib_loop(6)" << '\n';
    cout << fib_loop(0) << " " << fib_loop(1) << ' ' << fib_loop(2) << ' ' 
        << fib_loop(3) << ' ' << fib_loop(4) << ' ' << fib_loop(5) << ' ' 
        << fib_loop(6) << ' ' << fib_loop(7) << ' ' << fib_loop(8) << ' ' 
        << fib_loop(9) << "\n\n";

    cout << "Ackermann's number: ack(2,2000)" << '\n';
    cout << ack(2, 2000) << '\n';

#if 0
    /*Ackermann timing tests, maximum n for each m before memory overflow*/
    StopWatch timer1;
    cout << ack(1, 4000);
    timer1.Stop();

    timer1.Start();
    cout << ack(2, 2000);
    timer1.Stop();

    timer1.Start();
    cout << ack(3, 8);
    timer1.Stop();

    timer1.Start();
    cout << ack(4, 0);
    timer1.Stop();
#endif

    return 0;
}