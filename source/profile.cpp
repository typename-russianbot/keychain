#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ -getters-
//^ @protected
const string profile::getUsername()
{
    return this->cUsername;
}
const string profile::getPasskey()
{
    return this->cPassword;
}

//^ -setters-
//^ @protected
void profile::setUsername(const string &username)
{
    this->cUsername = username;
}
void profile::setPassword(const string &password)
{
    this->cPassword = password;
}

//^ -helpers-
//^ @protected

//^ loadProfile()
//^ @def: compares the target string & compares it to
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
//^ @def
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
//^ @def
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

//^ removeProfile()
//^ @def
bool profile::removeProfile(const string &target)
{
    //* create readfile obj
    ifstream readfile("data/profiles.txt");
    ofstream tempfile("temp.txt");

    if (!ValidateFile(readfile)) //! file load failure
        return false;

    else //* file validated
    {
        string line;

        //^ get each line from profiles.txt, except the target line
        while (getline(readfile, line))
        {
            if (line.find(target) == string::npos) //* write all lines that aren't target to temp.txt
                tempfile << line << endl;
        }
    }

    //^ close opened files
    readfile.close();
    tempfile.close();

    //^ update profiles.txt to temp.txt
    remove("data/profiles.txt");
    rename("temp.txt", "data/profiles.txt");

    return true;
}

//^ createProfile()
//^ @def:
bool profile::createProfile(const string &username, const string &password)
{
    return false;
}

//* -[PUBLIC]- *

//* -constructor-
//* @public
profile::profile(const string &username, const string &password) : cUsername(username), cPassword(password), cAccess(restricted)
{

    if (username == _none && password == _none) //! both username & password are empty
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
//* @public
profile::~profile()
{
}

//* -functions-
//* @public

//** load() */
//* @def:
//* @returns true:
//! @returns false:
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
//* @def: saves the current username & password attributes to profiles.txt
//* @returns true: target saved to profiles.txt
//! @returns false: target failed to save
bool profile::save()
{
    if (saveProfile()) //* target saved to profiles.txt
        return true;

    return false; //! target failed to save
}

//** search() */
//* @def: takes the target string & compares it to all usernames in profiles.txt
//* @returns true:
//! @returns false:
bool profile::search(const string &target)
{
    if (searchProfile(target))
        return true;

    return false;
}

//** remove() */
//* @def:
//* @returns true: target was removed
//! @returns false: target removal failure
bool profile::remove(const string &target)
{

    if (!search(target)) //! search for target in file before removal
    {
        cout << "profile doesn't exist" << endl;
        return false;
    }

    if (removeProfile(target)) //* target removed
        return true;

    else //! target removal failure
        return false;
}

//** create() */
//* @def: takes the passed in username & password
bool profile::create(const string &username, const string &password)
{
    return false;
}

//* -overloads-
//* @public

ostream &operator<<(ostream &out, const profile &profile)
{
    out << "Username: " << profile.cUsername << endl
        << "Password: " << profile.cPassword << endl;

    return out;
}