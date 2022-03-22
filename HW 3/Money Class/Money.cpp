/*
* Money.cpp
* David Misyura
* 20 Mar 2022
* Money.cpp for CS 202
*/

#include "Money.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using std::setw;
using std::right;
using std::setfill;
using std::setprecision;
using std::ostream;
using std::abs;
using std::remainder;

/* Constructors and Destructor */
Money::Money() : money(0.00)
{

}

Money::Money(const int &amount) : money(amount)
{

}

Money::Money(const double &amount) : money(amount)
{

}

Money::~Money()
{

}

/* Ostream Operator */
ostream &operator<<(ostream &out, const Money &amount)
{
	//gives dollars and cents if double is given, otherwise performs modulus to give cents
	double cash = remainder(amount.money, 100);

	if (amount.money == 0)
	{
		out << "$0.00";
	}
	else if (amount.money > 0) //positive amount
	{
		if (static_cast<int>(amount.money) == amount.money) //if int, which are just cents
		{
			out << "$0" << '.' << right << setfill('0') <<setw(2) << cash;
		}
		else //otherwise, dollars and cents are given
		{
			out << "$" << right << setfill('0') << setprecision(3) << cash;
		}
	}
	else //else if negative amount
	{
		if (static_cast<int>(amount.money) == amount.money) //if int, which are just cents
		{
			out << "-$0" << '.' << right << setfill('0') << setw(2) << abs(cash);
		}
		else //otherwise, dollars and cents are given
		{
			out << "-$" << right << setfill('0') << setprecision(3) << abs(cash);
		}
	}

	return out;
}

/* Equality Operators */
bool operator==(const Money &lhs, const Money &rhs)
{
	return (lhs.money == rhs.money);
}

bool operator!=(const Money &lhs, const Money &rhs)
{
	return !(lhs.money == rhs.money);
}

bool operator<(const Money &lhs, const Money &rhs)
{
	return (lhs.money < rhs.money);
}

bool operator<=(const Money &lhs, const Money &rhs)
{
	return (lhs.money <= rhs.money);
}

bool operator>(const Money &lhs, const Money &rhs)
{
	return (lhs.money > rhs.money);
}

bool operator>=(const Money &lhs, const Money &rhs)
{
	return (lhs.money >= rhs.money);
}

/* Relational Operators */
Money &Money::operator+=(const Money &rhs)
{
	money += rhs.money;

	return *this;
}

Money &Money::operator-=(const Money &rhs)
{
	money -= rhs.money;

	return *this;
}

Money &Money::operator*=(const double &rhs)
{
	money *= rhs;

	return *this;
}

Money &Money::operator*=(const Money &rhs)
{
	money *= rhs.money;

	return *this;
}

Money &Money::operator/=(const double &rhs)
{
	money /= rhs;

	return *this;
}

/* Arithmetic Operators */
Money operator+(const Money &lhs, const Money &rhs)
{
	return Money(lhs.money + rhs.money);
}

Money operator-(const Money &lhs, const Money &rhs)
{
	return Money(lhs.money - rhs.money);
}

Money operator*(const double &lhs, const Money &rhs)
{
	return Money(lhs * rhs.money);
}

Money operator*(const Money &lhs, const double &rhs)
{
	return Money(lhs.money * rhs);
}

Money operator/(const Money &lhs, const double &rhs)
{
	return Money(lhs.money / rhs);
}

Money operator/(const Money &lhs, const Money &rhs)
{
	return Money(lhs.money / rhs.money);
}