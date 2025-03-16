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
    //^ <GETTERS>
    const string getUsername(); //^ getUsername()
    const string getPasskey();  //^ getPasskey()

    //^ <SETTERS>
    void setUsername(const string &username); //^ setUsername()
    void setPassword(const string &password); //^ setPasskey()

    //^ <HELPERS>
    bool loadProfile(const string &username);                           //^ loadProfile()
    bool saveProfile();                                                 //^ saveProfile()
    bool searchProfile(const string &target);                           //^ searchProfile()
    bool removeProfile(const string &target);                           //^ removeProfile()
    bool createProfile(const string &username, const string &password); //^ createProfile() 
    bool accessProfile();                                               //^ accessProfile()

    //* -[PUBLIC]- *
public:
    //* <CONSTRUCTOR>
    profile(const string &username = _none, const string &password = _none);

    //* <DESTRUCTOR>
    ~profile();

    //* <FUNCTIONS>
    bool load(const string &target = _none);                                     //* load()
    bool save();                                                                 //* save()
    bool search(const string &target = _none);                                   //* search()
    bool remove(const string &target = _none);                                   //* remove()
    bool create(const string &username = _none, const string &password = _none); //* create()
    bool print();                                                                //* print()

    //* <OVERLOADS>
    friend ostream &operator<<(ostream &out, const profile &profile); //* operator<<
};
