/*
* myreadwrite.h
* David Misyura
* 25 Apr 2022
* HW 5 for CS 202
*/

#ifndef MYREADWRITE_H
#define MYREADWRITE_H

#include <fstream>
using std::ofstream;
using std::ifstream;

template<typename T>
void myRead(ifstream& ifs, T &temp) //read in file
{
	ifs.read(reinterpret_cast<char*>(&temp), sizeof(temp));
}

template<typename T>
void myWrite(ofstream& ofs, const T &temp) //write to file
{
	ofs.write(reinterpret_cast<const char*>(&temp), sizeof(temp));
}

#endif