#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Record.h"
#include "GeneralMethods.h"
#include "XMLFile.h"

using namespace std;

class ExpensesFile : public XMLFile
{

public:
    int lastExpenseID = 0;
    ExpensesFile(string fileName) : XMLFile(fileName) {};
};

#endif
