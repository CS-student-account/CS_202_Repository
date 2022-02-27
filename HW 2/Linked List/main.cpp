/*
* Linked List.cpp
* David Misyura
* 26 Feb 2022
* HW 2 for CS 202
*/

/*#include <string>
#include <list>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Structure
{
public:
	int data1;

	Structure* next;
};

Structure* first = nullptr;
Structure* second = nullptr;
Structure* third = nullptr;
Structure* fourth = nullptr;
Structure* fifth = nullptr;
Structure* sixth = nullptr;
Structure* temp;

void insert() 
{
	int val = 25;
	cout << "Inserting into queue: " << val << endl;
	if (sixth == nullptr) 
	{
		sixth = (class Structure*)malloc(sizeof(class Structure));
		sixth->next = nullptr;
		sixth->data1 = val;
		first = sixth;
	}
	else 
	{
		temp = (class Structure*)malloc(sizeof(class Structure));
		sixth->next = temp;
		temp->data1 = val;
		temp->next = nullptr;
		sixth = temp;
	}
}

void Delete() 
{
	temp = sixth;
	if (first == nullptr) 
	{
		cout << "Underflow" << endl;
	}
	else
	{
		if (temp->next != nullptr)
		{
			temp = temp->next;
			cout << "Element deleted from queue is : " << first->data1 << endl;
			free(first);
			first = temp;
		}
		else
		{
			cout << "Element deleted from queue is : " << first->data1 << endl;
			free(first);
			first = nullptr;
			sixth = nullptr;
		}
	}
}

void deleteFront()  // for deletion from front
{
	if (first == nullptr)
		cout << "Queue is Empty";
	else
	{
		temp = first;
		first = first->next;
		delete temp;
		sixth = nullptr;
	}
}

void deleteRear()  // for deletion from front
{
	if (first == nullptr)
		cout << "Queue is Empty";
	else
	{
		temp = sixth;
		delete temp;
	}
}

void display() 
{
	temp = first;
	if ((first == nullptr) && (sixth == nullptr)) 
	{
		cout << "Queue is empty" << endl;
		return;
	}

	cout << "Queue elements are: ";
	while (temp != nullptr) 
	{
		cout << temp->data1 << " ";
		temp = temp->next;
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

	first->data1 = 1;
	first->next = second;

	second->data1 = 2;
	second->next = third;

	third->data1 = 3;
	third->next = fourth;

	fourth->data1 = 4;
	fourth->next = fifth;

	fifth->data1 = 5;
	fifth->next = sixth;

	sixth->data1 = 6;
	sixth->next = nullptr;

	display();
	insert();
	display();
	deleteFront();
	display();
	deleteRear();
	display();

	return 0;
}*/