/*
* box.h
* David Misyura
* 12 Apr 2022
* HW 4 for CS 202
*/

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>
#include <memory>
using std::string;
using std::ostream;
using std::unique_ptr;

/*-----------------------------------------------------------------*/

class Box
{
protected:
	int _width;
	int _height;

public:
	Box(); //default constructor
	Box(int width, int height); //parametricized constructor
	virtual ~Box(); //virtual destructor

	int getWidth() const;
	int getHeight() const;
	void setWidth(int width);
	void setHeight(int height);
	virtual void print(ostream& os) const = 0; //pure virtual print function
	virtual string type() const = 0; //pure virtual function-type function
};

/*-----------------------------------------------------------------*/

/* Global functions */
ostream &operator<<(ostream& os, const Box& b);
unique_ptr<Box> boxFactory(char c, int w, int h); //factory function

/*-----------------------------------------------------------------*/

class FilledBox : public Box
{
public:
	FilledBox(); //default constructor
	FilledBox(int width, int height); //parametricized constructor
	~FilledBox() override; //destructor

	void print(ostream& os) const override; //print filled box
	string type() const override; //function-type function
};

/*-----------------------------------------------------------------*/

class HollowBox : public Box
{
public:
	HollowBox(); //default constructor
	HollowBox(int width, int height); //parametricized constructor
	~HollowBox() override; //destructor

	void print(ostream& os) const override; //print hollow box
	string type() const override; //function-type function
};

/*-----------------------------------------------------------------*/

class CheckeredBox : public Box
{
public:
	CheckeredBox(); //default constructor
	CheckeredBox(int width, int height); //parametricized constructor
	~CheckeredBox() override; //destructor

	void print(ostream& os) const override; //print checkered box
	string type() const override; //function-type function
};

#endif