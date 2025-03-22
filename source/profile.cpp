#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ [---GETTERS---] ^//

//^ getUsername() | @def:
const string profile::getUsername()
{
    return this->cUsername;
}
//^ getPassword() | @def:
const string profile::getPassword()
{
    if (cAccess == restricted)
    {
        string input, verification; //* @var:

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

        if (input == verification && input == cPassword) //* input & verification match
            return input;
        else //! mismatch,
            return _none;
    }
    else
        return cPassword;
}
//^ getClearance() | @def:
bool profile::getClearance()
{
    if (cAccess == unrestricted) //* @note: check if access is restricted
        return true;

    char input;       //* @var:
    int attempts = 3; //* @var:

    while (input != 'n' && attempts > 0)
    {
        if (getPassword() == cPassword) //* @note: password match
        {
            return true;
        }

        while (true) //! @note: continue until passwords match or attempts reaches zero...
        {
            do
            {
                cout << "| Remaining Attempts: " << attempts << " |" << endl
                     << "Re-enter Passkey? [y/n]: ";

                cin >> input;

            } while (!ValidateInput(input));

            if (input == 'n') //! @note: user cancelled operation
                return false;
            else
                break;
        }
        attempts--;
    }

    return false;
}

//^ [---SETTERS---]

//^ setUsername() | @def:
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
//^ setPassword() | @def:
void profile::setPassword(const string &password)
{
    char retry;
    string input, verification;

    HideTerminal();

    //* @note:
    while (retry != 'n')
    {
        do
        {
            cout << "Password: ";
            cin >> input;
        } while (!ValidateInput(input));
        cout << endl;

        do
        {
            cout << "Re-enter Password: ";
            cin >> verification;
        } while (!ValidateInput(verification));
        cout << endl;

        if (input == verification)
        {
            ShowTerminal();
            cPassword = input;
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

    ShowTerminal();
    cPassword = _none;
}
//^ setClearance() | @def:
void profile::setClearance(const clearance &access)
{
    cAccess = access;
}

//^ [---HELPERS---] ^//

//^^ search_profile() ^/
bool profile::search_profile(const string &target)
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
//^^ load_profile() ^/
bool profile::load_profile(const string &target)
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
//^^ save_profile() ^/
bool profile::save_profile()
{
    ofstream writefile("data/profiles.txt", std::ios::app);

    if (!ValidateFile(writefile)) //! @note: file failed to load
        return false;

    //* @note: file validated
    writefile << this->cUsername << "," << this->cPassword << endl; //* @note: write profile data to savefile
    writefile.close();

    return true;
}
//^^ delete_profile() ^/
bool profile::delete_profile(const string &target)
{
    //* @var:
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

//* [---RESOURCE MANAGERS---] *//
profile::profile(const string &username, const string &password) : cUsername(username), cPassword(password)
{
    if (cPassword == _none)
        cAccess = unrestricted;
    else
        cAccess = restricted;
}
profile::~profile()
{
}

//* [---FUNCTIONS---] *//

//** searchProfile() */
bool profile::searchProfile(const string &target)
{
    if (search_profile(target)) //* @note: target found
        return true;

    return false; //! @note: target wasn't found
}
//** accessProfile() */
bool profile::accessProfile()
{
    if (getClearance())
    {
        cAccess = unrestricted;
        return true;
    }

    return false;
}
//** restrictProfile() */
bool profile::restrictProfile()
{
    if (getClearance())
    {
        cAccess = restricted;
        return true;
    }

    return false;
}
//** printProfile() */
void profile::printProfile()
{
    cout << *this;
}

//** loadProfile()  */
bool profile::loadProfile(const string &target)
{
    if (search_profile(target) && load_profile(target))
    {
        if (cPassword == _none)
            cAccess = unrestricted;
        else
            cAccess = restricted;

        cout << cPassword << endl;
        return true;
    }

    return false; //! target not found
}
//** saveProfile() */
bool profile::saveProfile()
{
    if (save_profile()) //* target saved to profiles.txt
        return true;

    return false; //! target failed to save
}
//** deleteProfile() */
bool profile::deleteProfile(const string &target)
{
    if (searchProfile(target) && delete_profile(target))
    {
        cUsername = _none;
        cPassword = _none;
        cAccess = unrestricted;
        return true;
    }

    return false; //! profile removal failed
}

//* <OVERLOADS> *//
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