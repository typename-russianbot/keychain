//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../Keychain/keychain.h"
#include "../Profile/profile.h"

//? -[CLASS: Account]- ?
class account : public profile, public keychain {
  //^ -[PROTECTED]- ^//
protected:
  //^ @def: put any helpers here if any are needed

  //* -[PUBLIC]- *//
public:
  //* <RESOURCE MANAGERS> *//
  account(const string &username = _none, const string& password = _none);
  ~account();

  //* <FUNCTIONS> *//
  bool swap(const string &username = _none);    //* swap()
  void details();                               //* details()
  void addKey();                                //* addKey()
  bool deleteKey();                             //* deleteKey()
  bool printKey(const string &keyname = _none); //* printKey()

  bool loadAccount();   //* loadAccount()
  bool saveAccount();   //* saveAccount()
  bool deleteAccount(); //* deleteAccount()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const account &account); //* operator<<
};