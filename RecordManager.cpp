#include "RecordManager.h"

Record RecordManager::provideNewRecordData(string type)
{
    Record record;
    char choice = ' ';
    if (type == "income")
    {
        incomesFile.lastIncomeID += 1;
        record.setID(incomesFile.lastIncomeID);
    }
    else if (type == "expense")
    {
        expensesFile.lastExpenseID += 1;
        record.setID(expensesFile.lastExpenseID);
    }

    record.setUserID(LOGGED_IN_USER_ID);

    cout << endl << "Is this record from today? (Y=yes, N=no): ";
    choice = GeneralMethods::readChar();

    while (choice != 'N' && choice != 'Y' && choice != 'n' && choice != 'y')
    {
        cout << endl << endl << "This was not correct choice, please type in \"Y\" if the record is from today, if not please type in \"N\"";
        cout << endl << "Is this record from today? (Y=yes, N=no): ";
        choice = GeneralMethods::readChar();
    }

    if (choice == 'Y' || choice == 'y')
    {
        time_t now = time(0);
        tm *ltm = localtime(&now); // tutorialspoint.com/cplusplus/cpp_date_time.htm#
        record.setDate(GeneralMethods::convertTMClassToDate(*ltm));
    }
    else
        record.setDate(provideDateOfRecord());

    cout << endl << "What is the record type?: ";
    record.setType(GeneralMethods::readLine());

    cout << endl << "What is the amount of this record?: ";
    record.setAmount(provideAmountOfRecord());

    return record;
}

Date RecordManager::provideDateOfRecord()
{
    Date date;
    string dateStr = "";

    cout << endl << endl << "Please provide date of this record in YYYY-MM-DD format.";
    cout << endl << "(The earliest possible date is 2000-01-01): ";
    dateStr = GeneralMethods::readLine();
    while (!checkCorrectnessOfDate(dateStr))
    {
        cout << endl << "Provided data is incorrect. Please check if it is in YYYY-MM-DD format and it is later than 2000-01-01 and try again.";
        cout << endl << endl << "Please provide date of this record in YYYY-MM-DD format: ";
        dateStr = GeneralMethods::readLine();
    }

    date = GeneralMethods::convertionStringDateToDate(dateStr);

    return date;
}

double RecordManager::provideAmountOfRecord()
{
    double amount = 0.0;
    string amountStr;

    amountStr = GeneralMethods::readLine();
    while (!checkCorrectnessOfAmount(amountStr))
    {
        cout << endl << "Provided amount is incorrect. Please check if it is numeric.";
        amountStr = GeneralMethods::readLine();
    }

    amount = GeneralMethods::convertionStringAmountToDouble(amountStr);
    return amount;
}

bool RecordManager::checkCorrectnessOfDate(string dateStr)
{
    int year = 0;
    int month = 0;
    int day = 0;
    string singlePartOfDate = "";
    int numberOfSinglePartOfDate = 1;

    for (int charPosition = 0; charPosition < (int)dateStr.length(); charPosition++)
    {
        if (dateStr[charPosition] != '-')
        {
            if (isdigit(dateStr[charPosition]))
                singlePartOfDate += dateStr[charPosition];
            else
            {
                cout << endl << "Date must be numeric. Please try again.";
                return false;
            }
        }
        else
        {
            switch(numberOfSinglePartOfDate)
            {
            case 1:
                year = atoi(singlePartOfDate.c_str());
                break;
            case 2:
                if (singlePartOfDate.length() != 2)
                {
                    cout << endl << "Number representing month must contain two digits. If it is lower than 10, add 0 in front.";
                    return false;
                }
                else
                    month = atoi(singlePartOfDate.c_str());
                break;
            }

            singlePartOfDate = "";
            numberOfSinglePartOfDate++;
        }

        if (charPosition == (int)dateStr.length() - 1)
        {
            if (singlePartOfDate.length() != 2)
            {
                cout << endl << "Number representing day must contain two digits. If it is lower than 10, add 0 in front.";
                return false;
            }
            else
                day = atoi(singlePartOfDate.c_str());
        }
    }

    time_t now = time(0);
    tm *ltm = localtime(&now); // tutorialspoint.com/cplusplus/cpp_date_time.htm#
    Date currentDate;
    currentDate = (GeneralMethods::convertTMClassToDate(*ltm));

    if (year < 2000 || year > currentDate.getYear())
    {
        cout << endl << "The earliest year is 2000. The latest is current year. Please try again." << endl;
        return false;
    }
    else if ((year == currentDate.getYear() && month > currentDate.getMonth()) || month < 1 || month > 12)
    {
        cout << endl << "Number representing month must be between 1 and 12 or number representing current month if the year is the same as current year. Please try again." << endl;
        return false;
    }
    else if ((year == currentDate.getYear() && month == currentDate.getMonth() && day > currentDate.getDay()) || day < 1 || day > GeneralMethods::maxNumberOfDaysInMonth(year, month))
    {
        cout << endl << "Number representing day must be between 1 and maximum day of typed in month or number representing current day of the month if the year and month are the same as the current ones. Please try again." << endl;
        return false;
    }
    else
        return true;
}

