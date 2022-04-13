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
#include <memory>
using std::string;
using std::ostream;
using std::unique_ptr;

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
	virtual void print(ostream& os) const = 0;
	virtual string type() = 0;
};

ostream &operator<<(ostream& os, const Box& b);
unique_ptr<Box> boxFactory(char c, int w, int h);



class FilledBox : public Box
{
public:
	FilledBox(); //default constructor
	FilledBox(int width, int height); //parametricized constructor
	~FilledBox(); //destructor

	void print(ostream& os) const;
	string type();
};


class HollowBox : public Box
{
public:
	HollowBox(); //default constructor
	HollowBox(int width, int height); //parametricized constructor
	~HollowBox(); //destructor

	void print(ostream& os) const;
	string type();
};


class CheckeredBox : public Box
{
public:
	CheckeredBox(); //default constructor
	CheckeredBox(int width, int height); //parametricized constructor
	~CheckeredBox(); //destructor

	void print(ostream& os) const;
	string type();
};

#endif