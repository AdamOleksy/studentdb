// Serialization.cpp : Defines the entry point for the console application.
//

#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

void testEmployeeDB();
void testStudentDB();

int main(int argc, char* argv[])
{
    testStudentDB();

    testEmployeeDB();

    return 0;
}

void testStudentDB()
{
    Student stud1("83042300853", "Jack", "Rabbit", "Warszawa", "41207");
    Student stud2("83042300853", "Riti", "Kokka", "Wroclaw", "41211");
    Student stud3("83042300853", "Anad", "Sleiman", "Poznan", "41213");

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
    Employee empl1("04231137443", "Jan", "Weglarz", "Poznan", 7500.34);
    Employee empl2("72110231098", "Jacek", "Blazewicz", "Lomza", 6800.67);
    Employee empl3("23012611639", "Jerzy", "Nawrocki", "Pcim", 11000.00);

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

    cout << "Sex: " << empl1.getSex() << endl;
    cout << "Sex: " << empl2.getSex() << endl;
    cout << "Sex: " << empl3.getSex() << endl;
}
