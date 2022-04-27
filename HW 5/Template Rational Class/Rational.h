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
	Rational(T = 0, T = 1); //parametricized constructor
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
	friend Rational<Y> operator+(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator-(const Rational<Y>& lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator*(Rational<Y> lhs, const Rational<Y>& rhs);
	template <typename Y>
	friend Rational<Y> operator/(Rational<Y> lhs, const Rational<Y>& rhs);
};

template<typename T>
Rational<T>::Rational(T num, T den) : _num(num), _den(den) //parametricized constructor
{
	reduce();
}

template<typename T>
void Rational<T>::reduce() 
{
	auto GCD = gcd(_num, _den);
	_num /= GCD;
	_den /= GCD;

	if (_den < 0) 
	{
		_num *= -1;
		_den *= -1;
	}
}

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
	*this = *this - rhs; //uses Rational::operator- to define operator-=
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator*=(const Rational<T>& rhs)
{
	_num *= rhs._num;
	_den *= rhs._den;
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator/=(const Rational<T>& rhs)
{
	return (*this *= {rhs._den, rhs._num});
}


template <typename Y>
Rational<Y> operator+(const Rational<Y>& lhs, const Rational<Y>& rhs)
{
	auto temp{ lhs };
	temp += rhs;
	return temp;
}

template <typename Y>
Rational<Y> operator-(const Rational<Y> &lhs, const Rational<Y>& rhs)
{
	return (lhs + -rhs);
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