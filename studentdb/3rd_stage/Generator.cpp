#include "Generator.hpp"
#include <fstream>
#include <vector>

Generator::Generator() : peselGenerator()
{
}

//Funkcja generuje POPRAWNE numery PESEL
std::string Generator::generateValidPESEL()
{
   return  peselGenerator.generatePesel();
}

//Funkcja losuje liczbe z podanego zakresu
int Generator::generateInt(int min, int quantity)
{
    return (std::rand() % quantity ) + min;
}

//Funkcja generuje numery PESEL
std::string Generator::generatePESEL()
{
    std::string PES;
    PES+=generatePairXX(1, 99); //Rok
    PES+=generatePairXX(1, 12); //Miesiac
    PES+=generatePairXX(1, 31); //Dzien
    PES+=std::to_string(generateInt(11111, 88888)); //Ostatnie 5 cyfr, losowe

    return PES;
}

//Zwraca dwie cyfry z przedzialu w string format XX
std::string Generator::generatePairXX(int min, int quantity)
{
    std::string XX;
    int number = generateInt(min, quantity);
    if(number<=9){
         XX+='0';
         XX+=std::to_string(number);
    }else{
        XX+=std::to_string(number);
    }
    return XX;
}

//Funkcja losuje string z pliku
std::string Generator::drawString(std::string fileLocation)
{
    std::fstream file;
    file.open(fileLocation, std::ios::in);
    if(file.good() == true)
    {
        std::vector<std::string> tab;
        tab.reserve(100);
        std::string temp;
        while (!file.eof()) {
            getline(file, temp, '\n');
            tab.push_back(temp);
        }
        return tab[generateInt(0, tab.size())];
    }else{
        std::cout << "Nie udalo sie otworzyc pliku";
        return "";
    }
}

//Funkcja losuje z pliku imion
std::string Generator::drawName()
{
    return drawString("Gen/FirstNames.txt");
}

//Funkcja losuje z pliku imion
std::string Generator::drawLastName()
{
    return drawString("Gen/LastNames.txt");
}

//Funkcja losuje cale adresy
std::string Generator::drawAddress()
{
    return drawString("Gen/Streets.txt") + ", " + drawString("Gen/Cities.txt");
}
