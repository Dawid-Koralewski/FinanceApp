#include "Record.h"

void Record::setID(int newID)
{
    ID = newID;
}

void Record::setUserID(int newID)
{
    userID = newID;
}

void Record::setDate(Date newDate)
{
    date = newDate;
}

void Record::setType(string newType)
{
    type = newType;
}

void Record::setAmount(double newAmount)
{
    amount = newAmount;
}

int Record::getID()
{
    return ID;
}

int Record::getUserID()
{
    return userID;
}

Date Record::getDate()
{
    return date;
}

int Record::getDateInt()
{
    int temp = date.getYear();
    temp = temp * 100;
    temp = temp + date.getMonth();
    temp = temp * 100;
    temp = temp + date.getDay();

    return temp;
}

string Record::getDateString()
{
    string dateStr = "";

    dateStr += GeneralMethods::conversionIntToString(date.getYear());
    dateStr += '-';
    if (date.getMonth() < 10)
    {
        dateStr += '0';
        dateStr += GeneralMethods::conversionIntToString(date.getMonth());
    }
    else
        dateStr += GeneralMethods::conversionIntToString(date.getMonth());
    dateStr += '-';
    if (date.getDay() < 10)
    {
        dateStr += '0';
        dateStr += GeneralMethods::conversionIntToString(date.getDay());
    }
    else
        dateStr += GeneralMethods::conversionIntToString(date.getDay());

    return dateStr;
}

string Record::getType()
{
    return type;
}

double Record::getAmount()
{
    return amount;
}

void Record::printRecordData()
{
    cout << endl << "Id:                 " << getID() << endl;
    cout << endl << "User ID:            " << getUserID() << endl;
    cout << endl << "Date:               " << getDate().getYear() << "-" << getDate().getMonth() << "-" << getDate().getDay() << endl;
    cout << endl << "Item:               " << getType() << endl;
    cout << endl << "Amount:             " << getAmount() << endl;
}

void Record::printRecordDataInBalanceFormat()
{
    cout << endl << getDate().getYear() << "-";

    if (getDate().getMonth() < 10)
        cout << "0" << getDate().getMonth() << "-";
    else
        cout << getDate().getMonth() << "-";

    if(getDate().getDay() < 10)
        cout << "0" << getDate().getDay();
    else
        cout << getDate().getDay();

    cout << "       " << getType();
    cout << "           " << getAmount() << endl;
}
