#include "User.h"

void User::setID(int newID)
{
    if (newID >= 0)
        ID = newID;
}

void User::setName(string newName)
{
    name = newName;
}


void User::setSurname(string newSurname)
{
    surname = newSurname;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}


void User::setPassword(string newPassword)
{
    password = newPassword;
}


int User::getID()
{
    return ID;
}

string User::getName()
{
    return name;
}


string User::getSurname()
{
    return surname;
}

string User::getLogin()
{
    return login;
}


string User::getPassword()
{
    return password;
}
