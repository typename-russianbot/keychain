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
public:
  //* <RESOURCE MANAGERS> *//
  account(const string &username = _none, const string &password = _none);
  ~account();

  //* <FUNCTIONS> *//

  void info();                             //* info()
  bool save();                             //* save()
  bool swap(const string &target = _none); //* swap()
  bool wipe(const string &target = _none); //* wipe()

  bool keyadd();                                //* keyadd()
  bool keyremove(const string &target = _none); //* keyremove()
  bool keyinfo(const string &target = _none);   //* keyinfo()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const account &account); //* operator<<
};