#include <iostream>
#include "stdafx.h"
#include "birthdate.h"
using namespace std;

bool CBirthDate::operator == (const CBirthDate& otherDate)
{
	return year == otherDate.GetYear() && month == otherDate.GetMonth() && day == otherDate.GetDay();
}

bool CBirthDate::operator > (const CBirthDate& otherDate)
{
	if (year == otherDate.GetYear())
	{
		if (month == otherDate.GetMonth())
		{
			if (day == otherDate.GetDay())
			{
				return false;
			}
			else
			{
				return day > otherDate.GetDay();
			}
		}
		else
		{
			return month > otherDate.GetMonth();
		}
	}
	else
	{
		return year > otherDate.GetYear();
	}
}

bool CBirthDate::operator<(const CBirthDate& otherDate)
{
	if (year == otherDate.GetYear())
	{
		if (month == otherDate.GetMonth())
		{
			if (day == otherDate.GetDay())
			{
				return false;
			}
			else
			{
				return day < otherDate.GetDay();
			}
		}
		else
		{
			return month < otherDate.GetMonth();
		}
	}
	else
	{
		return year < otherDate.GetYear();
	}
}

CBirthDate::CBirthDate()
{
	day = 0;
	month = 0;
	year = 0;
}

CBirthDate::CBirthDate(const CBirthDate& date)
{
	day = date.GetDay();
	month = date.GetMonth();
	year = date.GetYear();
}

CBirthDate::CBirthDate(unsigned int inputDay, unsigned int inputMonth, unsigned int inputYear)
{
	day = inputDay;
	month = inputMonth;
	year = inputYear;
}

unsigned int CBirthDate::GetDay() const
{
	return day;
}

void CBirthDate::SetDay(unsigned int inputDay)
{
	day = inputDay;
}

unsigned int CBirthDate::GetMonth() const
{
	return month;
}

void CBirthDate::SetMonth(unsigned int inputMonth)
{
	month = inputMonth;
}
unsigned int CBirthDate::GetYear() const
{
	return year;
}

void CBirthDate::SetYear(unsigned int inputYear)
{
	year = inputYear;
}

void CBirthDate::operator=(const CBirthDate &date)
{
	day = date.GetDay();
	month = date.GetMonth();
	year = date.GetYear();
}