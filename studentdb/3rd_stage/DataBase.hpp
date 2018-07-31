#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Employee.hpp"
#include <fstream>

class DataBase
{
public:
    std::vector<Person*> dataBase_;

    //Zaladuje dane z pliku Data.csv
    void loadDataBase();

    //Wypisze zwroci wielkosc wektora
    int dataSize();

    //Zapisze baze do pliku Data.csv
    void saveDataBase();

    //Usuwa osobe po peselu
    void deleteByPESEL(std::string PES);

    //Wyszukiwanie po peselu
    void findByPESEL(std::string PES);
};
