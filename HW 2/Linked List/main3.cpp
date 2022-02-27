/*
* Linked List.cpp
* David Misyura
* 26 Feb 2022
* HW 2 for CS 202
*/

#include <string>
#include <list>
#include <iostream>
#include <random>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::swap;
using std::istringstream;

class Node
{
	public:
		int data;
		Node* next;
};

Node *head, *tail = nullptr;

void pushBack() 
{
	random_device rd;
	mt19937 gen(rd());  // PRNG, randomly seeded
	uniform_int_distribution<int> dist(1, 50);
	int val = dist(gen);

	cout << "Pushing into back of linked list: " << val << endl;

	//1. allocate node
	Node* newNode = new Node();

	//2. assign data element
	newNode->data = val;

	//3. assign null to the next of new node
	newNode->next = NULL;

	//4. Check the Linked List is empty or not,
	//   if empty make the new node as head 
	if (head == NULL) 
	{
		head = newNode;
	}
	else {

		//5. Else, traverse to the last node
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		//6. Change the next of last node to new node
		temp->next = newNode;
	}
}

void popFront()
{
	if (head == nullptr)
	{
		head = tail = nullptr;
		cout << "Linked list empty";
	}
	else
	{
		cout << "Popped Element At Front!" << endl;
		Node* temp;
		temp = head;
		head = head->next;
		delete(temp);
	}
}

void popBack() 
{
	Node* prev = nullptr;
	Node* temp = head;
	while (temp->next != nullptr) 
	{
		prev = temp;
		temp = temp->next;
	}

	delete temp;
	prev->next = nullptr;
	cout << "Popped Element At Back!" << endl;
}

void sort(Node* &head, Node* p1, Node* p2)
{
	if (p2 == nullptr)
	{
		return;
	}
	Node* p3 = p1->next;
	while (p3 != nullptr)
	{
		if (p1->data > p3->data)
		{
			swap(p1->data, p3->data);
		}
		p3 = p3->next;
	}
	sort(head, p2, p2->next);
}

void display()
{
	Node* temp = head;
	if ((head == nullptr) && (tail == nullptr))
	{
		cout << "Linked list empty" << endl;
		return;
	}

	cout << "Elements are: ";
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

	tail->data = 2;
	tail->next = nullptr;

	cout << "[Queue]" << endl;
	display();
	pushBack();
	display();
	popFront();
	display();

	cout << endl << "[Stack]" << endl;
	display();
	pushBack();
	display();
	popBack();
	display();

	cout << endl << "[Insert and Find]" << endl;
	pushBack();
	pushBack();
	pushBack();
	pushBack();
	sort(head, head, head->next);
	cout << "Linked list sorted!" << endl;
	display();

	return 0;
}