//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//? -[CLASS: Account]- ?
class account : public profile, public keychain
{
    //! -[PRIVATE]- !
private:
    lock cLock; //! cLock

    //^ -[PROTECTED]- ^
protected:
    //^ <HELPERS>
    bool unlock();   //^ unlock()
    bool relock();   //^ relock()
    bool isLocked(); //^ isLocked()

    //* -[PUBLIC]- *
public:
    //* <CONSTRUCTOR>
    account(const string &username = _none, const string &password = _none); //! @note: maybe we shouldn't have access to the password in constructors... always prompt the user for their password, not grab it from constructs

    //* <DESTRUCTOR>
    ~account();

    //* <FUNCTIONS>
    //* @details: class functions of account
    bool newAccount(const string &username = _none, const string &password = _none); //* newAccount()
    bool deleteAccount(const string &username = _none);                              //* deleteAccount()
    bool switchAccount(const string &username = _none);                              //* switchAccount()
    void details();                                                                  //* details()

    void addKey();    //* addKey()
    bool deleteKey(); //* deleteKey()
    bool printKey();  //* printKey()
};