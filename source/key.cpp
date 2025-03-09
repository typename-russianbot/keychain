#include "../include/Keychain/key.h"

//& |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object) {
  switch (object) {
  default:
    output << "{null}";
    break;
  case 1:
    output << "poor";
    break;
  case 2:
    output << "weak";
    break;
  case 3:
    output << "strong";
    break;
  case 4:
    output << "excellent";
    break;
  }

  return output;
}

//& |--- GLOBAL VARIABLES ---|
//^  1. BOOL -- debugger
bool debugger = _off;

key::key(string destination, string username, string email, string password,
         strength integrity, int access)
    : keyDestination(destination), keyUsername(username), keyEmail(email),
      keyPassword(password), keyIntegrity(integrity), keyAccess(access) {}

//?? 2. setters:
void key::set_keyDestination(const string &nDestination) {
  this->keyDestination = nDestination;
}
void key::set_mEmail(const string &nEmail) { this->keyEmail = nEmail; }
void key::set_mUsername(const string &nUsername) {
  this->keyUsername = nUsername;
}
void key::set_mPassword(const string &nPassword) {
  this->keyPassword = nPassword;
}
void key::set_mIntegrity(const strength &nIntegrity) {
  this->keyIntegrity = nIntegrity;
}

//?? getters:
const string key::get_keyDestination(void) { return this->keyDestination; }
const string key::get_keyUsername(void) { return this->keyUsername; }
const string key::get_keyEmail(void) { return this->keyEmail; }
const string key::get_keyPassword(void) { return this->keyPassword; }
const strength key::get_keyIntegrity(void) { return this->keyIntegrity; }

//? key functions:
ostream &operator<<(ostream &output, const key &object) {
  output << "<" << object.keyDestination << " Key>" << endl
         << "\t- Username:\t" << object.keyUsername << endl
         << "\t-    Email:\t" << object.keyEmail << endl
         << "\t- Password:\t" << object.keyPassword << endl
         << "\t- Strength:\t" << object.keyIntegrity << endl;

  return output;
}
bool key::is_null(void) {
  if (this->keyDestination == _null && this->keyUsername == _null &&
      this->keyEmail == _null && this->keyPassword == _null &&
      this->keyIntegrity == empty && this->keyAccess == 0)
    return true;

  return false;
}
key &key::operator=(const key &object) {
  this->keyDestination = object.keyDestination;
  this->keyUsername = object.keyUsername;
  this->keyEmail = object.keyEmail;
  this->keyPassword = object.keyPassword;
  this->keyAccess = object.keyAccess;
  return *this;
}
key::~key() {
  if (debugger == _on)
    cout << "<" << this->keyDestination << " key>: destroyed" << endl;
}
