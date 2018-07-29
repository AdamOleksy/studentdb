#include "Employee.hpp"
#include <iostream>
#include <string>


Employee::Employee(string pesel, string firstName, string lastName, string address, float salary)
: Person(pesel, firstName, lastName, address), Salary(salary)
{
	Occupation = "Employee";
}

Employee::~Employee()
{
}

// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Employee& obj)
{
    out << obj.Occupation << '\n'
		<< obj.PESEL << '\n'  
		<< obj.FirstName << '\n' 
		<< obj.LastName << '\n' 
		<< obj.Address << '\n' 
		<< obj.Salary << '\n' 
		<< std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Employee& obj)
{
    in >> obj.Occupation;
	in >> obj.PESEL; 
	in >> obj.FirstName;
	in >> obj.LastName;
	in >> obj.Address;
	in >> obj.Salary;
    return in;
}
