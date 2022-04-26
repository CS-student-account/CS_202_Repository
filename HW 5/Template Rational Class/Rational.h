/*
* Rational.h
* David Misyura
* 26 Apr 2022
* HW 5 for CS 202
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <fstream>
using std::ostream;
using std::ofstream;
using std::ifstream;

template <typename T>
class Rational
{
private:
	T _first, _second;

public:
	Rational() : _first(nullptr), _second(nullptr) {}//default constructor
	Rational(T first, T second) : _first(first), _second(second) {} //parametricized constructor
	~Rational() {} //destructor

	template <typename Y>
	friend ostream& operator<<(ostream& os, const Rational<Y>& object);

	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator!=(const Rational& lhs, const Rational& rhs);
	friend bool operator<(const Rational& lhs, const Rational& rhs);
	friend bool operator<=(const Rational& lhs, const Rational& rhs);
	friend bool operator>(const Rational& lhs, const Rational& rhs);
	friend bool operator>=(const Rational& lhs, const Rational& rhs);

	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	friend Rational operator+(const Rational& lhs, const Rational& rhs);
	friend Rational operator-(const Rational& lhs, const Rational& rhs);
	friend Rational operator*(const Rational& lhs, const Rational& rhs);
	friend Rational operator/(const Rational& lhs, const Rational& rhs);
};

#endif