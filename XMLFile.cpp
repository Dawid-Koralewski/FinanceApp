#include "XMLFile.h"

string XMLFile::getFileName()
{    return FILE_NAME;
}

bool XMLFile::isFileEmpty()
{
    bool isEmpty = true;
//    xmlFile.open(getFileName().c_str(), ios::app);
//
//    if (xmlFile.good() == true)
//    {
//        xmlFile.seekg(0, ios::end);
//        if (xmlFile.tellg() != 0)
//            isEmpty = false;
//    }

//    xmlFile.close();
    return isEmpty;
}

int XMLFile::loadLoggedInUserRecordsFromFile(vector <Record> &records, int loggedInUserID)
{
    records.clear();
    CMarkup recordsFile;
    Record record;
    lastRecordID = 0;

    if (recordsFile.Load(getFileName()))
    {
        recordsFile.FindElem();
        recordsFile.IntoElem();

        while (recordsFile.FindElem("RECORD"))
        {
            recordsFile.IntoElem();

            recordsFile.FindElem("ID");
            if ((GeneralMethods::convertionStringToInt(recordsFile.GetData())) > lastRecordID)
            {
                record.setID(GeneralMethods::convertionStringToInt(recordsFile.GetData()));
                lastRecordID = GeneralMethods::convertionStringToInt(recordsFile.GetData());
            }
            else
                break;

            recordsFile.FindElem("USERID");
            record.setUserID(GeneralMethods::convertionStringToInt(recordsFile.GetData()));

            recordsFile.FindElem("DATE");

            record.setDate(GeneralMethods::convertionStringDateToDate(recordsFile.GetData()));

            recordsFile.FindElem("TYPE");
            record.setType(recordsFile.GetData());

            recordsFile.FindElem("AMOUNT");
            record.setAmount(atof(recordsFile.GetData().c_str()));

            recordsFile.OutOfElem();

            if (record.getUserID() == loggedInUserID)
                records.push_back(record);
        }
    }

    return lastRecordID;

//    string singleRecordDataInFileSyntaxt = "";
//    string lastRecordDataInFile = "";
//    fstream textFile;
//
//    textFile.open(getFileName().c_str(), ios::in);
//
//    if (textFile.good() == true)
//    {
//        while (getline(textFile, singleRecordDataInFileSyntaxt))
//        {
//            if(loggedInUserID == getUserIDFromDataInFileSyntax(singleRecordDataInFileSyntaxt))
//            {
//                record = getRecordDataFromDataInFileSyntax(singleRecordDataInFileSyntaxt);
//                records.push_back(record);
//            }
//        }
//        lastRecordDataInFile = singleRecordDataInFileSyntaxt;
//    }
//    else
//    {
//        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
//        system("pause");
//    }
//
//    textFile.close();
//
//    if (lastRecordDataInFile != "")
//    {
//        recordID = getRecordIDFromDataInFileSyntax(lastRecordDataInFile);
//        return recordID;
//    }
//    else
//    {
//        cout << endl << endl << "ZERO" << endl << endl;
//        return 0;
//    }
}

void XMLFile::addRecordToFile(Record record)
{
        CMarkup recordsFile;

    if (recordsFile.Load(getFileName()))
    {
        recordsFile.FindElem();
        recordsFile.IntoElem();
    }
    else
    {
        recordsFile.AddElem("RECORDS");
        recordsFile.IntoElem();
    }

    recordsFile.AddElem("RECORD");
    recordsFile.IntoElem();

    recordsFile.AddElem("ID", record.getID());
    recordsFile.AddElem("USERID", record.getUserID());
    recordsFile.AddElem("DATE", record.getDateString());
    recordsFile.AddElem("TYPE", record.getType());
    recordsFile.AddElem("AMOUNT", to_string(record.getAmount()));

    recordsFile.Save(getFileName());
}
//Record RecordsFile::getRecordDataFromDataInFileSyntax(string dataInFileSyntax)
//{
//    Record record;
//
//    // TODO //
//
//    return record;
//}
//
//int RecordsFile::getUserIDFromDataInFileSyntax(string dataInFileSyntax)
//{
//    int userID = 0;
////    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
////    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
//
//    // TODO //
//
//    return userID;
//}
//
//int RecordsFile::getRecordIDFromDataInFileSyntax(string dataInFileSyntax)
//{
//    //int pozycjaRozpoczeciaIdAdresata = 0;
//    int idAdresata = 0;
//    //int idAdresata = GeneralMethods::convertionStringToInt(GeneralMethods::getNumber(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
//    return idAdresata;
//}
//
//string RecordsFile::convertRecordDataToFileSyntax(Record record)
//{
//    string lineWithRecordData = "";
//
//    lineWithRecordData += GeneralMethods::conversionIntToString(record.getRecordID()) + '|';
//    lineWithRecordData += GeneralMethods::conversionIntToString(record.getUserID()) + '|';
//
//    return lineWithRecordData;
//}
//
//int RecordsFile::getLastRecordFromFile()
//{
//    int lastRecordID = 0;
//    string singleRecordDataInFileSyntaxt = "";
//    string lastRecordDataInFile = "";
//    fstream textFile;
//    textFile.open(getFileName().c_str(), ios::in);
//
//    if (textFile.good() == true)
//    {
//        while (getline(textFile, singleRecordDataInFileSyntaxt)) {}
//            lastRecordDataInFile = singleRecordDataInFileSyntaxt;
//            textFile.close();
//    }
//    else
//        cout << "It was not possible to open file and load data." << endl;
//
//    if (lastRecordDataInFile != "")
//    {
//        lastRecordID = getRecordIDFromDataInFileSyntax(lastRecordDataInFile);
//    }
//    return lastRecordID;
//}
//
//void RecordsFile::deleteFile(string nazwaPlikuZRozszerzeniem)
//{
//    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
//    else
//        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
//}
//
//void RecordsFile::changeFileName(string oldName, string newName)
//{
//    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
//    else
//        cout << "File name was not changed." << oldName << endl;
//}
