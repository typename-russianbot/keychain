#pragma once
#include "../master.h"

//& -[CLASS: profile]- &
class profile
{
    //! -[PRIVATE]- !
private:
    string cUsername;  //! cUsername
    string cPassword;  //! cPassword
    clearance cAccess; //! cAccess

    //^ -[PROTECTED]- ^
protected:
    const string getUsername();                                                //^ getUsername()
    const string getPasskey();                                                 //^ getPasskey()
    void setUsername(const string &username);                                  //^ setUsername()
    void setPassword(const string &password);                                  //^ setPasskey()
    bool loadProfile(const string &username);                                  //^ loadProfile()
    bool saveProfile();                                                        //^ saveProfile()
    void checkProfile(unsigned int &i, string &value, const string &username); //^ parseLine()

    //* -[PUBLIC]- *
public:
    //* -constructor-
    profile(const string &username = _none);                 //* 1. searches for a profile based on the passed in string
    profile(const string &username, const string &password); //* 2. sets both username & password to the passed in params

    //* -destructor-
    ~profile();

    //* -functions-
    bool search(const string &username = _none);

    //* -overloads-
    friend ostream &operator<<(ostream &out, const profile &profile);
};
