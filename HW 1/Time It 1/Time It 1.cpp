/*
* Time It 1.cpp
* David Misyura
* 5 Feb 2022
* HW 1 for CS 202
*/

#include "StopWatch.h"

int main()
{
    //test various vectors with 4 searching algorithms
    int a(10), b(100), c(1'000), d(10'000), e(100'000), 
        f(1'000'000), g(10'000'000), h(100'000'000), i(1'000'000'000);
    
    lookForInt(a);
    lookForInt(b);
    lookForInt(c);
    lookForInt(d);
    lookForInt(e);
    lookForInt(f);
    lookForInt(g);
    lookForInt(h);
    lookForInt(i);

	return 0;
}