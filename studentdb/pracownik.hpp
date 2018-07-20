#include <string>

class Pracownik{
public:
    std::string imie_;
    std::string nazwisko_;
    int pensja;

    Pracownik(){}
    Pracownik(std::string i, std::string n, int p): imie_(i), nazwisko_(n), pensja(p) {}
};
