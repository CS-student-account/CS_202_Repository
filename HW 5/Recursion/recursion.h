/*
* recursion.h
* David Misyura
* 26 Apr 2022
* HW 5 for CS 202
*/

#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
using std::ostream;
using std::cout;

int fib(int n)
{
	if (n <= 1) 
	{
		return n;
	}
	else 
	{
		return(fib(n-1) + fib(n-2));
	}
}

void fib_loop(int n)
{
	int term1 = 0, term2 = 1, termNext;

    for (int i = 0; i < n - 1; i++) 
    {
        if (i == 0) 
        {
            cout << 0 << ' ';
        }

        if (i == 1) 
        {
            cout << 1 << ' ';
        }

        termNext = term1 + term2;
        term1 = term2;
        term2 = termNext;

        cout << termNext << ' ';
    }
}

int ack(int m, int n)
{
    if (m == 0) 
    {
        return (n+1);
    }
    else if ((m > 0) && (n == 0))
    {
        return ack(m - 1, 1);
    }
    else if ((m > 0) && (n > 0))
    {
        return ack(m-1, ack(m, n-1));
    }
}

#endif