#include <string>

class Student
{
public:
    std::string imie_;
    std::string nazwisko_;
    int indeks_;
    
    Student() {}

    Student(std::string im, std::string n, int i) : imie_(im), nazwisko_(n), indeks_(i){}
};
