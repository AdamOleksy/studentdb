#include <iostream>
#include "DataBase.hpp"
#include <fstream>

void DataBase::loadDataBase()
{
    std::fstream file;
    file.open("Data.csv", std::ios::in);

    if(file.good() == true)
    {

        while(!file.eof()){
           std::string temp, flag, pesel, name, lastName, address, info;
           getline(file, temp, ';');
           flag = temp;
           getline(file, temp, ';');
           pesel = temp;
           getline(file, temp, ';');
           name = temp;
           getline(file, temp, ';');
           lastName = temp;
           getline(file, temp, ';');
           address = temp;
           getline(file, temp, '\n');
           info = temp;
           if(flag == "Student")
               dataBase_.push_back(new Student(pesel,name,lastName, address, info));

           if(flag == "Employee")
               dataBase_.push_back(new Employee(pesel,name,lastName, address, std::stof(info)));

        }
    }
    else{
        std::cout << "Nie otwarto pliku" << std::endl;
    }

}
void DataBase::saveDataBase()
{
    std::fstream file;
    file.open("Data.csv", std::ios::out);
    if(file.good() == true){
        for(auto a : dataBase_)
        {
            file<<a->Occupation << ';'
                <<a->getPesel() << ';'
                <<a->getFirstName() << ';'
                <<a->getLastName() << ';'
                <<a->getAddress() << '\n';

        }
    }else{
        std::cout << "Nie udalo sie otworzyc pliku";
    }

}
int DataBase::dataSize()
{
    std::cout << "Wielkosc tablicy: " << dataBase_.size() << std::endl;
    return dataBase_.size();
}
