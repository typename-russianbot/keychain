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

//^^ getKeyData() ^/
bool account::inputKeyData(const string &keyname, const string &username, const string &email, const string &password)
{

    return false;
}

//^^ ^/

//* -[PUBLIC]- *// @publicsection

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
//* @def: 
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
void account::details()
{
    cout << "|--Details--------------|" << endl
         << endl;

    cout << " - Account: " << cLock << endl;

    //* print profile data
    this->printProfile();

    cout << " - Keys Found: " << getKeys() << endl
         << endl;

    cout << "|------------------------|" << endl;
}

//^^ addKey() ^/
bool account::add()
{
    //* input variables
    key newKey; 
    cin >> newKey; 

    this->addKey(newKey); 

    return false; //! failed to add key
}
