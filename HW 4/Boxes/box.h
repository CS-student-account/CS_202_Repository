/*
* box.h
* David Misyura
* 12 Apr 2022
* HW 4 for CS 202
*/

#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Box
{
protected:
	int _width;
	int _height;
	string _type;

public:
	Box(); //default constructor
	Box(int width, int height); //parametricized constructor
	~Box(); //destructor

	int getWidth() const;
	int getHeight() const;
	void setWidth(int width);
	void setHeight(int height);
	virtual void print(ostream& os) = 0;
	virtual string type() = 0;
};

ostream operator<<(ostream& os, const Box& b);

class FilledBox : public Box
{
protected:
	int _width;
	int _height;
	string _type;

public:
	FilledBox(); //default constructor
	FilledBox(int width, int height); //parametricized constructor
	~FilledBox(); //destructor

	int getWidth() const;
	int getHeight() const;
	int setWidth(int width);
	int setHeight(int height);
	string type() const;
};

class HollowBox : public Box
{
protected:

public:
	HollowBox(); //default constructor
	HollowBox(int width, int height); //parametricized constructor
	~HollowBox(); //destructor
};

class CheckeredBox : public Box
{
protected:

public:
	CheckeredBox(); //default constructor
	CheckeredBox(int width, int height); //parametricized constructor
	~CheckeredBox(); //destructor
};

#endif