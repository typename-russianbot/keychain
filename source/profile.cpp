#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ <GETTERS>
//^ @protected
const string profile::getUsername()
{
    return this->cUsername;
}
const string profile::getPasskey()
{
    return this->cPassword;
}

//^ <SETTERS>
//^ @protected
void profile::setUsername(const string &username)
{
    this->cUsername = username;
}
void profile::setPassword(const string &password)
{
    this->cPassword = password;
}

//^ <HELPERS>
//^ @protected

//^ loadProfile()
//^ @def: compares the target string to all other usernames in profiles.txt
//* @returns true:
//! @returns false:
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
//^ @def: writes the currently stored profile attributes to profiles.txt
//* @returns true:
//! @returns false:
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
//^ @def:
//* @returns true:
//! @returns false:
bool profile::lookupProfile(const string &target)
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
//^ @def:
//* @returns true:
//! @returns false:
bool profile::deleteProfile(const string &target)
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
    removeProfile("data/profiles.txt");
    rename("temp.txt", "data/profiles.txt");

    return true;
}

//^ createProfile()
//^ @def:
//* @returns true:
//! @returns false:
bool profile::addProfile(const string &username, const string &password)
{
    if (username == _none && password == _none) //! no data, cancel profile creation
        return false;

    else if (username != _none) //* username param accepted
    {
        cAccess = restricted;

        if (password == _none)
            cAccess = permitted;

        setUsername(username);
        setPassword(password);

        save();
        return true;
    }

    return false;
}

//^^ profileAccess() ^/
//* @returns true: if access is permitted
//! @returns false: if access is restricted
bool profile::profileAccess()
{
    if (this->cAccess == permitted) //* access permitted
        return true;

    return false; //! access restricted
}

//* -[PUBLIC]- *

//* <CONSTRUCTOR>
//* @public
profile::profile(const string &username, const string &password)
{

    if (username == _none && password == _none) //* @if: both username & password are _none
    {
        //* 1. load profile data
        //* 2. create a new profile
        //* 3. exit program
    }
    else if (username != _none) //* @elseif: username is not empty
    {
        if (password == _none) //* un-restrict profile permissions
            cAccess = permitted;

        else //! restrict profile permissions
            cAccess = restricted;

        createProfile(username, password);
    }
    else
    {
        cout << "blank profile created" << endl;
        createProfile(username, password);
    }
}

//* <DESTRUCTOR>
//* @public
profile::~profile()
{
}

//* <FUNCTIONS>
//* @public

//** load() */
//* @def: first, searches for the profile before attempting to load. If found, load profile. Otherwise, return false
//* @returns true: profile loaded
//! @returns false: profile loading failed
bool profile::load(const string &target)
{
    if (lookupProfile(target)) //* target was found, load data
    {
        loadProfile(target);
        return true;
    }

    return false; //! target not found
}

//** save() */
//* @def: saves the current username & password attributes to profiles.txt
//* @returns true: profile saved
//! @returns false: profile saving failed
bool profile::save()
{
    if (saveProfile()) //* target saved to profiles.txt
        return true;

    return false; //! target failed to save
}

//** search() */
//* @def: takes the target string & compares it to all usernames in profiles.txt
//* @returns true: profile found
//! @returns false: profile search failed
bool profile::searchProfile(const string &target)
{
    if (lookupProfile(target)) //* profile found
        return true;

    return false; //! profile search failed
}

//** remove() */
//* @def:
//* @returns true: profile removed
//! @returns false: profile removal failed
bool profile::removeProfile(const string &target)
{
    if (!searchProfile(target)) //! search for target in file before removal
        return false;

    if (deleteProfile(target)) //* profile removed
        return true;

    return false; //! profile removal failed
}

//** create() */
//* @def: takes the passed in username & password
//* @returns true: profile created
//! @returns false: profile creation failed
bool profile::createProfile(const string &username, const string &password)
{
    if (addProfile(username, password)) //* profile created
        return true;

    return false; //! profile creation failed
}

//** printProfile() */
void profile::printProfile()
{
    cout << *this;
}

//* <OVERLOADS>
//* @public
ostream &operator<<(ostream &out, const profile &profile)
{
    if (profile.cAccess != restricted)
    {
        out << " - Username: " << profile.cUsername << endl
            << " - Password: " << profile.cPassword << endl;
    }
    else
    {
        out << " - Username: " << profile.cUsername << endl
            << " - Password: " << _censor << endl;
    }

    return out;
}