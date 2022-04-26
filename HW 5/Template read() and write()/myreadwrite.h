/*
* myreadwrite.h
* David Misyura
* 25 Apr 2022
* HW 5 for CS 202
*/

#ifndef MYREADWRITE_H
#define MYREADWRITE_H

#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ostream;
using std::ofstream;
using std::ifstream;

template<typename T>
void myRead(ifstream& ifs, T &temp)
{
	ifs.read(reinterpret_cast<char*>(&temp), sizeof(temp));
}

template<typename Y>
void myWrite(ofstream& ofs, const Y &temp)
{
	ofs.write(reinterpret_cast<const char*>(&temp), sizeof(temp));
}

#endif