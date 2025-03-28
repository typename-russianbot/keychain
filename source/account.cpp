#include "../include/Account/account.h"

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *//
account::account(const string &username, const string &password) {

  //* @note: set profile data
  set_username(username);
  set_password(password);

  //* @def: set keychain data
  set_owner(username);
}

//* <DESTRUCTOR> *//
account::~account() {}

//* <FUNCTIONS> *//

//** swap() */
//* @def:

bool account::swap(const string &target) {
  if (target != _none && searchProfile(target)) {
    loadProfile(target);
    return true;
  }

  return false;
}

//** info() */
//* @def: gets the current profile (cUsername, cPassword, cAccess) & keychain (#
// of keys)
//* data currently stored
void account::info() {
  cout << "|--Account Info---------------|" << endl << endl;

  cout << " - Account: " << endl; //* @note: display current account state

  this->printProfile(); //* @note: print profile data

  cout << " - Keys Found: " << get_keys()
       << endl //* @note: display the number of keys on this account
       << endl;

  cout << "|-----------------------------|" << endl;
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
//* @def:
bool account::deleteKey(const string &target) {

  if (target != _none && searchProfile(target)) {
    delete_key(target);
    return true;
  }

  return false;
}

//** printKey() */
//* @def: if the target is found in search & != to _none,
//* because the target cannot be _none
bool account::printKey(const string &target) {

  if (target != _none && searchKey(target)) {
    printKey(target);
    return true;
  }

  return false;
}