#include "StdAfx.h"
#include "Employee.h"
#include <iostream>
#include <string>


Employee::Employee(std::string firstName, std::string lastName, float salary)
: FirstName(firstName), LastName(lastName), Salary(salary)
{
	//FirstName = firstName;
	//LastName = lastName;
}

Employee::~Employee()
{
}


bool operator==(Employee& obj1, Employee& obj2)
{
	return (obj1.FirstName.compare(obj2.FirstName) == 0 && 
			obj1.LastName.compare(obj2.LastName) == 0 && 
			obj1.Salary == obj2.Salary);
}

// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Employee& obj)
{
	out << obj.FirstName << '\n' << obj.LastName << "\n" << obj.Salary << '\n' << std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Employee& obj)
{
	in >> obj.FirstName;
	in >> obj.LastName;
	in >> obj.Salary;
    return in;
}
