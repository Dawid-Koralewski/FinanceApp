#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
    int day = 0;
    int month = 0;
    int year = 0;

public:
    Date(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    int getDay();
    int getMonth();
    int getYear();
};

#endif
