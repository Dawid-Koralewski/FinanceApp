#include "XMLFile.h"

string XMLFile::getFileName()
{
    return FILE_NAME;
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
