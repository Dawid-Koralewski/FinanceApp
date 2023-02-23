#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <ctype.h>

#include "Record.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class RecordManager
{
    vector <Record> incomes;
    vector <Record> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    const int LOGGED_IN_USER_ID;
    int lastIncomeID = 0;
    int lastExpenseID = 0;

public:
    RecordManager(string incomesFileName, string expensesFileName, int loggedInUserID)
        : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserID)
    {
        loadLoggedInUserRecordsFromFile(LOGGED_IN_USER_ID);
    };
//    Record provideNewRecordData();
    bool checkCorrectnessOfDate(string dateStr);
    bool checkCorrectnessOfAmount(string amountStr);
    void addIncome();
    void addExpense();
//    void setLastRecordID(int newID);
    Record provideNewRecordData(string type);
    Date provideDateOfRecord();
    double provideAmountOfRecord();
    void loadLoggedInUserRecordsFromFile(int loggedInUserID);
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSpecificRange();
    void showBalanceBetweenSelectedDates(Date startDate, Date endDate);
    vector <Record> clearRecordsOutOfRange(vector <Record> records, Date startDate, Date endDate);
    vector <Record> sortRecords(vector <Record> records, Date startDate, Date endDate);
//    int getLoggedInUserID();
//    int getRecordIDFromDataInFileSyntax(string dataInFileSyntax);
//    Record getRecordDataFromDataInFileSyntax(string recordDataInFileSyntax);
//    vector <Record> getRecords();
    void printAllRecords(vector <Record> records);
//    int getLastRecordID();
//    string convertRecordDataToFileSyntax(Record record);
//    int provideChosenRecordID();
};

#endif
