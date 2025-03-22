//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//? -[CLASS: Account]- ?
class account : public profile, public keychain
{
    //^ -[PROTECTED]- ^
protected:
    //^ <HELPERS>


    //* -[PUBLIC]- *
public:
    //* <CONSTRUCTOR>
    account(const string &username = _none); //! @note: maybe we shouldn't have access to the password in constructors... always prompt the user for their password, not grab it from constructs

    //* <DESTRUCTOR>
    ~account();

    //* <FUNCTIONS>
    //* @details: class functions of account
    bool newAccount(const string &username = _none, const string &password = _none); //* newAccount()
    bool saveAccount();                                                              //* saveAccount()
    bool deleteAccount(const string &username = _none);                              //* deleteAccount()
    bool switchAccount(const string &username = _none);                              //* switchAccount()
    void details();                                                                  //* details()

    void add();                                   //* addKey()
    bool deleteKey();                             //* deleteKey()
    bool printKey(const string &keyname = _none); //* printKey()
};