#ifndef BIRTHDATE_H
#define BIRTHDATE_H
#include <iostream>
#include "stdafx.h"
using namespace std;

class CBirthDate
{
public:
	CBirthDate();
	CBirthDate(const CBirthDate& date);
	CBirthDate(unsigned int inputDay, unsigned int inputMonth, unsigned int inputYear);
	unsigned int GetDay() const;
	void SetDay(unsigned int day);
	unsigned int GetMonth() const;
	void SetMonth(unsigned int month);
	unsigned int GetYear() const;
	void SetYear(unsigned int year);
	bool operator == (const CBirthDate& otherDate);
	bool operator > (const CBirthDate& otherDate);
	bool operator < (const CBirthDate& otherDate);
	void operator = (const CBirthDate& date);

	friend ostream &operator<<(ostream& out, const CBirthDate& date)
	{
		return out << date.GetDay() << '/' << date.GetMonth() << '/' << date.GetYear() << endl;
	}

	friend istream &operator>>(istream& in, CBirthDate& date)
	{
		unsigned int day;
		unsigned int month;
		unsigned int year;
		in >> day >> month >> year;
		date.SetDay(day);
		date.SetMonth(month);
		date.SetYear(year);

		return in;
	}

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
#endif