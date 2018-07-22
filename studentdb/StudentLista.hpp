#pragma once
#include <iostream>
#include <vector>
#include "student.hpp"

class StudentLista
{
    std::vector<Student> studentLista_;
public:
    //Funkcja sluzaca do dodawania studentow do listy
    void dodajStudenta(std::string imie, std::string nazwisko, int indeks);

    //Funkcja do usuwania studenta na podstawie numeru indeksu
    void usunStudenta(int indeks);

    //Wypisanie listy studentow
    void wypiszListeStudentow();

};
