//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../master.h"

class profile
{
    //! -[PRIVATE]- !
private:
    string cUsername;  //! cUsername | @def: profile owner
    string cPassword;  //! cPassword | @def: profile password
    clearance cAccess; //! cAccess   | @def: profile restrictions

    //^ -[PROTECTED]- ^
protected:
    //^ <GETTERS>
    const string getUsername(); //^ getUsername()
    const string getPassword(); //^ getPassword()
    bool getClearance();        //^ getClearance()

    //^ <SETTERS>
    void setUsername(const string &username = _none); //^ setUsername()
    void setPassword(const string &password = _none); //^ setPassword()
    void setClearance(const clearance &access);       //^ setClearance()

    //^ <HELPERS>
    bool search_profile(const string &target); //^ search_profile()
    bool load_profile(const string &username); //^ load_profile()
    bool save_profile();                       //^ save_profile()
    bool delete_profile(const string &target); //^ delete_profile()

    //* -[PUBLIC]- *
public:
    //* <RESOURCE MANAGERS> *//
    profile(const string &username = _none, const string &password = _none); //* profile()
    ~profile();                                                              //* ~profile()

    //* <FUNCTIONS> *//
    bool searchProfile(const string &target = _none); //* searchProfile()
    bool accessProfile();                             //* accessProfile()
    bool restrictProfile();                           //* restrictProfile()
    void printProfile();                              //* printProfile()

    bool loadProfile(const string &target = _none);   //* loadProfile()
    bool saveProfile();                               //* saveProfile()
    bool deleteProfile(const string &target = _none); //* deleteProfile()

    //* <OVERLOADS> *//s
    friend ostream &operator<<(ostream &out, const profile &profile); //* operator<<
};
