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
  bool init();
  void info();                             //* info()
  bool save();                             //* save()
  bool load(const string &target = _none); //* load()
  bool wipe(const string &target = _none); //* wipe()

  bool clean(const string &target = _none); //* clean()

  bool keyadd();                                //* keyadd()
  bool keyremove(const string &target = _none); //* keyremove()
  bool keyinfo(const string &target = _none);   //* keyinfo()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const account &account); //* operator<<
};