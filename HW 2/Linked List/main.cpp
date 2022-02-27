/*
* Linked List.cpp
* David Misyura
* 26 Feb 2022
* HW 2 for CS 202
*/

#include <string>
#include <list>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

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

Structure* first = nullptr;
Structure* second = nullptr;
Structure* third = nullptr;
Structure* fourth = nullptr;
Structure* fifth = nullptr;
Structure* sixth = nullptr;
Structure* temp;

void Insert() {
	int val = 25;
	cout << "Insert the element in queue: " << val << endl;
	if (sixth == nullptr) 
	{
		sixth = (class Structure*)malloc(sizeof(class Structure));
		sixth->next = nullptr;
		sixth->test1 = val;
		first = sixth;
	}
	else {
		temp = (class Structure*)malloc(sizeof(class Structure));
		sixth->next = temp;
		temp->test1 = val;
		temp->next = nullptr;
		sixth = temp;
	}
}

void printList(Structure* n) 
{
	while (n != nullptr) 
	{
		cout << n->test1 << " ";
		n = n->next;
	}
	cout << endl;
}

int main()
{
	first = new Structure();
	second = new Structure();
	third = new Structure();
	fourth = new Structure();
	fifth = new Structure();
	sixth = new Structure();

	first->test1 = 1;
	first->next = second;

	second->test1 = 2;
	second->next = third;

	third->test1 = 3;
	third->next = fourth;

	fourth->test1 = 4;
	fourth->next = fifth;

	fifth->test1 = 5;
	fifth->next = sixth;

	sixth->test1 = 6;
	sixth->next = nullptr;


	Insert();
	printList(first);

	return 0;
}