//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../master.h"

class profile {
  //! -[PRIVATE]- !//
private:
  string cUsername;  //! cUsername | @def: profile owner
  string cPassword;  //! cPassword | @def: profile password
  clearance cAccess; //! cAccess   | @def: profile restrictions

  //^ -[PROTECTED]- ^//
protected:
  //^ <MUTATORS>
  const string get_username();                       //^ get_username()
  void set_username(const string &username = _none); //^ set_username()

  const string get_password();                       //^ get_password()
  void set_password(const string &password = _none); //^ set_password()

  const clearance get_clearance();             //^ get_clearance()
  void set_clearance(const clearance &access); //^ set_clearance()

  //^ <HELPERS>
  bool search_profile(const string &target); //^ search_profile()
  bool request_access();                     //^ request_access()

  bool save_profile();                       //^ save_profile()
  bool load_profile(const string &target);   //^ load_profile()
  bool delete_profile(const string &target); //^ delete_profile()

  //* -[PUBLIC]- *//
public:
  //* <RESOURCE MANAGERS> *//
  profile(const string &username = _none,
          const string &password = _none); //* profile()
  ~profile();                              //* ~profile()

  //* <FUNCTIONS> *//
  bool searchProfile(const string &target = _none); //* searchProfile()
  bool getAccess();                                 //* getAccess()
  bool setRestricted();                             //* setRestricted()
  void printProfile();                              //* printProfile()

  bool saveProfile();                               //* saveProfile()
  bool loadProfile(const string &target = _none);   //* loadProfile()
  bool deleteProfile(const string &target = _none); //* deleteProfile()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const profile &profile); //* operator<<
};
