//#include "RecordsFile.h"
//
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
//int RecordsFile::loadLoggedInUserRecordsFromFile(vector <Record> &records, int loggedInUserID)
//{
//    records.clear();
//    Record record;
//    int recordID = 0;
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
//}
//
//void RecordsFile::addRecordToFile(Record record)
//{
//    string lineWithRecordData = "";
//    fstream textFile;
//    textFile.open(getFileName().c_str(), ios::out | ios::app);
//
//    if (textFile.good() == true)
//    {
//        lineWithRecordData = convertRecordDataToFileSyntax(record);
//
//        if (isFileEmpty() == true)
//        {
//            textFile << lineWithRecordData;
//        }
//        else
//        {
//            textFile << endl << lineWithRecordData ;
//        }
//    }
//    else
//    {
//        cout << "It was not possible to open file and save data in it." << endl;
//    }
//    textFile.close();
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
