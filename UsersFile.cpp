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

vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
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

void UsersFile::saveAllUsersToFile(vector <User> &users)
{
    remove("users.xml");
    for (vector <User> :: iterator itr = users.begin(); itr != users.end() && !users.empty(); itr++)
    {
        addUserToFile(*itr);
    }
}
