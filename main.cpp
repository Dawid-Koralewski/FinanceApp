#include <iostream>
#include "FinanceApp.h"

using namespace std;

int main()
{
    FinanceApp financeApp("users.xml", "incomes.xml", "expenses.xml");

    while (true)
    {
        financeApp.showMainMenu();
    }

    return 0;
}
