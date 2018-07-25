#pragma once
#include <iostream>
#include <vector>
#include <string>

class Person
{
private:
    std::vector<std::string> m_data;

public:
	std::string FirstName;
	std::string LastName;

	Person(std::string firstName, std::string lastName);
    ~Person();
	friend bool operator==(Person& obj1, Person& obj2);
	friend std::ostream& operator<<(std::ostream& out, Person& obj);
	friend std::istream& operator>>(std::istream& in, Person& obj);
};
