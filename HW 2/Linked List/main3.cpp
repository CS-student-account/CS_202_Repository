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

class Node
{
public:
	int data;
	Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;
Node* temp;

void insert()
{
	int val = 25;
	cout << "Inserting into queue: " << val << endl;
	if (tail == nullptr)
	{
		tail = (class Node*)malloc(sizeof(class Node));
		tail->next = nullptr;
		tail->data = val;
		head = tail;
	}
	else
	{
		temp = (class Node*)malloc(sizeof(class Node));
		tail->next = temp;
		temp->data = val;
		temp->next = nullptr;
		tail = temp;
	}
}

void Delete()
{
	temp = tail;
	if (head == nullptr)
	{
		cout << "Underflow" << endl;
	}
	else
	{
		if (temp->next != nullptr)
		{
			temp = temp->next;
			cout << "Element deleted from queue is : " << head->data << endl;
			free(head);
			head = temp;
		}
		else
		{
			cout << "Element deleted from queue is : " << head->data << endl;
			free(head);
			head = nullptr;
			tail = nullptr;
		}
	}
}

void popFront()
{
	if (head == nullptr)
	{
		head = tail = nullptr;
		cout << "Queue is Empty";
	}
	else
	{
		temp = head;
		head = head->next;
		delete(temp);
	}
}

void popBack()
{
	if (head->next == nullptr) 
	{
		delete head;
		head = nullptr;
	}
	else 
	{
		Node* penultimate = head;
		Node* tail = head->next;
		while (tail->next != nullptr) 
		{
			penultimate = tail;
			tail = tail->next;
		}
		delete tail;
		penultimate->next = nullptr;
	}
}

void display()
{
	temp = head;
	if ((head == nullptr) && (tail == nullptr))
	{
		cout << "Queue is empty" << endl;
		return;
	}

	cout << "Queue elements are: ";
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	head = new Node();
	tail = new Node();

	head->data = 1;
	head->next = tail;

	tail->data = 6;
	tail->next = nullptr;

	display();
	insert();
	display();
	popBack();
	popFront();
	display();

	return 0;
}