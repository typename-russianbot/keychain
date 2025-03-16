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
    bool unlock();                                                                                                 //^ unlock()
    bool relock();                                                                                                 //^ relock()
    bool isLocked();                                                                                               //^ isLocked()
    bool inputKeyData(const string &keyname, const string &username, const string &email, const string &password); //^ getKeyData()
    bool getTarget(const string &target);                                                                          //^ getTarget()

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
    void details(); //* details()

    bool add();    //* addKey()
    bool removeKey(); //* removeKey()
    bool printKey();  //* printKey()
};