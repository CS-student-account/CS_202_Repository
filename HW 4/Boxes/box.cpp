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
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stoi;
using std::ostream;
using std::unique_ptr;
using std::make_unique;

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

ostream &operator<<(ostream& os, const Box& b)
{
	b.print(os);
	return os;
}

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

/*--------------------------------------------------------------------*/

FilledBox::FilledBox(){}

FilledBox::FilledBox(int width, int height) : Box(width, height){}

FilledBox::~FilledBox(){}

void FilledBox::print(ostream& os) const
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

string FilledBox::type() const
{
	return "Filled";
}

/*--------------------------------------------------------------------*/

HollowBox::HollowBox(){}

HollowBox::HollowBox(int width, int height) : Box(width, height) {}

HollowBox::~HollowBox(){}

void HollowBox::print(ostream& os) const
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

string HollowBox::type() const
{
	return "Hollow";
}

/*--------------------------------------------------------------------*/

CheckeredBox::CheckeredBox(){}

CheckeredBox::CheckeredBox(int width, int height) : Box(width, height) {}

CheckeredBox::~CheckeredBox(){}

void CheckeredBox::print(ostream& os) const
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

string CheckeredBox::type() const
{
	return "Checkered";
}