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

	Employee(void);
	Employee(std::string firstName, std::string lastName, float salary);
	~Employee(void);
	friend bool operator==(Employee& obj1, Employee& obj2);
	friend std::ostream& operator<<(std::ostream& out, Employee& obj);
	friend std::istream& operator>>(std::istream& in, Employee& obj);
};
