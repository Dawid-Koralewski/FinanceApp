#include "FinanceApp.h"

void FinanceApp::showMainMenu()
{
    char choice;
        if (loggedInUserID == 0)
        {
            choice = selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                loggedInUserID = userManager.userSignIn();
                break;
            case '2':
                 userManager.userSignUp();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such an option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            recordManager = new RecordManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, loggedInUserID);

            choice = selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                recordManager -> addIncome();
                break;

            case '2':
                recordManager -> addExpense();
                break;

            case '3':
                recordManager -> showBalanceFromCurrentMonth();
                break;

            case '4':
                recordManager -> showBalanceFromPreviousMonth();
                break;

            case '5':
                recordManager -> showBalanceFromSpecificRange();
                break;

            case '8':
                //userManager.changeLoggedInUserPassword();
                break;

            case '9':
                loggedInUserID = 0;
                delete recordManager;
                recordManager = NULL;
                break;
            }
        }
}

char FinanceApp::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> Main menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sing Up" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = GeneralMethods::readChar();

    return choice;
}

char FinanceApp::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> User menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from current month" << endl;
    cout << "4. Balance from past month" << endl;
    cout << "5. Balance from selected range" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = GeneralMethods::readChar();

    return choice;
}
