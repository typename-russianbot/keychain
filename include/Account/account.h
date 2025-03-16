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
    account(const string &username = _none, const string &password = _none);

    //* <DESTRUCTOR>
    ~account();

    //* <FUNCTIONS>
    bool create();  //* create()
    bool remove();  //* remove()
    bool search();  //* search()
    bool details(); //* details()

    //* <OVERLOADS>
    friend ostream &operator<<(ostream &out, const account &account); //* operator<<
};