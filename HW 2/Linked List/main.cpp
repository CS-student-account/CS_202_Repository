/*
* Linked List.cpp
* David Misyura
* 26 Feb 2022
* HW 2 for CS 202
*/

#include <string>
#include <list>
using std::string;

class Structure
{
public:
	int test1;
	string test2;
	double test3;
	char test4;
	float test5;

	Structure* next;
};

int main()
{
	Structure* first = nullptr;
	Structure* second = nullptr;
	Structure* third = nullptr;

	first = new Structure();
	second = new Structure();
	third = new Structure();

	return 0;
}