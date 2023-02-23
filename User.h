#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int ID = 0;
    string name;
    string surname;
    string login;
    string password;

public:
    void setID(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getID();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
};

#endif
