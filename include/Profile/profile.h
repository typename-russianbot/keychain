//? | @author: Matthew H. | @github: typename-russianbot | ?

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
    const string getPassword(); //^ getPassword()

    //^ <SETTERS>
    void setUsername(const string &username = _none); //^ setUsername()
    void setPassword(const string& password = _none);                               //^ setPassword()

    //^ <HELPERS>
    bool profileNew(const string &username = _none, const string &password = _none); //^ 1. profileNew()
    bool profileDelete(const string &target);                                        //^ 2. profileDelete()
    bool profileSearch(const string &target);                                        //^ 3. profileSearch()
    bool profileAccess();                                                            //^ 4. profileAccess()
    bool profileLoad(const string &username);                                        //^ 5. profileLoad()
    bool profileSave();                                                              //^ 6. profileSave()

    //* -[PUBLIC]- *
public:
    //* <CONSTRUCTOR>
    profile(const string &username = _none, const string &password = _none);

    //* <DESTRUCTOR>
    ~profile();

    //* <FUNCTIONS>
    bool newProfile(const string &username = _none, const string &password = _none); //* 1. newProfile()
    bool deleteProfile(const string &target = _none);                                //* 2. deleteProfile()
    bool searchProfile(const string &target = _none);                                //* 3. searchProfile()
    bool accessProfile();                                                            //* 4. accessProfile()
    void printProfile();                                                             //* 5. printProfile()
    bool loadProfile(const string &target = _none);                                  //* 6. loadProfile()
    bool saveProfile();                                                              //* 7. saveProfile()

    //* <OVERLOADS>
    friend ostream &operator<<(ostream &out, const profile &profile); //* operator<<
    friend istream &operator>>(istream &in, const profile &profile);  //* operator>>
};
