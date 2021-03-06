#pragma once
#include <iostream>
#include <vector>
#include <string>

class Student //: public Person
{
public:
	std::string IndexNo;
	std::string FirstName;
	std::string LastName;
	float AverageGrade;

    Student(std::string indexNo = "", std::string firstName = "", std::string lastName = "", float averageGrade = 0.0);
    ~Student();
	friend bool operator==(Student& obj1, Student& obj2);
	friend std::ostream& operator<<(std::ostream& out, Student& obj);
	friend std::istream& operator>>(std::istream& in, Student& obj);
};
