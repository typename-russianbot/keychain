#include "../include/Account/account.h"

//^ -[PROTECTED]- ^// @protectedsection

//^ <HELPERS>
//^ @protected

//^^ unlock() ^/
bool account::unlock()
{
    if (this->cLock == unlocked) //* already unlocked
        return true;

    else //* unlock account
    {
        cLock = unlocked;
        return true;
    }

    return false; //! failed to unlock
}

//^^ relock() ^/
bool account::relock()
{
    if (cLock == locked) //* already locked
        return true;

    else //* lock account
    {
        cLock = locked;
        return true;
    }

    return false; //! failed to re-lock account
}

//^^ isLocked() ^/
bool account::isLocked()
{
    if (cLock == locked) //* account is locked
        return true;

    return false; //! account is unlocked
}

//^^ ^/

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *// @public
account::account(const string &username, const string &password) : cLock(locked)
{
    if (username == _none && password == _none) //! both username & password are empty
    {
    }
    else
    {
        if (password == _none) //^ if no password is given, don't lock account
            cLock = unlocked;

        profileNew(username, password);
    }
}

//* <DESTRUCTOR> *// @public
account::~account()
{
}

//* <FUNCTIONS> *// @public

//** create() */
//* @def:
bool account::newAccount(const string &username, const string &password)
{
    return false;
}

//** wipe() */
//* @def: 
bool account::deleteAccount(const string &username)
{
    //! @note: need to add wipe feature for keychain

    //* @note: if no username is specified, remove the current profile
    if (username == _none && this->deleteProfile(getUsername()))
    {
        //* @note: overwrite current data in username & password
        this->setUsername(_none);
        // this->setPassword(); @note: use setPassword in account
        return true;
    }

    return false;
}

//** swap() */
//* @def:
bool account::switchAccount(const string &username)
{
    if (username == _none) //! no name specified to swap to
        return false;
    else
    {
        if (!this->searchProfile(username)) //! profile not found
            return false;

        else //* profile found
        {
            this->saveProfile();                //* @note: save current profile
            this->profileLoad(username); //* @note: load designated profile
        }
    }

    return true;
}

//** details() */
//* @def:
void account::details()
{
    cout << "|--Details---------------|" << endl
         << endl;

    cout << " - Account: " << cLock << endl; //* @note: display current account state

    this->printProfile(); //* @note: print profile data

    cout << " - Keys Found: " << getKeys() << endl //* @note: display the number of keys on this account
         << endl;

    cout << "|------------------------|" << endl;
}

//** add() */
//* @def:
void account::addKey()
{
    key newKey; //* @note: create a new key object

    cin >> newKey; //* @note: get data for new key

    this->keyNew(newKey); //* @note: add the key
}

bool account::deleteKey()
{
    return false;
}
