// Serialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "Employee.h"
#include <fstream>
#include <cassert>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	testStudentDB();

	testEmployeeDB();

	return 0;
}

void testStudentDB()
{
	Student stud1("41207", "Jack", "Rabbit", 4.5);
	Student stud2("41211", "Riti", "Kokka", 4.75);
	Student stud3("41213", "Anad", "Sleiman", 3.67);
 
	// Open the File
	std::ofstream out("students.txt");
 
	// Write objects to file
	out<<stud1;
	out<<stud2;
	out<<stud3;
 
	out.close();
 
	// Open the File
	std::ifstream in("students.txt");
 
	Student student1;
	Student student2;
	Student student3;
 
	// Read objects from file and fill in data
	in>>student1;
	in>>student2;
	in>>student3;
 
	in.close();
 
	// Compare the Objects
	assert(stud1==student1);
	assert(stud2==student2);
	assert(stud3==student3);
 
	std::cout << "Everything worked good!" << std::endl;
	std::string s;
	std::cin >> s;
}

void testEmployeeDB()
{
	Employee empl1("Jan", "Weglarz", 7500.34);
	Employee empl2("Jacek", "Blazewicz", 6800.67);
	Employee empl3("Jerzy", "Nawrocki", 11000.00);
 
	// Open the File
	std::ofstream out("employee.txt");
 
	// Write objects to file
	out<<empl1;
	out<<empl2;
	out<<empl3;
 
	out.close();
 
	// Open the File
	std::ifstream in("employee.txt");
 
	Employee employee1;
	Employee employee2;
	Employee employee3;
 
	// Read objects from file and fill in data
	in>>employee1;
	in>>employee2;
	in>>employee3;
 
	in.close();
 
	// Compare the Objects
	assert(empl1==employee1);
	assert(empl2==employee2);
	assert(empl3==employee3);
 
	std::cout << "Everything worked good!" << std::endl;
	std::string s;
	std::cin >> s;
}