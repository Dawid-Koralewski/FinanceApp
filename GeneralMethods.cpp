#include "GeneralMethods.h"

string GeneralMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string GeneralMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char GeneralMethods::readChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "That was not a single character. Try again." << endl;
    }
    return character;
}

string GeneralMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int GeneralMethods::convertionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string GeneralMethods::changeFirstLetterToUpercaseRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int GeneralMethods::readInteger()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

Date GeneralMethods::convertTMClassToDate(tm &time)
{
    Date date;
    date.setYear(1900 + time.tm_year);
    date.setMonth(1 + time.tm_mon);
    date.setDay(time.tm_mday);

    return date;
}

Date GeneralMethods::convertionStringDateToDate(string dateStr)
{
    Date date;
    string singlePartOfDate = "";
    int numberOfSinglePartOfDate = 1;

    for (int charPosition = 0; charPosition < (int)dateStr.length(); charPosition++)
    {
        if (dateStr[charPosition] != '-')
        {
            singlePartOfDate += dateStr[charPosition];
        }
        else
        {
            switch(numberOfSinglePartOfDate)
            {
            case 1:
                date.setYear(atoi(singlePartOfDate.c_str()));
                break;
            case 2:
                date.setMonth(atoi(singlePartOfDate.c_str()));
                break;
            }

            singlePartOfDate = "";
            numberOfSinglePartOfDate++;
        }

        if (charPosition == (int)dateStr.length() - 1)
        {
            date.setDay(atoi(singlePartOfDate.c_str()));
        }
    }
    return date;
}

int GeneralMethods::maxNumberOfDaysInMonth(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if ((year % 4) == 0 && month == 2)
        return 29;
    else if (month == 2)
        return 28;
    else
        return 0;
}

double GeneralMethods::convertionStringAmountToDouble(string amountStr)
{
    double amount;
    int amountIntegerPart = 0;
    int amountFractalPart = 0;
    string singlePartOfAmount = "";
    int numberOfSinglePartOfAmount = 1;

    for (int charPosition = 0; charPosition < (int)amountStr.length(); charPosition++)
    {
        if (amountStr[charPosition] != ',' && amountStr[charPosition] != '.')
        {
            singlePartOfAmount += amountStr[charPosition];
        }
        else
        {
            switch(numberOfSinglePartOfAmount)
            {
            case 1:
                amountIntegerPart = atoi(singlePartOfAmount.c_str());
                break;
            case 2:
                amountFractalPart = atoi(singlePartOfAmount.c_str());
                break;
            }

            singlePartOfAmount = "";
            numberOfSinglePartOfAmount++;
        }

        if ((charPosition == (int)amountStr.length() - 1) && numberOfSinglePartOfAmount < 2)
        {
            amountIntegerPart = atoi(singlePartOfAmount.c_str());
        }
        else if ((charPosition == (int)amountStr.length() - 1) && numberOfSinglePartOfAmount == 2)
        {
            amountFractalPart = atoi(singlePartOfAmount.c_str());
        }
        else if ((charPosition == (int)amountStr.length() - 1) && numberOfSinglePartOfAmount > 2)
        {
            cout << endl << "Wrong amount. Amount changed to 0.0. Please verify your data.";
            amount = 0.0;
            system("pause");
            return amount;
        }
    }

    amountStr = GeneralMethods::conversionIntToString(amountIntegerPart) + '.' + GeneralMethods::conversionIntToString(amountFractalPart);
    amount = atof(amountStr.c_str());
    return amount;
}
