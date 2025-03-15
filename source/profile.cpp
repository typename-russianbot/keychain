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

//^ -helpers-

//^ loadProfile()
bool profile::loadProfile(const string &target)
{
    ifstream readfile("data/profiles.txt");

    if (!ValidateFile(readfile)) //! file failed to load
        return false;

    else //* file validated
    {
        string line;

        while (getline(readfile, line))
        {
            size_t commaPos = line.find(',');

            //? validate commaPos
            if (commaPos != string::npos)
            {
                if (line.substr(0, commaPos) == target) //* target found
                {
                    setUsername(line.substr(0, commaPos));
                    setPassword(line.substr(commaPos + 1));

                    readfile.close();
                    return true;
                }
            }
        }

        //! target not found
        readfile.close();
        return false;
    }
}

//^ saveProfile()
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

//^ searchProfile()
bool profile::searchProfile(const string &target)
{
    ifstream readfile("data/profiles.txt");

    if (!ValidateFile(readfile)) //! file failed to load
        return false;

    else //* file validated
    {
        string line;

        //^ parse thru file
        while (getline(readfile, line))
        {
            size_t commaPos = line.find(',');

            //^ validate commaPos
            if (commaPos != string::npos)
            {
                //* target found
                if (line.substr(0, commaPos) == target)
                {
                    readfile.close();
                    return true;
                }
            }
        }

        //! target not found
        readfile.close();
        return false;
    }
}

bool profile::removeProfile(const string &target)
{
    return false;
} 

//* -[PUBLIC]- *

//* -constructor-
//* @details:
//* if both username & password are empty, prompt for user input
//* if username is not empty &
profile::profile(const string &username, const string &password) : cUsername(username), cPassword(password), cAccess(restricted)
{

    if (username == _none && password == _none) //! both username & password are empty; prompt for input
    {
        cout << "prompt user for input here" << endl;
    }
    else if (username != _none && password == _none) //^ search for passed in username & load data (if found) into this profile
    {
        if (!loadProfile(username))
        {
            cout << "Profile: '" << username << "' not found" << endl;
            exit(1);
        }
        else
            cout << "Profile: '" << username << "' found" << endl;
    }
    else if (username != _none && password != _none)
    {
        setUsername(username);
        setPassword(password);
    }
    else
    {
        exit(1);
    }
}

//* -destructor-
profile::~profile()
{
}

//* -functions-

//** load() */
bool profile::load(const string &target)
{
    if (searchProfile(target)) //* target was found, load data
    {
        loadProfile(target);
        return true;
    }
    
    return false; //! target not found
}

//** save() */
bool profile::save()
{
    if (saveProfile()) //* target saved to profiles.txt
        return true;

    return false; //! target failed to save
}

//** search() */
bool profile::search(const string &target)
{
    if (searchProfile(target))
        return true;

    return false;
}

//** remove() */
bool profile::remove(const string &target)
{
    return false;
}

//* -overloads-
ostream &operator<<(ostream &out, const profile &profile)
{
    out << "Username: " << profile.cUsername << endl
        << "Password: " << profile.cPassword << endl;

    return out;
}