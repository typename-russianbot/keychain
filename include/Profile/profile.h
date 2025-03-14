// TODO: class=<profile>
#pragma once
#include "../master.h"
class profile
{
    //! -[PRIVATE]- !
private:
    string cUsername; //! cUsername
    string cPassword; //! cPassword

    //^ -[PROTECTED]- ^
public: 
    const string getUsername();               //^ getUsername()
    const string getPasskey();                //^ getPasskey()
    void setUsername(const string &username); //^ setUsername()
    void setPassword(const string &password); //^ setPasskey()
    void loadProfile();                       //^ loadProfile()
    void saveProfile();                       //^ saveProfile()

    //* -[PUBLIC]- *
public:
    //* -constructor-
    profile(const string &username = _none, const string &password = _none);

    //* -destructor-
    ~profile();

    //* -overloads-
    friend ostream &operator<<(ostream &out, const profile &profile);
};
