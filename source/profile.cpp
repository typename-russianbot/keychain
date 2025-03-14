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
bool profile::loadProfile(const string &username)
{
    ifstream readfile("data/profiles.txt"); //^ load profiles.txt for read

    if (!ValidateFile(readfile)) //! file failed to load
        return false;

    else //* file validated
    {
        string line, value;

        //* parse through file
        while (getline(readfile, line))
        {
            stringstream currentline(line);
            unsigned int i = 0;

            while (getline(currentline, value, ','))
            {
                checkProfile(i, value, username);
            }
        }

        if (username != cUsername)
        {
            return false;
        }

        readfile.close();
    }

    return true;
}
bool profile::saveProfile()
{
    ofstream writefile("data/profiles.txt", std::ios::app); //^ load profiles.txt for write & set write mode to append

    if (!ValidateFile(writefile)) //! file failed to load
        return false;

    else //* file validated
    {
        writefile << this->cUsername << "," << this->cPassword << endl; //* write to file
        writefile.close();
    }

    return true;
}
//^ checkProfile()
void profile::checkProfile(unsigned int &i, string &value, const string &username)
{
    switch (i)
    {
    case 0: //* case0:
        if (value == username)
            this->cUsername = value;

        i++;
        break;

    case 1: //* case1:
        if (username == cUsername)
            this->cPassword = value;
        break;
    }
}

//* -[PUBLIC]- *

//* -constructor-
profile::profile(const string &username)
{
    if (username == _none)
        cout << "prompt user for input here" << endl;
    else
    {
        if (!loadProfile(username))
        {
            cout << "Profile: '" << username << "' not found" << endl;
            exit(1);
        }
        else
            cout << "Profile: '" << username << "' found" << endl;
    }
}

profile::profile(const string &username, const string &password) : cUsername(username), cPassword(password)
{
    saveProfile();
}

//* -destructor-
profile::~profile()
{
}

//* -functions-
bool profile::search(const string &username)
{
    if (!loadProfile(username))
    {
        cout << "Profile: '" << username << "' not found" << endl;
        return false;
    }
    else
        cout << "Profile: '" << username << "' found" << endl;

    return true;
}

//* -overloads-
ostream &operator<<(ostream &out, const profile &profile)
{
    out << "Username: " << profile.cUsername << endl
        << "Password: " << profile.cPassword << endl;

    return out;
}