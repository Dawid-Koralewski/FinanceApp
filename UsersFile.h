#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "GeneralMethods.h"
#include "XMLFile.h"

using namespace std;

class UsersFile : public XMLFile
{
//    string convertUserDataToDataInFileSyntax(User user);
//    User getUserDataFromDataInFileSyntax(string singleUserDataInFileSyntax);
//
public:
    UsersFile(string fileName) : XMLFile(fileName) {}
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
//    void saveAllUsersToFile(vector <User> &users);
};

#endif
