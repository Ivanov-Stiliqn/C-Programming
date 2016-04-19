#include <iostream>
#include "stdafx.h"
#include "birthdate.h"
#include "student.h"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void PrintStudents(int size, CStudent students[])
{
	for (int i = 0; i < size; i++)
	{
		cout << students[i];
	}
}

void SortAscending(int size, CStudent students[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (students[j].GetBirthDate() > students[j + 1].GetBirthDate())
			{
				CStudent swap = students[j];
				students[j] = students[j + 1];
				students[j + 1] = swap;
			}
		}
	}
}

void SortDescending(int size, CStudent students[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (students[j].GetBirthDate() < students[j + 1].GetBirthDate())
			{
				CStudent swap = students[j];
				students[j] = students[j + 1];
				students[j + 1] = swap;
			}
		}
	}
}

list<CStudent> SearchStudents(int size, CStudent students[], CBirthDate searchDate1, CBirthDate searchDate2)
{

	list<CStudent> searchedStudents;

	for (int i = 0; i < size; i++)
	{
		if ((students[i].GetBirthDate() > searchDate1) && (students[i].GetBirthDate() < searchDate2))
		{

			searchedStudents.push_front(students[i]);
		}
	}

	return searchedStudents;
}

bool FindStudent(int size, CStudent students[], CStudent student)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i] == student)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	//PROBLEM 1 TEST

	/*CBirthDate firstDate(02, 03, 1991);
	CBirthDate secondDate(01, 01, 1991);
	cout << (firstDate == secondDate) << endl;
	cout << firstDate;
	cin >> firstDate;
	cout << firstDate;*/

	//PROBLEM 2 TEST

	//string firstStudentName = "vasko";
	//CBirthDate firstDate(01, 01, 2001);
	//CStudent student1(firstStudentName, firstDate);

	//string secondStudentName = "maira";
	//CBirthDate secondDate(01, 01, 1999);
	//CStudent student2(secondStudentName, secondDate);
	//
	//string thirdStudentName = "gosho";
	//CBirthDate thirdDate(01, 02, 2002);
	//CStudent student3(thirdStudentName, thirdDate);
	//
	////Creating container
	//CStudent students[3] = { student1, student2, student3 };
	//
	//PrintStudents(3, students);
	//cout << endl;
	//cout << "Sorted Ascending:" << endl;
	//SortAscending(3, students);
	//PrintStudents(3, students);
	//cout << endl;
	//cout << "Sorted Descending:" << endl;
	//SortDescending(3, students);
	//PrintStudents(3, students);
	//cout << "Searched students:" << endl;
	//CBirthDate searchDate1(01, 01, 1998);
	//CBirthDate searchDate2(01, 01, 2002);
	//list<CStudent> search = SearchStudents(3, students, searchDate1, searchDate2);
	//for (std::list<CStudent>::iterator it = search.begin(); it != search.end(); ++it)
	//{
	//	std::cout << ' ' << *it;
	//}
	
	string line;
	list<CStudent> people;
	ifstream file("people.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream buf(line);
			istream_iterator<std::string> beg(buf), end;

			vector<std::string> tokens(beg, end);

			string name = tokens[0];
			int day = stoi(tokens[1]);
			int month = stoi(tokens[2]);
			int year = stoi(tokens[3]);
			CBirthDate date(day, month, year);
			CStudent currentStudent(name, date);
			people.push_front(currentStudent);
		}
		file.close();
	}
	else cout << "Unable to open file";

	int size = people.size();
	CStudent* peopleArray = new CStudent[size];
	int index = 0;
	for each (CStudent person in people)
	{
		peopleArray[index] = person;
		index++;
	}

	SortAscending(size, peopleArray);
	PrintStudents(size, peopleArray);
	
	CStudent searchingStudent("Name5", CBirthDate(1, 1, 1988));

	if (FindStudent(size, peopleArray, searchingStudent))
	{
		cout << "Student exists"<<endl;
	}

	return 0;
}
