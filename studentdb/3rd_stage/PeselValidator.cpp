#include "PeselValidator.hpp"

PeselValidator::PeselValidator()
{
    static bool seeded = false;
    // Seed random number generator
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }
}

int PeselValidator::getPeselDigit(int index, string pesel)
{
    if (index >= 0 && index < pesel.length())
        if (isdigit(pesel[index]))
            return pesel[index] - '0';
    return -1;
}

bool PeselValidator::isPeselValid(string pesel)
{
    // Check if is number and 11 digit long
    if (pesel.length() == 11)
    {
        // Check birth date
        if (isDateValid(getYear(pesel), getMonth(pesel), getDay(pesel)))
        {
            // Count weighted sum: 1 3 7 9 1 3 7 9 1 3
            int lastDigit = countCheckSum(pesel);
            // 11th digit is check sum digit
            return (lastDigit == getPeselDigit(10, pesel));
        }
    }
    return false;
}

int PeselValidator::countCheckSum(string pesel)
{
    int sum = 0;
    if (pesel.length() >= 10)
        for (int i = 0; i < 10; i++)
            sum += weights[i] * getPeselDigit(i, pesel);

    int checkDigit = sum % 10;
    return checkDigit == 0 ? 0 : 10-checkDigit;
}

int PeselValidator::getYear(string pesel)
{
    int year = 10 * getPeselDigit(0, pesel) + getPeselDigit(1, pesel);
    int month = 10 * getPeselDigit(2, pesel) + getPeselDigit(3, pesel);

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

int PeselValidator::getMonth(string pesel)
{
    int month = 10 * getPeselDigit(2, pesel) + getPeselDigit(3, pesel);

    if (month > 20 && month < 33)
        return month - 20;
    else if (month > 40 && month < 53)
        return month - 40;
    else if (month > 60 && month < 73)
        return month - 60;
    return month;
}

int PeselValidator::getDay(string pesel)
{
    int day = 10 * getPeselDigit(4, pesel) + getPeselDigit(5, pesel);
    return day;
}

// Return true if year is a multiple of 4 and
// not multiple of 100 OR year is multiple of 400.
bool PeselValidator::isLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

// Return true if given date is valid
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
    // number of days equal to 30
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
/////
///

void PeselValidator::generateBirthDate(int &year, int &month, int &day)
{
     do {
        year = rand() % MAX_VALID_YEAR + MIN_VALID_YEAR;
        month = rand() % 12 + 1;
        day = rand() % 31 + 1;
    }
    while (!isDateValid(year, month, day));
}

int PeselValidator::getMonthShiftedByYear(int year, int month)
{
    // PESEL for this year is not supported
    if (year > MAX_VALID_YEAR || year < MIN_VALID_YEAR)
        return 0;

    int monthShift = (int)((year - 1900) / 100) * 20;
    return month + monthShift;
}

int PeselValidator::generateRandomNumber(int digitCount)
{
    int maxValue = pow(10, digitCount);
    int number = rand() % maxValue + 1;
    return number;
}

string PeselValidator::generatePesel()
{
    char arr[11];
    int year = 0, month = 0, day = 0;
    generateBirthDate(year, month, day);
    int number = generateRandomNumber(4);
    sprintf(arr, "%02d%02d%02d%04d",
            year % 100,
            getMonthShiftedByYear(year, month),
            day,
            number);
    string str(arr);

    int checkDigit = countCheckSum(str);
    str.append(to_string(checkDigit));
    return str;
}
