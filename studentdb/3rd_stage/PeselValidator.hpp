#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class PeselValidator
{
    const int MIN_VALID_YEAR = 1900;
    const int MAX_VALID_YEAR = 2299;
    const int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

public:
    PeselValidator();

    int getPeselDigit(int index, string pesel);
    bool isPeselValid(string pesel);
    int countCheckSum(string pesel);
    int getYear(string pesel);
    int getMonth(string pesel);
    int getDay(string pesel);
    bool isLeapYear(int year);
    bool isDateValid(int day, int month, int year);

    void generateBirthDate(int &year, int &month, int &day);
    int getMonthShiftedByYear(int year, int month);
    int generateRandomNumber(int digitCount);
    string generatePesel();
};

