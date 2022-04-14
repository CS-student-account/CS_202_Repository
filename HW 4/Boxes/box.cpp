/*
* box.cpp
* David Misyura
* 12 Apr 2022
* HW 4 for CS 202
*/

#include "box.h"
#include <iostream>
#include <string>
#include <memory>
using std::string;
using std::ostream;
using std::unique_ptr;

/*-----------------------------------------------------------------*/

Box::Box() : _width(1), _height(1){}
Box::Box(int width, int height) : _width(width), _height(height){}
Box::~Box(){}

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

/*-----------------------------------------------------------------*/

ostream &operator<<(ostream& os, const Box& b) //global ostream << operator
{
	b.print(os);
	return os;
}

//global factory function returning unique pointer of appropriate type of box
unique_ptr<Box> boxFactory(char c, int w, int h)
{
	switch (c)
	{
	case 'f':
		return unique_ptr<Box>(new FilledBox(w, h));

	case 'h':
		return unique_ptr<Box>(new HollowBox(w, h));

	case 'c':
		return unique_ptr<Box>(new CheckeredBox(w, h));
	}
}

/*-----------------------------------------------------------------*/

FilledBox::FilledBox(){}
FilledBox::FilledBox(int width, int height) : Box(width, height){}
FilledBox::~FilledBox(){}

void FilledBox::print(ostream& os) const //print filled box
{
	for (int j = 0; j < _height; j++) //iterate through rows
	{
		for (int i = 0; i < _width; i++) //iterate through columns
		{
			os << 'x'; //character visualizing box
		}
		os << '\n'; //new line after a row is processed
	}
}

string FilledBox::type() const //get type of box function
{
	return "Filled";
}

/*-----------------------------------------------------------------*/

HollowBox::HollowBox(){}
HollowBox::HollowBox(int width, int height) : Box(width, height){}
HollowBox::~HollowBox(){}

void HollowBox::print(ostream& os) const //print hollow box
{
	for (int j = 1; j <= _height; j++) //iterate through rows
	{
		if (j == 1 || j == _height) //top or bottom of box
		{
			for (int i = 1; i <= _width; i++) //iterate through columns
			{
				os << 'x'; //character visualizing box
			}
		}
		else
		{
			for (int i = 1; i <= _width; i++) //iterate through columns
			{
				if (i == 1 || i == _width) //left or right edge of box
				{
					os << 'x'; //character visualizing box
				}
				else //inside of box
				{
					os << ' '; //empty space inside box
				}
			}
		}
		os << '\n'; //new line after a row is processed
	}
}

string HollowBox::type() const //get type of box function
{
	return "Hollow";
}

/*-----------------------------------------------------------------*/

CheckeredBox::CheckeredBox(){}
CheckeredBox::CheckeredBox(int width, int height) : Box(width, height){}
CheckeredBox::~CheckeredBox(){}

void CheckeredBox::print(ostream& os) const //print checkered box
{
	for (int j = 0; j < _height; j++) //iterate through rows
	{
		if (j % 2 == 0) //even row
		{
			for (int i = 0; i < _width; i++) //iterate through columns
			{
				if (i % 2 == 0) //even column
				{
					os << 'x'; //character visualizing box
				}
				else //odd column
				{
					os << ' '; //empty space inside box
				}
			}
		}
		else //odd row
		{
			for (int i = 0; i < _width; i++) //iterate through columns
			{
				if (i % 2 == 0) //even column
				{
					os << ' '; //empty space inside box
				}
				else //odd column
				{
					os << 'x'; //character visualizing box
				}
			}
		}
		os << '\n'; //new line after a row is processed
	}
}

string CheckeredBox::type() const //get type of box function
{
	return "Checkered";
}