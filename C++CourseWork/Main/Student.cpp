#include <iostream>
#include "stdafx.h"
#include "birthdate.h"
#include "student.h"
using namespace std;

CStudent::CStudent(const CStudent& student)
{
	name = student.GetName();
	birthDate = student.GetBirthDate();
}

CStudent::CStudent()
{
	name = "";
	CBirthDate date(0, 0, 0);
	birthDate = date;
}

CStudent::CStudent(string inputName, CBirthDate inputDate)
{
	name = inputName;
	birthDate = inputDate;
}

string CStudent::GetName() const
{
	return name;
}

void CStudent::SetName(string inputName)
{
	name = inputName;
}

CBirthDate CStudent::GetBirthDate() const
{
	return birthDate;
}

void CStudent::SetBirthDate(CBirthDate inputBirthDate)
{
	birthDate = inputBirthDate;
}

void CStudent::operator=(const CStudent &student)
{
	name = student.GetName();
	birthDate = student.GetBirthDate();
}

bool CStudent::operator == (const CStudent& otherStudent)
{
	return name == otherStudent.GetName() && birthDate == otherStudent.GetBirthDate();
}
bool CStudent::operator > (const CStudent& otherStudent)
{
	return (birthDate > otherStudent.GetBirthDate());
};

bool CStudent::operator < (const CStudent& otherStudent)
{
	return (birthDate < otherStudent.GetBirthDate());
};