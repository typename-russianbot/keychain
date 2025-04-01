//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//** @notes:
//*
//*
//* */

//? -[CLASS: Account]- ?
class account : public profile, public keychain {
  //^ -[PROTECTED]- ^//
protected:
  //^ @def: put any helpers here if any are needed

  //* -[PUBLIC]- *//
public:
  //* <RESOURCE MANAGERS> *//
  account(const string &username = _none, const string &password = _none);
  ~account();

  //* <FUNCTIONS> *//

  void info();                             //* info()
  bool save();                             //* save()
  bool swap(const string &target = _none); //* swap()
  bool wipe(const string &target = _none); //* wipe()

  bool addKey();                                //* addKey()
  bool deleteKey(const string &target = _none); //* deleteKey()
  bool printKey(const string &target = _none);  //* printKey()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const account &account); //* operator<<
};