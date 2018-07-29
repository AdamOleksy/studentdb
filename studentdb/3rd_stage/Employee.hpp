#pragma once
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;

class Employee : public Person
{
public:
	float Salary;

    Employee(string pesel, string firstName, string lastName, string address, float salary);
    ~Employee();
	friend std::ostream& operator<<(std::ostream& out, Employee& obj);
	friend std::istream& operator>>(std::istream& in, Employee& obj);
};
