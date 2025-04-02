#include "../include/Keychain/key.h"

//* <RESOURCE MANAGERS>
key::key(string destination, string username, string email, string password,
         integrity integrity)
    : cKeyname(destination), cUsername(username), cEmail(email),
      cPassword(password), cKeyintegrity(integrity) {}
key::~key() {
  if (_debugger == _on)
    cout << "<" << this->cKeyname << " key>: destroyed" << endl;
}

//* <SETTERS>
void key::setKeyname(const string &nKeyname) { this->cKeyname = nKeyname; }
void key::setEmail(const string &nEmail) { this->cEmail = nEmail; }
void key::setUsername(const string &nUsername) { this->cUsername = nUsername; }
void key::setPassword(const string &nPassword) { this->cPassword = nPassword; }
void key::setKeyintegrity(const integrity &nIntegrity) {
  this->cKeyintegrity = nIntegrity;
}

//* <GETTERS>
const string key::getKeyname(void) { return this->cKeyname; }
const string key::getUsername(void) { return this->cUsername; }
const string key::getEmail(void) { return this->cEmail; }
const string key::getPassword(void) { return this->cPassword; }
const integrity key::getKeyintegrity(void) { return this->cKeyintegrity; }

//* <OVERLOADS>
istream &operator>>(istream &in, key &key) {
  char retry;
  string verification, password;

  //* @note: grab keyname
  do {
    cout << "Keyname: ";
    in >> key.cKeyname;
  } while (!ValidateInput(key.cKeyname));

  //* @note: grab username
  do {
    cout << "Username: ";
    in >> key.cUsername;
  } while (!ValidateInput(key.cUsername));

  //* @note: grab email
  do {
    cout << "Email: ";
    in >> key.cEmail;
  } while (!ValidateInput(key.cEmail));

  //* @note: grab password (same method as setPassword in profile)

  HideTerminal();

  while (retry != 'n') {
    do {
      cout << "Password: ";
      in >> password;
    } while (!ValidateInput(password));

    cout << endl;

    do {
      cout << "Re-enter Password: ";
      cin >> verification;
    } while (!ValidateInput(verification));

    if (password == verification) {
      ShowTerminal();
      key.cPassword = password;

      cout << key << endl;
      return in;
    }

    else {
      do {
        cout << "<ERROR>: Password Mismatch Detected" << endl
             << "Re-attempt? [y/n]: ";

        cin >> retry;
        cout << endl;
      } while (!ValidateInput(retry));
    }
  }

  ShowTerminal();
  cout << key << endl;

  return in;
}
ostream &operator<<(ostream &output, const key &object) {
  output << "<" << object.cKeyname << ">" << endl
         << "\t-    Email:\t" << object.cEmail << endl
         << "\t- Username:\t" << object.cUsername << endl
         << "\t- Password:\t" << object.cPassword << endl
         << "\t- Strength:\t" << object.cKeyintegrity << endl;

  return output;
}
key &key::operator=(const key &object) {
  this->cKeyname = object.cKeyname;
  this->cUsername = object.cUsername;
  this->cEmail = object.cEmail;
  this->cPassword = object.cPassword;
  return *this;
}