bool RecordManager::checkCorrectnessOfAmount(string amountStr)
{
    for (int charPosition = 0; charPosition < (int)amountStr.length(); charPosition++)
    {
        if (amountStr[charPosition] != ',' && amountStr[charPosition] != '.' && !isdigit(amountStr[charPosition]))
        {
            return false;
        }
    }
    return true;
}

void RecordManager::addIncome()
{
    Record record;

    system("cls");
    cout << " >>> ADDING NEW RECORD <<<" << endl << endl;
    record = provideNewRecordData("income");

    incomes.push_back(record);
    incomesFile.addRecordToFile(record);

    incomesFile.lastIncomeID += 1;

    cout << endl << "Record successfully added!" << endl;
    system("pause");
    return;
}

void RecordManager::addExpense()
{
    Record record;

    system("cls");
    cout << " >>> ADDING NEW RECORD <<<" << endl << endl;
    record = provideNewRecordData("expense");

    expenses.push_back(record);
    expensesFile.addRecordToFile(record);

    expensesFile.lastExpenseID += 1;

    cout << endl << "Record successfully added!" << endl;
    system("pause");
    return;
}

void RecordManager::loadLoggedInUserRecordsFromFile(int loggedInUserID)
{
    incomesFile.lastIncomeID = incomesFile.loadLoggedInUserRecordsFromFile(incomes, loggedInUserID);
    expensesFile.lastExpenseID = expensesFile.loadLoggedInUserRecordsFromFile(expenses, loggedInUserID);
}

void RecordManager::showBalanceFromCurrentMonth()
{
    Date startDate, endDate;
    time_t now = time(0);
    tm *ltm = localtime(&now); // tutorialspoint.com/cplusplus/cpp_date_time.htm#
    endDate = GeneralMethods::convertTMClassToDate(*ltm);

    startDate = endDate;
    startDate.setDay(1);

    showBalanceBetweenSelectedDates(startDate, endDate);
}

void RecordManager::showBalanceFromPreviousMonth()
{
    Date startDate, endDate;
    time_t now = time(0);
    tm *ltm = localtime(&now); // tutorialspoint.com/cplusplus/cpp_date_time.htm#
    endDate = GeneralMethods::convertTMClassToDate(*ltm);

    if (endDate.getMonth() == 1)
    {
        endDate.setYear(endDate.getYear() - 1);
        endDate.setMonth(12);
        endDate.setDay(GeneralMethods::maxNumberOfDaysInMonth(endDate.getYear(), endDate.getMonth()));
    }
    else
    {
        endDate.setMonth(endDate.getMonth() - 1);
        endDate.setDay(GeneralMethods::maxNumberOfDaysInMonth(endDate.getYear(), endDate.getMonth()));
    }

    startDate = endDate;
    startDate.setDay(1);

    showBalanceBetweenSelectedDates(startDate, endDate);
}

void RecordManager::showBalanceFromSpecificRange()
{
    Date startDate, endDate;
    string dateStr = "";

    cout << endl << endl << "Please provide STARTDATE of the date range in YYYY-MM-DD format.";
    cout << endl << "(The earliest possible date is 2000-01-01): ";
    dateStr = GeneralMethods::readLine();
    while (!checkCorrectnessOfDate(dateStr))
    {
        cout << endl << "Provided data is incorrect. Please check if it is in YYYY-MM-DD format and it is later than 2000-01-01 and try again.";
        cout << endl << endl << "Please provide date of this record in YYYY-MM-DD format: ";
        dateStr = GeneralMethods::readLine();
    }

    endDate = GeneralMethods::convertionStringDateToDate(dateStr);

    cout << endl << endl << "Please provide ENDDATE of the date range in YYYY-MM-DD format.";
    cout << endl << "(The earliest possible date is 2000-01-01): ";
    dateStr = GeneralMethods::readLine();
    while (!checkCorrectnessOfDate(dateStr))
    {
        cout << endl << "Provided data is incorrect. Please check if it is in YYYY-MM-DD format and it is later than 2000-01-01 and try again.";
        cout << endl << endl << "Please provide date of this record in YYYY-MM-DD format: ";
        dateStr = GeneralMethods::readLine();
    }

    endDate = GeneralMethods::convertionStringDateToDate(dateStr);

    showBalanceBetweenSelectedDates(startDate, endDate);
}

