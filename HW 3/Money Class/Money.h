#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <vector>
using std::string;
using std::ostream;

class Money
{
private:
	float money;
	
public:
	Money();
	Money(const int &amount);
	Money(const float &amount);
	~Money();
	friend ostream& operator<<(ostream& out, const Money& amount);
	Money& operator+=(const Money& rhs);
	Money operator+(const Money& rhs);
};
#endif 