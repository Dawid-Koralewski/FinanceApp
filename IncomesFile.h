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
//    Record getRecordDataFromDataInFileSyntax(string dataInFileSyntax);

public:
    IncomesFile(string fileName) : XMLFile(fileName) {};
//    int getRecordIDFromDataInFileSyntax(string dataInFileSyntax);
//    int getUserIDFromDataInFileSyntax(string dataInFileSyntax);
//    int loadLoggedInUserRecordsFromFile(vector <Record> &incomes, int loggedInUserID);
//    void addRecordToFile(Record record);
//    string convertRecordDataToFileSyntax(Record record);
//    int getLastRecordFromFile();
//    void deleteFile(string fileNameIncludingExtention);
//    void changeFileName(string oldFileName, string newFileName);
};

#endif
