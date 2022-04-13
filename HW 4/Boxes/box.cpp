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
	return _width;
}

int Box::getHeight() const
{
	return _height;
}

void Box::setWidth(int width)
{
	_width = width;
}

void Box::setHeight(int height)
{
	_height = height;
}

ostream operator<<(ostream& os, const Box& b)
{
	//b.print(os);
	//return os;
}

/*--------------------------------------------------------------------*/

FilledBox::FilledBox()
{
	//cout << "Base default Tea constructor!" << endl;
}

FilledBox::FilledBox(int width, int height)
{
	//cout << "Base parametricized Tea constructor of " << blend << " blend and " << quantity << " cups!" << endl;
}

FilledBox::~FilledBox()
{
	//cout << "Base Tea destructor!" << endl;
}

void FilledBox::print(ostream& os)
{
	for (int j = 0; j < _height; j++)
	{
		for (int i = 0; i < _width; i++)
		{
			os << 'x';
		}
		os << '\n';
	}
}

string FilledBox::type()
{
	return "Filled";
}

/*--------------------------------------------------------------------*/

HollowBox::HollowBox()
{
	//cout << "Base default Tea constructor!" << endl;
}

HollowBox::HollowBox(int width, int height)
{
	//cout << "Base parametricized Tea constructor of " << blend << " blend and " << quantity << " cups!" << endl;
}

HollowBox::~HollowBox()
{
	//cout << "Base Tea destructor!" << endl;
}

void HollowBox::print(ostream& os)
{
	for (int j = 0; j < _height; j++)
	{
		for (int i = 0; i < _width; i++)
		{
			os << 'x';
		}
		os << '\n';
	}
}

string HollowBox::type()
{
	return "Hollow";
}

/*--------------------------------------------------------------------*/

CheckeredBox::CheckeredBox()
{
	//cout << "Base default Tea constructor!" << endl;
}

CheckeredBox::CheckeredBox(int width, int height)
{
	//cout << "Base parametricized Tea constructor of " << blend << " blend and " << quantity << " cups!" << endl;
}

CheckeredBox::~CheckeredBox()
{
	//cout << "Base Tea destructor!" << endl;
}

void CheckeredBox::print(ostream& os)
{
	for (int j = 0; j < _height; j++)
	{
		for (int i = 0; i < _width; i++)
		{
			os << 'x';
		}
		os << '\n';
	}
}

string CheckeredBox::type()
{
	return "Checkered";
}