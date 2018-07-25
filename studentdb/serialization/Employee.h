#pragma once
#include <iostream>
#include <vector>
#include <string>

class Employee //: public Person
{
public:
	std::string FirstName;
	std::string LastName;
	float Salary;

    Employee(std::string firstName = "", std::string lastName = "", float salary = 0.0);
    ~Employee();
	friend bool operator==(Employee& obj1, Employee& obj2);
	friend std::ostream& operator<<(std::ostream& out, Employee& obj);
	friend std::istream& operator>>(std::istream& in, Employee& obj);
};
