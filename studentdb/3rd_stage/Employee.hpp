#pragma once
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;

class Employee : public Person
{
public:
	float Salary;

    Employee();
    Employee(string pesel, string firstName, string lastName, string address, float salary);
    ~Employee();

    string getSpecialAttribute();

	friend std::ostream& operator<<(std::ostream& out, Employee& obj);
	friend std::istream& operator>>(std::istream& in, Employee& obj);
};
