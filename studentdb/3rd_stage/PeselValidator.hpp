#pragma once
#include <string>
#include <iostream>

using namespace std;

class PeselValidator
{
    const int MIN_VALID_YEAR = 1900;
    const int MAX_VALID_YEAR = 2299;
    const int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    string PESEL;
public:
    PeselValidator(string pesel);

    int getPeselDigit(int index);
    bool isPeselValid();
    int countCheckSum();
    int getYear();
    int getMonth();
    int getDay();
    bool isLeapYear(int year);
    bool isDateValid(int day, int month, int year);
};

