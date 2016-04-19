#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "stdafx.h"
#include "birthdate.h"
#include <string>
using namespace std;

class CStudent
{
private:
	string name;
	CBirthDate birthDate;

public:
	CStudent();
	CStudent(string inputName, CBirthDate inputBirthDate);
	CStudent(const CStudent& student);
	string GetName() const;
	void SetName(string inputName);
	CBirthDate GetBirthDate() const;
	void SetBirthDate(CBirthDate inputBirthDate);
	void operator=(const CStudent &student);
	bool operator == (const CStudent& otherStudent);
	bool operator > (const CStudent& student);
	bool operator < (const CStudent& student);

	friend ostream &operator<<(ostream& out, CStudent student)
	{
		return out << student.GetName() << " " << student.GetBirthDate() << endl;
	}

	friend istream &operator>>(istream& in, CStudent& student)
	{
		string name;
		CBirthDate date;
		in >> name >> date;

		student.SetName(name);
		student.SetBirthDate(date);

		return in;
	}
};
#endif