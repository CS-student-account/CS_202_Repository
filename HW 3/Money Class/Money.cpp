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
#include <cmath>
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
using std::abs;
using std::round;
using std::fmod;
using std::remainder;

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

ostream& operator<<(ostream& out, const Money& amount)
{
	double temp = amount.money;
	int dollars = round(temp);
	double cents = remainder(temp,100);

	if (amount.money == 0)
	{
		out << "$" << 0 << '.' << left << setfill('0') << setw(2) << 0;
	}
	else if (amount.money > 0)
	{
		if (static_cast<int>(amount.money) == amount.money) 
		{
			out << "$" << 0 << '.' << right << setfill('0') << setw(2) << temp;
		}
		else 
		{
			//'.' << right << setfill('0') << setw(2) << temp
			out << "$" << right << setfill('0') << setw(4) << setprecision(3) << cents;
		}
	}
	else
	{
		if (static_cast<int>(amount.money) == amount.money)
		{
			out << "-$" << 0 << '.' << right << setfill('0') << setw(2) << temp;
		}
		else
		{
			//'.' << right << setfill('0') << setw(2) << temp
			out << "-$" << right << setfill('0') << setw(4) << setprecision(3) << abs(cents);
		}
	}

	return out;
}

bool operator==(const Money &lhs, const Money& rhs)
{
	return (lhs.money == rhs.money);
}

bool operator!=(const Money& lhs, const Money& rhs)
{
	return !(lhs.money == rhs.money);
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
	money -= rhs.money;

	return *this;
}

Money Money::operator*=(const double& rhs)
{
	money *= rhs;

	return *this;
}

Money Money::operator*=(const Money& rhs)
{
	money *= rhs.money;

	return *this;
}

Money Money::operator/=(const double& rhs)
{
	money /= rhs;

	return *this;
}

Money Money::operator/=(const Money& rhs)
{
	money /= rhs.money;

	return *this;
}

Money operator+(const Money& lhs, const Money& rhs)
{
	return Money(lhs.money + rhs.money);
}

Money operator-(const Money& lhs, const Money& rhs)
{
	return Money(lhs.money - rhs.money);
}

Money operator*(const double& lhs, const Money& rhs)
{
	return Money(lhs * rhs.money);
}

Money operator*(const Money& lhs, const double& rhs)
{
	return Money(lhs.money * rhs);
}

Money operator*(const Money& lhs, const Money& rhs)
{
	return Money(lhs.money * rhs.money);
}

Money operator/(const Money& lhs, const double& rhs)
{
	return Money(lhs.money / rhs);
}

Money operator/(const Money& lhs, const Money& rhs)
{
	return Money(lhs.money / rhs.money);
}