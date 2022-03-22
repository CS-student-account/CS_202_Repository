/*
* Money.cpp
* David Misyura
* 20 Mar 2022
* Money.cpp for CS 202
*/

#include "Money.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <typeinfo>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::setw;
using std::left;
using std::right;
using std::setfill;
using std::setprecision;
using std::stoi;
using std::ostream;

Money::Money() : money(0)
{
	return;
}

Money::Money(const int &amount) : money(amount)
{
	return;
}

Money::Money(const double &amount) : money(amount)
{
	return;
}

Money::~Money()
{
	return;
}

ostream& operator<<(ostream& out, const Money& amount)
{
	float temp = amount.money;

	out << "$";

	if (amount.money > 100)
	{
		out << temp/100;
	}
	else if (amount.money < 0)
	{
		out << "-" << temp/100;
	}

	return out;
}

bool operator==(const Money &lhs, const Money& rhs)
{
	return (lhs.money == rhs.money);
}

bool operator!=(const Money& lhs, const Money& rhs)
{
	return (lhs.money != rhs.money);
}

bool operator<(const Money& lhs, const Money& rhs)
{
	return (lhs.money < rhs.money);
}

bool operator<=(const Money& lhs, const Money& rhs)
{
	return (lhs.money <= rhs.money);
}

bool operator>(const Money& lhs, const Money& rhs)
{
	return (lhs.money > rhs.money);
}

bool operator>=(const Money& lhs, const Money& rhs)
{
	return (lhs.money >= rhs.money);
}

Money& Money::operator+=(const Money& rhs)
{
	money += rhs.money;

	return *this;
}

Money Money::operator-=(const Money& rhs)
{
	return;
}

Money Money::operator*=(const Money& rhs)
{
	return;
}

Money Money::operator/=(const Money& rhs)
{
	return;
}

Money Money::operator+(const Money& rhs)
{
	Money out = *this;

	if (out.money > 0)
	{
		out.money += rhs.money;
	}

	if (out.money > 0)
	{
		out.money += rhs.money;
	}

	return out;
}

Money Money::operator-(const Money& rhs)
{
	return;
}

Money Money::operator*(const Money& rhs)
{
	return;
}

Money Money::operator/(const Money& rhs)
{
	return;
}