void RecordManager::showBalanceBetweenSelectedDates(Date startDate, Date endDate)
{
    vector <Record> incomesSorted = incomes;
    vector <Record> expensesSorted = expenses;

    if (!incomesSorted.empty())
    {
        incomesSorted = clearRecordsOutOfRange(incomesSorted, startDate, endDate);
        if (!incomesSorted.empty())
            incomesSorted = sortRecords(incomesSorted);
        else
            cout << endl << "No records in current date range in incomes file." << endl;
    }
    else
    {
        cout << endl << "No records in incomes file for current user." << endl << endl;
    }

    if (!expensesSorted.empty())
    {
        expensesSorted = clearRecordsOutOfRange(expensesSorted, startDate, endDate);
        if (!incomesSorted.empty())
            expensesSorted = sortRecords(expensesSorted);
        else
            cout << endl << "No records in current date range in expenses file." << endl;
    }
    else
    {
        cout << endl << "No records in expenses file for current user." << endl << endl;
    }

    cout << endl << "===============INCOMES==============";
    cout << endl << "Date             Type         Amount" << endl;
    printAllRecordsInBalanceFormat(incomesSorted);
    cout << endl << endl << "==============EXPENSES==============";
    cout << endl << "Date             Type         Amount" << endl;
    printAllRecordsInBalanceFormat(expensesSorted);

    double sumOfIncomes = calculateSumOfRecords(incomesSorted);
    double sumOfExpenses = calculateSumOfRecords(expensesSorted);
    cout << "INCOMES: " << sumOfIncomes << " | EXPENSES: " << sumOfExpenses << " | Balance: " << sumOfIncomes - sumOfExpenses << endl;
    system("pause");
}

double RecordManager::calculateSumOfRecords(vector <Record> records)
{
    double sum = 0.0;

    for (vector <Record> :: iterator itr = records.begin(); itr != records.end() && !records.empty(); itr++)
    {
        sum += itr -> getAmount();
    }

    return sum;
}

vector <Record> RecordManager::clearRecordsOutOfRange(vector <Record> records, Date startDate, Date endDate)
{
    Date tempDate;
    for (vector <Record> :: iterator itr = records.begin(); itr != records.end() && !records.empty(); itr++)
    {
        tempDate = itr -> getDate();
        if (tempDate.getYear() < startDate.getYear() || tempDate.getYear() > endDate.getYear())
        {
            records.erase(itr);
        }
        else if (tempDate.getMonth() < startDate.getMonth() || tempDate.getMonth() > endDate.getMonth())
        {
            records.erase(itr);
        }
        else if (tempDate.getDay() < startDate.getDay() || tempDate.getDay() > endDate.getDay())
        {
            records.erase(itr);
        }
    }
    return records;
}

vector <Record> RecordManager::sortRecords(vector <Record> records)
{
    vector <Record> recordsSorted;
    vector <Record> :: iterator itr = records.begin();
    vector <Record> :: iterator itrToRecordWithEarliestDateInVector = records.begin();
    Record recordTemp;

    int IDOfRecordWithEarliestDateInVector = itr -> getID();

    while (!records.empty())
    {
        itr = records.begin();
        IDOfRecordWithEarliestDateInVector = itr -> getID();

        while (itr != records.end())
        {
            if (checkIfRecordIsFromEarlierThanCurrentEarliest(itrToRecordWithEarliestDateInVector -> getDate(), itr -> getDate()))
            {
                IDOfRecordWithEarliestDateInVector = itr -> getID();
            }

            itr++;
        }

        recordTemp = findRecordByID(records, IDOfRecordWithEarliestDateInVector);

        if (recordTemp.getID() != 0)
        {
            recordsSorted.push_back(recordTemp);
        }
        deleteRecordByID(records, IDOfRecordWithEarliestDateInVector);
    }

    return recordsSorted;
}

Record RecordManager::findRecordByID(vector <Record> records, int recordID)
{
    Record record;

    for (vector <Record> :: iterator itr = records.begin(); itr != records.end() && !records.empty(); itr++)
    {
        if (recordID == itr -> getID())
        {
            record = *itr;
            return record;
        }
    }

    return record;
}

void RecordManager::deleteRecordByID(vector <Record> &records, int recordID)
{
    for (vector <Record> :: iterator itr = records.begin(); itr != records.end() && !records.empty(); itr++)
    {
        if (recordID == itr -> getID())
        {
            records.erase(itr);
            return;
        }
    }
    return;
}

bool RecordManager::checkIfRecordIsFromEarlierThanCurrentEarliest(Date earliestDate, Date dateToCheck)
{
    if (dateToCheck.getYear() < earliestDate.getYear())
        return true;
    else if ((dateToCheck.getYear() == earliestDate.getYear()) && dateToCheck.getMonth() < earliestDate.getMonth())
        return true;
    else if ((dateToCheck.getYear() == earliestDate.getYear()) && dateToCheck.getMonth() == earliestDate.getMonth() && dateToCheck.getDay() < earliestDate.getDay())
        return true;
    else
        return false;
}

void RecordManager::printAllRecords(vector <Record> records)
{
    system("cls");
    if (!records.empty())
    {
        for (vector <Record> :: iterator itr = records.begin(); itr != records.end(); itr++)
        {
            itr -> printRecordData();
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No records." << endl << endl;
    }
    system("pause");
}

void RecordManager::printAllRecordsInBalanceFormat(vector <Record> records)
{
    if (!records.empty())
    {
        for (vector <Record> :: iterator itr = records.begin(); itr != records.end(); itr++)
        {
            itr -> printRecordDataInBalanceFormat();
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No records." << endl << endl;
    }
}
