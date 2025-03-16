#include "../include/Account/account.h"

//^ -[PROTECTED]- ^
//^ @protectedsection

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

//* -[PUBLIC]- *
//* @publicsection

//* <CONSTRUCTOR>
//* @public
account::account(const string &username, const string &password) : cLock(locked)
{
    if (password == _none) //^ if no password is given, don't lock account
        cLock = unlocked;

    addProfile(username, password);
    addPassword(password);
}

//* <DESTRUCTOR>
//* @public
account::~account()
{
}

//* <FUNCTIONS>
//* @public

//** create() */
bool account::create()
{
    return false;
}

//** remove() */
bool account::remove()
{
    return false;
}

//** search() */
bool account::search()
{
    return false;
}

//** details() */
bool account::details()
{
    //* print profile data
    this->printProfile(); 

    //* print keychain data
    if (this->printKeychain())
        return true;

    return false;
}

//* <OVERLOADS>

//** operator<< */
ostream &operator<<(ostream &out, const account &account)
{
    // TODO: insert return statement here

    return out;
}
