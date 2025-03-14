#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ -getters-
const string profile::getUsername()
{
    return this->cUsername;
}
const string profile::getPasskey()
{
    return this->cPassword;
}

//^ -setters-
void profile::setUsername(const string &username)
{
    this->cUsername = username;
}
void profile::setPassword(const string &password)
{
    this->cPassword = password;
}

//^ -load/save profiles-
void profile::loadProfile()
{
    ifstream readFile("data/profiles.txt");

    if (!readFile)
        cout << "file not loaded" << endl;
    else
        cout << "file was loaded" << endl;
}

void profile::saveProfile()
{
    ofstream writeFile("data/profiles.txt");

    if (!writeFile)
        cout << "file not loaded" << endl;
    else
        cout << "file was loaded" << endl;
}

//* -[PUBLIC]- *

//* -constructor-
profile::profile(const string &username, const string &password) : cUsername(username), cPassword(password)
{
}

//* -destructor-
profile::~profile()
{
}