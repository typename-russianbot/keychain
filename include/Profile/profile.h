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
    //^ -getters-
    const string getUsername(); //^ getUsername()
    const string getPasskey();  //^ getPasskey()

    //^ -setters-
    void setUsername(const string &username); //^ setUsername()
    void setPassword(const string &password); //^ setPasskey()

    //^ -helpers-
    bool loadProfile(const string &username);                                  //^ loadProfile()
    bool saveProfile();                                                        //^ saveProfile()
    bool searchProfile(const string &target);                                  //^ searchProfile()

    //* -[PUBLIC]- *
public:
    //* -constructor-
    profile(const string &username = _none, const string &password = _none);

    //* -destructor-
    ~profile();

    //* -functions-
    bool load(const string &target = _none);   //* load()
    bool save();                               //* save()
    bool search(const string &target = _none); //* search()
    bool remove(const string &target = _none); //* remove()

    //* -overloads-
    friend ostream &operator<<(ostream &out, const profile &profile);
};
