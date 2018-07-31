#include "Student.hpp"
#include <iostream>
#include <string>

Student::Student(string pesel, string firstName, string lastName, string address, string indexNumber)
    : Person(pesel, firstName, lastName, address) , IndexNumber(indexNumber)
{
	Occupation = "Student";
}

Student::~Student()
{
}

string Student::getSpecialAttribute()
{
    return IndexNumber;
}

// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Student& obj)
{
    out << obj.Occupation << '\n'
		<< obj.PESEL << '\n'  
		<< obj.FirstName << '\n' 
		<< obj.LastName << '\n' 
		<< obj.Address << '\n' 
		<< obj.IndexNumber << '\n' 
		<< std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Student& obj)
{
    in >> obj.Occupation;
	in >> obj.PESEL; 
	in >> obj.FirstName;
	in >> obj.LastName;
	in >> obj.Address;
	in >> obj.IndexNumber;
    return in;
}
