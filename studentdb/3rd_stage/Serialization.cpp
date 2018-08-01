// Serialization.cpp : Defines the entry point for the console application.
//

#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "PeselValidator.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

void testEmployeeDB();
void testStudentDB();

int main(int argc, char* argv[])
{
    PeselValidator peselGenerator;
    string pesel;
    for (int i = 0; i < 21; i++)
    {
        pesel = peselGenerator.generatePesel();
        cout << "PESEL: " << pesel << ", valid: " << std::boolalpha << peselGenerator.isPeselValid(pesel) << endl;
    }
    testStudentDB();

    testEmployeeDB();

    return 0;
}

void testStudentDB()
{
    Student stud1("83042300853", "Jack", "Rabbit", "Warszawa", "41207");
    Student stud2("77081100543", "Riti", "Kokka", "Wroclaw", "41211");
    //Student stud3("83030678328", "Anad", "Sleiman", "Poznan", "41213");
    Student stud3("22222222222", "Anad", "Sleiman", "Poznan", "41213");

    // Open the File
    std::ofstream out("students.txt");

    // Write objects to file
    out<<stud1;
    out<<stud2;
    out<<stud3;

    out.close();

    // Open the File
    std::ifstream in("students.txt");

    Student student1("", "", "", "", "");
    Student student2("", "", "", "", "");
    Student student3("", "", "", "", "");

    // Read objects from file and fill in data
    in>>student1;
    in>>student2;
    in>>student3;

    in.close();

    // Compare the Objects
    assert(stud1==student1);
    assert(stud2==student2);
    assert(stud3==student3);

    cout << "Sex: " << stud1.getSex() << ", PESEL valid: " << stud1.isPeselValid() << endl;
    cout << "Sex: " << stud2.getSex() << ", PESEL valid: " << stud2.isPeselValid() << endl;
    cout << "Sex: " << stud3.getSex() << ", PESEL valid: " << stud3.isPeselValid() << endl;

    Person* p;
    p = &stud3;
    cout << p->getSpecialAttribute() << endl;

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

    Employee employee1("", "", "", "", 0);
    Employee employee2("", "", "", "", 0);
    Employee employee3("", "", "", "", 0);

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

    cout << "Sex: " << empl1.getSex() << ", PESEL valid: " << empl1.isPeselValid() << endl;
    cout << "Sex: " << empl2.getSex() << ", PESEL valid: " << empl1.isPeselValid() << endl;
    cout << "Sex: " << empl3.getSex() << ", PESEL valid: " << empl1.isPeselValid() << endl;
//    for (int i = -5; i < 15; i++)
//        cout << i << ":" << empl3.getPeselDigit(i) << " ";
    cout << endl;
    cout << empl3;

    Person* p;
    p = &empl2;
    cout << p->getSpecialAttribute() << endl;
}
