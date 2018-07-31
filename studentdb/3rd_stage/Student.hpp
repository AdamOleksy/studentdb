#pragma once
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;

class Student : public Person
{
public:
	string IndexNumber;

    Student();
    Student(string pesel, string firstName, string lastName, string address, string indexNumber);
    ~Student();

    string getSpecialAttribute();

	friend std::ostream& operator<<(std::ostream& out, Student& obj);
	friend std::istream& operator>>(std::istream& in, Student& obj);
};
