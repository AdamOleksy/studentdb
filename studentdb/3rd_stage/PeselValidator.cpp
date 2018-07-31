#include "PeselValidator.hpp"

PeselValidator::PeselValidator(string pesel) : PESEL(pesel)
{
}

int PeselValidator::getPeselDigit(int index)
{
    if (index >= 0 && index < PESEL.length())
        if (isdigit(PESEL[index]))
            return PESEL[index] - '0';
    return -1;
}

bool PeselValidator::isPeselValid()
{
    // Check if is number and 11 digit long
    if (PESEL.length() == 11)
    {
        // Check birth date
        if (isDateValid(getYear(), getMonth(), getDay()))
        {
            // Count weighted sum: 1 3 7 9 1 3 7 9 1 3
            int lastDigit = countCheckSum();
            // 11th digit is check sum digit
            return (lastDigit == getPeselDigit(10));
        }
    }
    return false;
}

int PeselValidator::countCheckSum()
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += weights[i] * getPeselDigit(i);
    }

    int checkDigit = sum % 10;
    return checkDigit == 0 ? 0 : 10-checkDigit;
}

int PeselValidator::getYear()
{
    int year = 10 * getPeselDigit(0) + getPeselDigit(1);
    int month = 10 * getPeselDigit(2) + getPeselDigit(3);

    if (month > 0 && month < 13)
        return year + 1900;
    else if (month > 20 && month < 33)
        return year + 2000;
    else if (month > 40 && month < 53)
        return year + 2100;
    else if (month > 60 && month < 73)
        return year + 2200;
    return year;
}

int PeselValidator::getMonth()
{
    int month = 10 * getPeselDigit(2) + getPeselDigit(3);

    if (month > 20 && month < 33)
        return month - 20;
    else if (month > 40 && month < 53)
        return month - 40;
    else if (month > 60 && month < 73)
        return month - 60;
    return month;
}

int PeselValidator::getDay()
{
    int day = 10 * getPeselDigit(4) + getPeselDigit(5);
    return day;
}

// Returns true if given year is leap
bool PeselValidator::isLeapYear(int year)
{
    // Return true if year is a multiple of 4 and
    // not multiple of 100 OR year is multiple of 400.
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

// Returns true if given date is valid
bool PeselValidator::isDateValid(int year, int month, int day)
{
    // Check if inputs are in given range
    if (year > MAX_VALID_YEAR || year < MIN_VALID_YEAR)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Handle February with leap year
    if (month == 2)
    {
        return isLeapYear(year) ? day <= 29 : day <= 28;
    }

    // Months: April, June, September and November have
    // number of days less than or equal to 30.
    switch (month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
        default:
            // We check already input data less or equal than 31
            return true;
    }
}

/////// Generator
///
///

