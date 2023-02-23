#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
    CMarkup usersFile;

    if (usersFile.Load(getFileName()))
    {
        usersFile.FindElem();
        usersFile.IntoElem();

    }
    else
    {
        usersFile.AddElem("RECORDS");
        usersFile.IntoElem();
    }

    usersFile.AddElem("USER");
    usersFile.IntoElem();

    usersFile.AddElem("ID", user.getID());
    usersFile.AddElem("NAME", user.getName());
    usersFile.AddElem("SURNAME", user.getSurname());
    usersFile.AddElem("LOGIN", user.getLogin());
    usersFile.AddElem("PASSWORD", user.getPassword());

    usersFile.Save(getFileName());
}

//string UsersFile::convertUserDataToDataInFileSyntax(User user)
//{
//    string lineWithUserData = "";
//
//    lineWithUserData += GeneralMethods::conversionIntToString(user.getID())+ '|';
//    lineWithUserData += user.getLogin() + '|';
//    lineWithUserData += user.getPassword() + '|';
//
//    return lineWithUserData;
//}

vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    vector <User>::iterator itr = users.begin();
    string singleUserDataInFileSyntax = "";
    CMarkup usersFile;
    int lastUserID = 0;
    users.clear();

    if (usersFile.Load(getFileName()))
    {
        usersFile.FindElem();
        usersFile.IntoElem();

        while (usersFile.FindElem("USER"))
        {
            usersFile.IntoElem();

            usersFile.FindElem("ID");
            if ((GeneralMethods::convertionStringToInt(usersFile.GetData())) > lastUserID)
            {
                user.setID(GeneralMethods::convertionStringToInt(usersFile.GetData()));
                lastUserID = GeneralMethods::convertionStringToInt(usersFile.GetData());
            }
            else
                break;

            usersFile.FindElem("NAME");
            user.setName(usersFile.GetData());

            usersFile.FindElem("SURNAME");
            user.setSurname(usersFile.GetData());

            usersFile.FindElem("LOGIN");
            user.setLogin(usersFile.GetData());

            usersFile.FindElem("PASSWORD");
            user.setPassword(usersFile.GetData());

            usersFile.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}

//User UsersFile::getUserDataFromDataInFileSyntax(string singleUserDataInFileSyntax)
//{
//    User user;
//    string singleUserData = "";
//    //int numerPojedynczejDanejUzytkownika = 1;
//
//    // TODO //
//
//    return user;
//}
//
//void UsersFile::saveAllUsersToFile(vector <User> &users)
//{
//    fstream textFile;
//    string lineWithUserData = "";
//    vector <User>::iterator itrEnd = --users.end();
//
//    textFile.open(getFileName().c_str(), ios::out);
//
//    if (textFile.good() == true)
//    {
//        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
//        {
//            lineWithUserData = convertUserDataToDataInFileSyntax(*itr);
//
//            if (itr == itrEnd)
//            {
//               textFile << lineWithUserData;
//            }
//            else
//            {
//                textFile << lineWithUserData << endl;
//            }
//            lineWithUserData = "";
//        }
//    }
//    else
//    {
//        cout << "It was not possible to open file " << getFileName() << endl;
//    }
//    textFile.close();
//}
