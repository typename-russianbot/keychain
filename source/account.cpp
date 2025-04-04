#include "../include/Account/account.h"
#include <iostream>

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *//
account::account(const string &username, const string &password) {

  //* @note: set profile data
  set_username(username);
  set_password(password);

  //* @def: set keychain data
  if (username != _none)
    set_owner(username);
}

//* <DESTRUCTOR> *//
account::~account() {}

//* <FUNCTIONS> *//

//** info() | @def:
void account::info() {
  cout << "|--Account Info---------------|" << endl << endl;

  cout << " - Account: " << get_clearance()
       << endl; //* @note: display current account state

  this->printProfile(); //* @note: print profile data

  cout << " - Keys Found: " << get_keys()
       << endl //* @note: display the number of keys on this account
       << endl;

  cout << "|-----------------------------|" << endl << endl; 
}

//** save() | @def:
bool account::save() {
  if (saveProfile() && saveKeychain())
    return true;

  return false;
}

//** load() | @def: loads the target account
bool account::load(const string &target) {
  //! @def: no target specified
  if (target == _none) {
    cerr << "<error>: no target specified" << endl;
    return false;
  }

  //? @def: target found, load info
  else if (search_profile(target)) {
    set_owner(target);
    loadProfile(target);
    loadKeychain(target);
    return true;
  }

  return false;
}

//** wipe() | @def: wipes the target account
bool account::wipe(const string &target) {

  //? @def: search for 'target'
  if (target != _none && (search_profile(target))) {
    delete_profile(target);
    delete_keychain(target);
    return true;
  }

  //? @def: no 'target' specified, search for currently loaded username
  else if (target == _none && search_profile(get_username())) {
    delete_profile(get_username());
    delete_keychain(get_username());
    return true;
  }

  //! @def: target profile not found
  else {
    cerr << "<error>: target profile not found" << endl;
    return false;
  }

  return false;
}

//** keyadd() | @def: prompts user for new key info
bool account::keyadd() {
  key nKey;

  //? @def: input prompt
  cin >> nKey;

  //? @def: return true if key added
  if (newKey(nKey))
    return true;

  //! @def: failed adding key
  else {
    cerr << "<error>: failed adding key" << endl;
    return false;
  }

  return false;
}

//** keyremove() | @def: deletes the target key
bool account::keyremove(const string &target) {

  //! @def: no searchkey input
  if (target == _none) {
    cerr << "<error>: no searchkey input" << endl;
    return false;
  }

  //? @def: target was found
  else if (searchKey(target)) {
    delete_key(target);
    return true;
  }

  return false;
}

//** keyinfo() | @def: displays the target key
bool account::keyinfo(const string &target) {

  //! @def: no searchkey input
  if (target == _none) {
    cerr << "<error>: no searchkey input" << endl;
    return false;
  }

  //? @def: target was found
  else if (searchKey(target)) {
    printKey(target);
    return true;
  }

  return false;
}
