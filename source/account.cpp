#include "../include/Account/account.h"

//^ -[PROTECTED]- ^

//^ <HELPERS>
bool account::unlock()
{
    if(this->cLock == unlocked)
        return true; 
    else{
        cLock = unlocked; 
        return true; 
    }

    return false; 
}
//* -[PUBLIC]- *

bool account::relock()
{
    return false;
}

//* <CONSTRUCTOR>
account::account(const string &username, const string &password)
{
    if (password == _none) //^ if no password is given, don't lock account
        cLock = unlocked;

    this->createProfile(username, password);
    this->createKey("keyname", "username", "email", "password"); 

    this->printKeychain(); 
    
}

//* <DESTRUCTOR>
account::~account()
{
}
