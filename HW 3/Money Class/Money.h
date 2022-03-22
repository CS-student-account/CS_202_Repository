#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <vector>
using std::string;
using std::ostream;

class Money
{
private:
	double money;
	
public:
	Money();
	Money(const int &amount);
	Money(const double &amount);
	~Money();
	friend ostream& operator<<(ostream& out, const Money& amount);

	friend bool operator==(const Money& lhs, const Money& rhs);
	friend bool operator!=(const Money& lhs, const Money& rhs);
	friend bool operator<(const Money& lhs, const Money& rhs);
	friend bool operator<=(const Money& lhs, const Money& rhs);
	friend bool operator>(const Money& lhs, const Money& rhs);
	friend bool operator>=(const Money& lhs, const Money& rhs);

	Money& operator+=(const Money& rhs);
	Money operator-=(const Money& rhs);
	Money operator*=(const Money& rhs);
	Money operator/=(const Money& rhs);

	friend Money operator+(const Money& lhs, const Money& rhs);
	friend Money operator-(const Money& lhs, const Money& rhs);
	friend Money operator*(const double& lhs, const Money& rhs);
	friend Money operator*(const Money& lhs, const double& rhs);
	friend Money operator*(const Money& lhs, const Money& rhs);
	friend Money operator/(const Money& lhs, const Money& rhs);
};
#endif 