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
    cout << "Recursive fibonacci: fib(0) to fib(20)" << '\n';
    for (int i = 0; i < 21; i++)
    {
        cout << fib(i) << ' ';
    }

    cout << "\n\n" << "Looping fibonacci: fib_loop(0) to fib_loop(20)" << '\n';
    for (int i = 0; i < 21; i++)
    {
        cout << fib_loop(i) << ' ';
    }

    cout << "\n\n" << "Ackermann's number: ack(2,2000)" << '\n';
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