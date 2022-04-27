/*
* Rational.h
* David Misyura
* 26 Apr 2022
* HW 5 for CS 202
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>
using std::ostream;
using std::gcd;

template <typename T>
class Rational
{
private:
	T _num, _den;
	void reduce();

public:

	Rational(T num = 0, T den = 1) : _num(num), _den(den) //parametricized constructor
	{
		reduce();
	}
	~Rational() {} //destructor

	template <typename Y>
	friend ostream& operator<<(ostream& os, const Rational<Y>& rhs);

	template <typename Y>
	friend Rational<Y> operator-(const Rational<Y>& lhs);

	template <typename Y>
	friend bool operator==(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend bool operator!=(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend bool operator<(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend bool operator<=(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend bool operator>(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend bool operator>=(const Rational<Y>& lhs, const Rational<Y>& rhs);


	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	template <typename Y>
	friend Rational<Y> operator+(Rational<Y> lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator-(Rational<Y> lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator*(Rational<Y> lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator/(Rational<Y> lhs, const Rational<Y>& rhs);
};

/*--------------------------reduce() function----------------------------*/
template<typename T>
void Rational<T>::reduce() 
{
	auto greatestCommonDen = gcd(_num, _den);
	_num /= greatestCommonDen;
	_den /= greatestCommonDen;

	if (_den < 0) 
	{
		_num *= -1;
		_den *= -1;
	}
}

/*----------------------Ostream & Negation Operators----------------------*/
template <typename Y>
ostream& operator<<(ostream& os, const Rational<Y>& rhs)
{
	os << rhs._num;
	
	if (rhs._den != 1)
	{
		os << "/" << rhs._den;
	}

	return os;
}

template <typename Y>
Rational<Y> operator-(const Rational<Y>& lhs)
{
	return {-lhs._num, lhs._den};
}

/*--------------------------Equality Operators------------------------------*/
template <typename Y>
bool operator==(const Rational<Y>& lhs, const Rational<Y>& rhs) 
{
	return (lhs._num == rhs._num && lhs._den == rhs._den);
}

template <typename Y>
bool operator!=(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	return !(rhs == lhs);
}

template <typename Y>
bool operator<(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	return (lhs._num * rhs._den < rhs._num * lhs._den);
}

template <typename Y>
bool operator<=(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	return !(rhs > lhs);
}

template <typename Y>
bool operator>(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	return (rhs < lhs);
}

template <typename Y>
bool operator>=(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	return !(rhs < lhs);
}

/*------------------------Relational Operators------------------------------*/
template <typename T>
Rational<T>& Rational<T>::operator+=(const Rational<T>& rhs)
{
	_num = (_num * rhs._den) + (rhs._num * _den);
	_den *= rhs._den;
	reduce();
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator-=(const Rational<T>& rhs)
{
	*this = *this + -rhs;
	reduce();
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator*=(const Rational<T>& rhs)
{
	_num *= rhs._num;
	_den *= rhs._den;
	reduce();
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator/=(const Rational<T>& rhs)
{
	*this *= {rhs._den, rhs._num};
	reduce();
	return *this;
}

/*------------------------Arithmetic Operators------------------------------*/
template <typename Y>
Rational<Y> operator+(Rational<Y> lhs, const Rational<Y>& rhs)
{
	return (lhs += rhs);
}

template <typename Y>
Rational<Y> operator-(Rational<Y> lhs, const Rational<Y>& rhs)
{
	return (lhs -= rhs);
}

template <typename Y>
Rational<Y> operator*(Rational<Y> lhs, const Rational<Y>& rhs)
{
	return (lhs *= rhs);
}

template <typename Y>
Rational<Y> operator/(Rational<Y> lhs, const Rational<Y>& rhs)
{
	return (lhs /= rhs);
}

#endif