/*
* box.cpp
* David Misyura
* 12 Apr 2022
* HW 4 for CS 202
*/

#include "box.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stoi;
using std::ostream;

Box::Box() : _width(1), _height(1)
{
	//cout << "Base default Tea constructor!" << endl;
}

Box::Box(int width, int height) : _width(width), _height(height)
{
	//cout << "Base parametricized Tea constructor of " << blend << " blend and " << quantity << " cups!" << endl;
}

Box::~Box()
{
	//cout << "Base Tea destructor!" << endl;
}

int Box::getWidth() const
{

}

int Box::getHeight() const
{

}

void Box::setWidth(int width)
{

}

void Box::setHeight(int height)
{

}

string Box::type() const
{

}

ostream operator<<(ostream& os, const Box& b)
{
	//b.print(os);
	//return os;
}