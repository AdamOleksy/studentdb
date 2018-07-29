#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
	string Occupation;
	string PESEL;
	string FirstName;
	string LastName;
	string Address;

    Person(string pesel, string firstName, string lastName, string address);
    ~Person();
    
    string getPesel();
    string getFirstName();
    string getLastName();
	string getFullName();
    string getAddress();
    bool validPesel();
    int getPeselDigit(int index);
    string getSex();

	friend bool operator==(Person& obj1, Person& obj2);
	friend std::ostream& operator<<(std::ostream& out, Person& obj);
	friend std::istream& operator>>(std::istream& in, Person& obj);
};
