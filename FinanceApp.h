#ifndef FINANCEAPP_H
#define FINANCEAPP_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "UserManager.h"
#include "RecordManager.h"

using namespace std;

class FinanceApp
{
    UserManager userManager;
    RecordManager *recordManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    int loggedInUserID = 0;
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

public:
    FinanceApp(string usersFileName, string incomesFileName, string expensesFileName) : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        recordManager = NULL;
    };
    ~FinanceApp()
    {
        delete recordManager;
        recordManager = NULL;
    };

    void showMainMenu();
};

#endif
