// TODO: class=<profile>
#pragma once
#include "../Keychain/keychain.h"
class profile
{
    //! -[PRIVATE]- !
private:
    string cUsername; //! cUsername
    string cPassword; //! cPassword

    //^ -[PROTECTED]- ^
protected:
    const string getUsername();               //^ getUsername
    const string getPasskey();                //^ getPasskey
    void setUsername(const string &username); //^ setUsername
    void setPassword(const string &password);   //^ setPasskey

    //* -[PUBLIC]- *
public:
    //* -constructor-
    profile(string username = _none, string password = _none);

    //* -destructor-
    ~profile();

    //* -overloads-
    friend ostream& operator<<(ostream& out, const profile& profile); 
    
};
