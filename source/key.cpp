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

//^^ -constructor
key::key(string destination, string username, string email, string password,
         strength integrity, int access)
    : cDestination(destination), cUsername(username), cEmail(email),
      cPassword(password), cIntegrity(integrity), cAccess(access) {}

//^^ -set
void key::setDest(const string &nDestination) {
  this->cDestination = nDestination;
}
void key::setEmail(const string &nEmail) { this->cEmail = nEmail; }
void key::setUsername(const string &nUsername) {
  this->cUsername = nUsername;
}
void key::setPassword(const string &nPassword) {
  this->cPassword = nPassword;
}
void key::setIntegrity(const strength &nIntegrity) {
  this->cIntegrity = nIntegrity;
}

//^^ -get
const string key::getDest(void) { return this->cDestination; }
const string key::getUsername(void) { return this->cUsername; }
const string key::getEmail(void) { return this->cEmail; }
const string key::getPassword(void) { return this->cPassword; }
const strength key::getIntegrity(void) { return this->cIntegrity; }

//^^ -key_functions
bool key::is_null(void) {
  if (this->cDestination == _null && this->cUsername == _null &&
      this->cEmail == _null && this->cPassword == _null &&
      this->cIntegrity == empty && this->cAccess == 0)
    return true;

  return false;
}

//^^ -overloads
ostream &operator<<(ostream &output, const key &object) {
  output << "<" << object.cDestination << " Key>" << endl
         << "\t- Username:\t" << object.cUsername << endl
         << "\t-    Email:\t" << object.cEmail << endl
         << "\t- Password:\t" << object.cPassword << endl
         << "\t- Strength:\t" << object.cIntegrity << endl;

  return output;
}
key &key::operator=(const key &object) {
  this->cDestination = object.cDestination;
  this->cUsername = object.cUsername;
  this->cEmail = object.cEmail;
  this->cPassword = object.cPassword;
  this->cAccess = object.cAccess;
  return *this;
}

//^^ -destructor
key::~key() {
  if (debugger == _on)
    cout << "<" << this->cDestination << " key>: destroyed" << endl;
}
