/*
* Time It 2.cpp
* David Misyura
* 8 Feb 2022
* HW 1 for CS 202
*/

#include "StopWatch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <time.h>
#include <stdlib.h>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;

int main()
{
	string book1("book1.txt"), book2("book2.txt"), 
		book3("book3.txt"), book4("book4.txt"), book5("book5.txt");

	timeIt2(book1);
	timeIt2(book2);
	timeIt2(book3);
	timeIt2(book4);
	timeIt2(book5);

    return 0;
}