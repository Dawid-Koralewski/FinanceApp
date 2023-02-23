#ifndef GENERALMETHODS_H
#define GENERALMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <ctime>

#include "Date.h"

using namespace std;

class GeneralMethods
{

public:
    static string conversionIntToString(int liczba);
    static string readLine();
    static char readChar();
    static string getNumber(string text, int charPosition);
    static int convertionStringToInt(string liczba);
    static string changeFirstLetterToUpercaseRestToLowercase(string text);
    static int readInteger();
    static Date convertTMClassToDate(tm &time);
    static Date convertionStringDateToDate(string dateStr);
    static string convertionDateToString(Date date);
    static int maxNumberOfDaysInMonth(int year, int month);
    static double convertionStringAmountToDouble(string amountStr);
};

#endif
