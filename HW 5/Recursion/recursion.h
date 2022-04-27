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

int fib_loop(int n)
{
	return 0;
}

int ack(int n)
{
	return 0;
}

#endif