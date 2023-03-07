#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Record.h"
#include "GeneralMethods.h"
#include "XMLFile.h"

using namespace std;

class IncomesFile : public XMLFile
{

public:
    int lastIncomeID = 0;
    IncomesFile(string fileName) : XMLFile(fileName) {};
};

#endif
