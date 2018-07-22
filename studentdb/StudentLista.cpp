#include "StudentLista.hpp"

void StudentLista::dodajStudenta(std::string imie, std::string nazwisko, int indeks)
{
    Student s(imie,nazwisko,indeks);
    studentLista_.push_back(s);
}

void StudentLista::usunStudenta(int indeks)
{
    int wielkosc = studentLista_.size();
    for(int i =0; i < wielkosc; i++)
        if(studentLista_[i].indeks_ == indeks)
        {
            studentLista_.erase(studentLista_.begin()+i);
            break;
        }
}

void StudentLista::wypiszListeStudentow()
{
    int wielkosc = studentLista_.size();
    for(int i =0; i < wielkosc; i++)
        std::cout << studentLista_[i].indeks_ << ": "
                  << studentLista_[i].imie_ << " " << studentLista_[i].nazwisko_ << std::endl;
}
