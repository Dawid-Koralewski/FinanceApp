#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Record.h"
#include "GeneralMethods.h"
#include "Markup.h"

using namespace std;

class XMLFile
{
    const string FILE_NAME;
    int lastRecordID = 0;

public:

    XMLFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName();
    bool isFileEmpty();
    int dateConversionFromProgramToUserReadableSyntax(int dateInProgramSyntax);

//    Record getRecordDataFromDataInFileSyntax(string dataInFileSyntax);


//    int getRecordIDFromDataInFileSyntax(string dataInFileSyntax);
//    int getUserIDFromDataInFileSyntax(string dataInFileSyntax);
    int loadLoggedInUserRecordsFromFile(vector <Record> &incomes, int loggedInUserID);
    void addRecordToFile(Record record);
//    string convertRecordDataToFileSyntax(Record record);
//    int getLastRecordFromFile();
//    void deleteFile(string fileNameIncludingExtention);
//    void changeFileName(string oldFileName, string newFileName);
};

#endif
