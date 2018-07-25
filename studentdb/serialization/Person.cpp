#include "StdAfx.h"
#include "Person.h"
#include <iostream>
#include <string>

Person::Person(void)
{
}

Person::Person(std::string firstName = "", std::string lastName = "")
{
	FirstName = firstName;
	LastName = lastName;
}

Person::~Person(void)
{
}

bool operator==(Person& obj1, Person& obj2)
{
	return (obj1.FirstName.compare(obj2.FirstName) == 0 && obj1.LastName.compare(obj2.LastName) == 0);
}

// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Person& obj)
{
	out << obj.FirstName << '\n' << obj.LastName << "\n" << std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Person& obj)
{
	in >> obj.FirstName;
	in >> obj.LastName;
    return in;
}
