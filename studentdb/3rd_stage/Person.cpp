#include "Person.hpp"
#include <iostream>
#include <string>


Person::Person(string pesel, string firstName, string lastName, string address) : 
	PESEL(pesel), FirstName(firstName), LastName(lastName), Address(address)
{
	Occupation = "Person";
}

Person::~Person()
{
}

string Person::getPesel()
{
	return PESEL;
}

string Person::getFirstName()
{
	return FirstName;
}

string Person::getLastName()
{
	return LastName;
}

string Person::getFullName()
{
    return FirstName + ' ' + LastName;
}

string Person::getAddress()
{
	return Address;
}

bool operator==(Person& obj1, Person& obj2)
{
    return (obj1.Occupation.compare(obj2.Occupation) == 0 &&
			obj1.PESEL.compare(obj2.PESEL) == 0 && 
			obj1.FirstName.compare(obj2.FirstName) == 0 && 
			obj1.LastName.compare(obj2.LastName) == 0 &&
			obj1.Address.compare(obj2.Address) == 0);
}
	
// Write the member variables to stream objects
std::ostream& operator<<(std::ostream& out, Person& obj)
{
    out << obj.Occupation << '\n'
		<< obj.PESEL << '\n'  
		<< obj.FirstName << '\n' 
		<< obj.LastName << '\n' 
		<< obj.Address << '\n' 
		<< std::endl;
    return out;
}

// Read data from stream object and fill it in member variables
std::istream& operator>>(std::istream& in, Person& obj)
{
    in >> obj.Occupation;
	in >> obj.PESEL; 
	in >> obj.FirstName;
	in >> obj.LastName;
	in >> obj.Address;
    return in;
}
