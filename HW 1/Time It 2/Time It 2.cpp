/*
* Time It 2.cpp
* David Misyura
* 8 Feb 2022
* HW 1 for CS 202
*/

#include "StopWatch.h"
#include <string>
using std::string;

int main()
{
	/* timing how long it takes to copy a book into 3 types of containers,
	to find a random string from each container, and to sort each container */

	string book1("book1.txt"), book2("book2.txt"), 
		book3("book3.txt"), book4("book4.txt"), book5("book5.txt");

	timeIt2(book1);
	timeIt2(book2);
	timeIt2(book3);
	timeIt2(book4);
	timeIt2(book5);

    return 0;
}