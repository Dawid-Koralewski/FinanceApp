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

    // new record private functions
    Record provideNewRecordData(string type);
    Date provideDateOfRecord();
    double provideAmountOfRecord();
    bool checkCorrectnessOfDate(string dateStr);
    bool checkCorrectnessOfAmount(string amountStr);

    // balance private functions
    void showBalanceBetweenSelectedDates(Date startDate, Date endDate);
    vector <Record> clearRecordsOutOfRange(vector <Record> records, Date startDate, Date endDate);
    vector <Record> sortRecords(vector <Record> records);
    bool checkIfRecordIsFromEarlierThanCurrentEarliest(Date earliestDate, Date dateToCheck);
    void deleteRecordByID(vector <Record> &records, int recordID);
    Record findRecordByID(vector <Record> records, int recordID);
    double calculateSumOfRecords(vector <Record> records);

public:
    RecordManager(string incomesFileName, string expensesFileName, int loggedInUserID)
        : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserID)
    {
        loadLoggedInUserRecordsFromFile(LOGGED_IN_USER_ID);
    };

    void loadLoggedInUserRecordsFromFile(int loggedInUserID);

    // new record public functions
    void addIncome();
    void addExpense();

    // balance private functions
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSpecificRange();

    // print functions
    void printAllRecords(vector <Record> records);
    void printAllRecordsInBalanceFormat(vector <Record> records);
};

#endif
