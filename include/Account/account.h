//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//? -[CLASS: Account]- ?
class account : public profile, public keychain
{
    //^ -[PROTECTED]- ^//
protected:
    //^ @def: put any helpers here if any are needed

    //* -[PUBLIC]- *//
public:
    //* <RESOURCE MANAGERS> *//
    account(const string &username = _none);
    ~account();

    //* <FUNCTIONS> *//
    bool switchAccount(const string &username = _none); //* switchAccount()
    void details();                                     //* details()
    void add();                                         //* addKey()
    bool deleteKey();                                   //* deleteKey()
    bool printKey(const string &keyname = _none);       //* printKey()

    bool loadAccount();   //* loadAccount()
    bool saveAccount();   //* saveAccount()
    bool deleteAccount(); //* deleteAccount()

    //* <OVERLOADS> *//
    friend ostream &operator<<(ostream &out, const account &account); //* operator<<
};