#include "UserManager.h"

User UserManager::provideNewUserData()
{
    User user;

    user.setID(getNewUserID());

    cout << "Name: ";
    user.setName(GeneralMethods::readLine());

    cout << "Surname: ";
    user.setSurname(GeneralMethods::readLine());

    do
    {
        cout << endl << "Login: ";
        user.setLogin(GeneralMethods::readLine());
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Password: ";
    user.setPassword(GeneralMethods::readLine());

    return user;
}

int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userSignUp()
{
    User user = provideNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << "Account was successfully created." << endl << endl;

    system("pause");
}

void UserManager::printAllUsers()
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        cout << endl << users[i].getID();
        cout << endl << users[i].getName();
        cout << endl << users[i].getSurname();
        cout << endl << users[i].getLogin();
        cout << endl << users[i].getPassword();
    }
}

int UserManager::userSignIn()
{
    int userID;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = GeneralMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int triesAmount = 3; triesAmount > 0; triesAmount--)
            {
                cout << "Provide password. Tries left: " << triesAmount << ": ";
                password = GeneralMethods::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    //system("pause");

                    userID = itr -> getID();
                    return userID;
                }
            }
            cout << "You have entered wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "The is no user with this login." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changeLoggedInUserPassword(int loggedInUserID)
{
    string newPassword = "";
    cout << "New password: ";
    newPassword = GeneralMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getID() == loggedInUserID
            )
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveAllUsersToFile(users);
}
