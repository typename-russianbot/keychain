#include "../include/Account/account.h"

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

//** info() |
void account::info() {
  cout << "|--Account Info---------------|" << endl << endl;

  cout << " - Account: " << get_clearance()
       << endl; //* @note: display current account state

  this->printProfile(); //* @note: print profile data

  cout << " - Keys Found: " << get_keys()
       << endl //* @note: display the number of keys on this account
       << endl;

  cout << "|-----------------------------|" << endl;
}

//** save()
bool account::save() {
  if (saveProfile() && saveKeychain())
    return true;

  return false;
}

//** swap()
bool account::swap(const string &target) {
  if (target != _none && search_profile(target)) {
    set_owner(target);
    loadProfile(target);
    loadKeychain(target);
    return true;
  }

  return false;
}

//** wipe()
bool account::wipe(const string &target) {
  if (target != _none && (search_profile(target))) {
    delete_profile(target);
    delete_keychain(target);
    return true;
  } else if (target == _none && search_profile(get_username())) {
    delete_profile(get_username());
    delete_keychain(get_username());
    return true;
  }

  return false;
}

//** addKey() */
//* @def: prompts the user for key data, then adds key onto the chain
bool account::addKey() {
  key newKey;
  cin >> newKey;

  system("clear");

  if (new_key(newKey)) //* @return: true if add succeeded
    return true;

  return false; //! @return: false if add failed
}

//** deleteKey() */
bool account::deleteKey(const string &target) {

  if (target != _none && searchProfile(target)) {
    delete_key(target);
    return true;
  }

  return false;
}

//** printKey() */
bool account::printKey(const string &target) {
  if (target != _none && searchKey(target)) {
    printKey(target);
    return true;
  }

  return false;
}
