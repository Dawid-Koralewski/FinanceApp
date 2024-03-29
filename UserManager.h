#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;

    User provideNewUserData();
    int getNewUserID();
    bool doesLoginExist(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName) {
        users = usersFile.loadUsersFromFile();
    };
    void userSignUp();
    void printAllUsers();
    int userSignIn();
    void changeLoggedInUserPassword(int loggedInUserID);
};

#endif
