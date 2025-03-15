#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//? -[CLASS: Account]- ?
class account
{
    //! -[PRIVATE]- !
private:
    profile cProfile;   //! cProfile
    keychain cKeychain; //! cKeychain

    //^ -[PROTECTED]- ^
protected:
    //^^ ^/

    //* -[PUBLIC]- *
public:
    //* <CONSTRUCTOR>
    account(const string &username = _none, const string &password = _none);

    //* <DESTRUCTOR>
    ~account();

    //* <FUNCTIONS>
    bool create();  //* create()
    bool remove();  //* remove()
    bool search();  //* search()
    bool details(); //* details()
    bool unlock();  //* unlock()

    //* <OVERLOADS>
};