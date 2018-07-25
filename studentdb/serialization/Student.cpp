#include "StdAfx.h"
#include "Student.h"
#include <iostream>
#include <string>


Student::Student(std::string indexNo, std::string firstName, std::string lastName, float averageGrade)
: IndexNo(indexNo), FirstName(firstName), LastName(lastName), AverageGrade(averageGrade)
{
	//IndexNo = indexNo;
	//FirstName = firstName;
	//LastName = lastName;
	//AverageGrade = averageGrade;
}

Student::~Student()
{
}


bool operator==(Student& obj1, Student& obj2)
{
	return (obj1.IndexNo.compare(obj2.IndexNo) == 0 && 
			obj1.FirstName.compare(obj2.FirstName) == 0 && 
			obj1.LastName.compare(obj2.LastName) == 0);
}

// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Student& obj)
{
	out << obj.IndexNo << '\n' << obj.FirstName << '\n' << obj.LastName << "\n" << obj.AverageGrade << "\n" << std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Student& obj)
{
	in >> obj.IndexNo;
	in >> obj.FirstName;
	in >> obj.LastName;
	in >> obj.AverageGrade;
    return in;
}
