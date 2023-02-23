#ifndef RECORD_H
#define RECORD_H

#include <iostream>

#include "GeneralMethods.h"
#include "Date.h"

using namespace std;

class Record
{
    int ID = 0;
    int userID = 0;
    Date date;
    string type = "";
    double amount = 0;

public:
    Record(int ID = 0, int userID = 0, string type = "", double amount = 0)
    {
        this->ID = ID;
        this->userID = userID;
        this->type = type;
        this->amount = amount;
    };

    void setID(int newID);
    void setUserID(int newID);
    void setDate(Date newDate);
    void setType(string newType);
    void setAmount(double newAmount);

    int getID();
    int getUserID();
    Date getDate();
    int getDateInt();
    string getDateString();
    string getType();
    double getAmount();

    void printRecordData();

};

#endif
