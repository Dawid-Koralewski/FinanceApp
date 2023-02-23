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
//    Record getRecordDataFromDataInFileSyntax(string dataInFileSyntax);
//
public:
    ExpensesFile(string fileName) : XMLFile(fileName) {};
//    int getRecordIDFromDataInFileSyntax(string dataInFileSyntax);
//    int getUserIDFromDataInFileSyntax(string dataInFileSyntax);
//    int loadLoggedInUserRecordsFromFile(vector <Record> &records, int loggedInUserID);
//    void addRecordToFile(Record record);
//    string convertRecordDataToFileSyntax(Record record);
//    int getLastRecordFromFile();
//    void deleteFile(string fileNameIncludingExtention);
//    void changeFileName(string oldFileName, string newFileName);
};

#endif
