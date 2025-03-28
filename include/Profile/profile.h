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
  const string get_username();
  const string get_password();
  const clearance get_clearance();
  void set_username(const string &username = _none);
  void set_password(const string &password = _none);
  void set_clearance(const clearance &access);

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
  bool accessProfile();                             //* accessProfile()
  bool restrictProfile();                           //* restrictProfile()
  void printProfile();                              //* printProfile()

  bool saveProfile();                               //* saveProfile()
  bool loadProfile(const string &target = _none);   //* loadProfile()
  bool deleteProfile(const string &target = _none); //* deleteProfile()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const profile &profile); //* operator<<
};
