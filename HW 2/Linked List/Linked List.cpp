/*
* Linked List.cpp
* David Misyura
* 26 Feb 2022
* HW 2 for CS 202
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <list>
#include <iostream>
#include <random>
using std::string;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::swap;

class Node
{
	public:
		int data;
		Node* next;
};

Node *head, *tail = nullptr; //start and end of linked list
int size = 0; //size of linked list

void pushBack() 
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 50);
	int val = dist(gen); //random int to push into list

	cout << "   " << "Pushing into back of linked list: " << val << endl;

	Node* newNode = new Node();
	newNode->data = val; //random int into data
	newNode->next = nullptr; //the node after the end should be null

	if (head == nullptr) //check if linked list is empty or not
	{
		head = newNode; //if empty, make the new node as head
	}
	else 
	{
		Node* temp = head; 
		while (temp->next != nullptr)//go to last node
		{
			temp = temp->next;
		}

		temp->next = newNode; //node after last gets value
	}
}

void popFront() //delete first element in list
{
	if (head == nullptr)
	{
		head = tail = nullptr;
		cout << "   " << "Linked list empty";
	}
	else
	{
		cout << "   " << "Popped Element At Front!" << endl;
		Node* temp;
		temp = head;
		head = head->next;
		delete(temp); //delete first element in list
	}
}

void popBack() //delete last element in list
{
	Node* prev = nullptr;
	Node* temp = head;
	while (temp->next != nullptr) 
	{
		prev = temp;
		temp = temp->next;
	}

	delete temp; //delete last element in list
	prev->next = nullptr; //the second-last element becomes the new last
	cout << "   " << "Popped Element At Back!" << endl;
}

void sort(Node* &head, Node* it1, Node* it2) //recursive sorting function
{
	if (it2 == nullptr)
	{
		cout << "   " << "Linked list sorted!" << endl;
		return;
	}
	Node* it3 = it1->next;
	while (it3 != nullptr)
	{
		if (it1->data > it3->data)
		{
			//swap adjacent list elements to sort
			swap(it1->data, it3->data);
		}
		it3 = it3->next;
	}
	sort(head, it2, it2->next); //call the function again
}

void find(int target) //find a certain int
{
	Node* current = head;
	cout << "   " << "Searching for " << target;

	while (current != nullptr)
	{
		if (current->data == target)
		{
			cout << ", and found it!" << endl;
			return;
		}

		current = current->next;
	}

	cout << ", but didn't find it." << endl;
}

Node* getNode(int data) //create a specified node for insert()
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

int getSize(Node* head) //get size of list
{
	Node* current = head;
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	return size;
}

void insert(Node** current, int position, int data) //insert an element into list
{
	getSize(head); //get a list's size
	if (position < 1 || position > size + 1) //check if position is correct
	{
		cout << "   " << "Invalid position!" << endl;
	}
	else 
	{
		while (position--) //loop until position is front of list
		{
			if (position == 0) //reached beginning of list
			{
				Node* temp = getNode(data);
				temp->next = *current; //new node points to previous node at the same position
				*current = temp; 
			}
			else
			{
				current = &(*current)->next;
			}
		}
		size++;
	}
}

void display() //print elements of list
{
	Node* temp = head;
	if ((head == nullptr) && (tail == nullptr)) //check for empty list
	{
		cout << "   " << "Linked list empty" << endl;
		return;
	}

	cout << "   " << "Elements are: ";
	while (temp != nullptr) //until the end of the list is reached
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

TEST_CASE("Linked List", "[linked list]")
{
	head = new Node();
	tail = new Node();

	head->data = 1;
	head->next = tail;

	tail->data = 2;
	tail->next = nullptr;

	cout << "[Queue: First-In First-Out]" << endl;
	display();
	pushBack();
	display();
	popFront();
	display();
	REQUIRE(head->data == 2); //simple test

	cout << endl << "[Stack: Last-In First-Out]" << endl;
	display();
	pushBack();
	display();
	popBack();
	display();
	REQUIRE(tail->data == 2); //simple test
	REQUIRE(getSize(head) == 2); //simple test

	cout << endl << "[Insert and Find]" << endl;
	pushBack();
	pushBack();
	pushBack();
	pushBack();
	display();
	sort(head, head, head->next);
	display();
	find(5);
	insert(&head, 3, 777);
	display();
	REQUIRE(getSize(head) == 16); //simple test
}