#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ <GETTERS> //^ @protected
const string profile::getUsername()
{
    return this->cUsername;
}
const string profile::getPassword()
{
    string input, verification;

    HideTerminal();

    //^ @note: prompt for password input
    cout << "Password: ";
    cin >> input;
    ValidateInput(input);
    cout << endl;

    //^ @note: prompt for password verification
    cout << "Re-enter Password: ";
    cin >> verification;
    ValidateInput(verification);
    cout << endl;

    ShowTerminal();

    if (input == verification) //* return input if it matches
        return input;
    else //! if input mis-match, return _none
        return _none;
}

//^ <SETTERS> ^// @protected
void profile::setUsername(const string &username)
{
    if (username == _none) //* @note: prompt for username if none is given
    {
        string input;

        do
        {
            cout << "Username: ";
            cin >> input;
        } while (!ValidateInput(input));

        cUsername = input;
        return;
    }
    else //* @note: set username to parameter
        this->cUsername = username;
}
void profile::setPassword(const string &password)
{
    if (password == _none)
    {
        char retry;
        string input, verification;

        HideTerminal();

        while (retry != 'n')
        {
            do //* get password
            {
                cout << "Password: ";
                cin >> input;
            } while (!ValidateInput(input));

            cout << endl;

            do //* get verification
            {
                cout << "Re-enter Password: ";
                cin >> verification;
            } while (!ValidateInput(verification));

            cout << endl;

            if (input == verification) //* @note: verify passkey inputs
            {
                ShowTerminal();
                this->cPassword = input;
                return;
            }

            else
            {
                do
                {
                    cout << "<ERROR>: Password Mismatch Detected" << endl
                         << "Re-attempt? [y/n]: ";

                    cin >> retry;
                    cout << endl;

                } while (!ValidateInput(retry));
            }
        }
    }

    ShowTerminal();
    cout << "<PASSWORD>: none" << endl;
    cPassword = _none;
}

//^ <HELPERS> ^// @protected

//^ 1. profileNew() ^/
//^ @def:
bool profile::profileNew(const string &username, const string &password)
{
    if (username == _none && password == _none) //! no data, cancel profile creation
    {
        setUsername();
        setPassword();

        if (cPassword == _none)
            cAccess = permitted;
        else
            cAccess = restricted;
    }
    else if (username != _none) //* username param accepted
    {
        cAccess = restricted;

        if (password == _none)
            cAccess = permitted;

        this->cUsername = username;
        this->cPassword = password;

        return true;
    }

    return false;
}

//^ 2. profileDelete() ^/
//^ @def:
bool profile::profileDelete(const string &target)
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
    deleteProfile("data/profiles.txt");
    rename("temp.txt", "data/profiles.txt");

    return true;
}

//^ 3. profileSearch() ^/
//^ @def:
bool profile::profileSearch(const string &target)
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

//^^ 4. profileAccess() ^/
//^ @def:
bool profile::profileAccess()
{
    char input;
    int attempts = 3;

    while (input != 'n' && attempts >= 0) //? continue loop until exited or passkey attempts has reached 0
    {
        //* match
        if (getPassword() == cPassword)
        {
            cAccess = permitted;
            return true;
        }

        //! mismatch encountered
        while (true)
        {
            do
            {
                cout << "| Remaining Attempts: " << attempts << " |" << endl
                     << "Re-enter Passkey? [y/n]: ";

                cin >> input;

            } while (!ValidateInput(input));

            if (input == 'n')
                return false;
            else
                break;
        }

        attempts--;
    }

    return false;
}

//^ 5. profileLoad() ^/
//^ @def: compares the target string to all other usernames in profiles.txt
bool profile::profileLoad(const string &target)
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
                    this->cUsername = line.substr(0, commaPos);
                    this->cPassword = line.substr(commaPos + 1);

                    readfile.close();
                    return true;
                }
            }
        }

        //! target not found
        readfile.close();
    }

    return false;
}

//^ 6. profileSave() ^/
//^ @def: writes the currently stored profile attributes to profiles.txt
bool profile::profileSave()
{
    ofstream writefile("data/profiles.txt", std::ios::app);

    if (!ValidateFile(writefile)) //! @note: file failed to load
        return false;

    //* @note: file validated
    writefile << this->cUsername << "," << this->cPassword << endl; //* @note: write profile data to savefile
    writefile.close();

    return true;
}

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *// @public
profile::profile(const string &username, const string &password)
{

    if (username == _none && password == _none) //* @if: both username & password are _none
    {
        setUsername();
        setPassword();

        if (cPassword == _none)
            cAccess = permitted;
        else
            cAccess = restricted;
    }
    else if (username != _none) //* @elseif: username is not empty
    {
        if (password == _none) //* un-restrict profile permissions
            cAccess = permitted;

        else //! restrict profile permissions
            cAccess = restricted;

        newProfile(username, password);
    }
    else
    {
        cout << "blank profile created" << endl;
        newProfile(username, password);
    }
}

//* <DESTRUCTOR> *// @public
profile::~profile()
{
}

//* <FUNCTIONS> *// @public

//** 1. newProfile() */
//* @def: takes the passed in username & password
bool profile::newProfile(const string &username, const string &password)
{
    if (profileNew(username, password)) //* profile created
        return true;

    return false; //! profile creation failed
}

//** 2. deleteProfile() */
//* @def: searches for the target, then removes it if found in the data fiel
bool profile::deleteProfile(const string &target)
{
    if (!searchProfile(target)) //! search for target in file before removal
        return false;

    if (profileDelete(target)) //* profile removed
        return true;

    return false; //! profile removal failed
}

//** 3. searchProfile() */
//* @def: takes the target string & compares it to all usernames in profiles.txt
bool profile::searchProfile(const string &target)
{
    if (profileSearch(target)) //* profile found
        return true;

    return false; //! profile search failed
}

//** 4. accessProfile() */
bool profile::accessProfile()
{
    if (profileAccess())
        return true;
    else
        return false;
}

//** 5. printProfile() */
//* @def:
void profile::printProfile()
{
    cout << *this;
}

//** 6. loadProfile() */
//* @def: first, searches for the profile before attempting to load. If found, load profile. Otherwise, return false
bool profile::loadProfile(const string &target)
{
    if (profileSearch(target)) //* target was found, load data
    {
        profileLoad(target);
        return true;
    }

    return false; //! target not found
}

//** 7. saveProfile() */
//* @def: saves the current username & password attributes to profiles.txt
bool profile::saveProfile()
{
    if (profileSave()) //* target saved to profiles.txt
        return true;

    return false; //! target failed to save
}

//* <OVERLOADS> *// @public
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