#pragma once
#include "../master.h"

//^  1. CLASS -- key
class key {
private:                 //^ -- MEMBERS --
  string keyDestination; //? 1. key_destination -- unlock destination for key
  string keyUsername;    //? 2. key_username -- username for this key
  string keyEmail;       //? 3. key_email -- email for this key
  string keyPassword;    //? 4. key_password -- password for this key
  strength keyIntegrity; //? 5. key_integrity -- strength of this key's password
  unsigned int
      keyAccess; //? 6. key_accessed -- number of times this key has been

public: //^ -- OPERATIONS --
  //* - CONSTRUCTOR -
  key(string destination = _null, string username = _null, string email = _null,
      string password = _null, strength integrity = empty, int access = 0)
      : keyDestination(destination), keyUsername(username), keyEmail(email),
        keyPassword(password), keyIntegrity(integrity), keyAccess(access) {}

  //* - FUNCTIONS -
  //? -- 1. setters
  void set_keyDestination(const string &nDestination) {
    this->keyDestination = nDestination;
  }
  void set_mUsername(const string &nUsername) { this->keyUsername = nUsername; }
  void set_mEmail(const string &nEmail) { this->keyEmail = nEmail; }
  void set_mPassword(const string &nPassword) { this->keyPassword = nPassword; }
  void set_mIntegrity(const strength &nIntegrity) {
    this->keyIntegrity = nIntegrity;
  }
  //? -- 2. getters
  const string get_keyDestination(void) { return this->keyDestination; }
  const string get_keyUsername(void) { return this->keyUsername; }
  const string get_keyEmail(void) { return this->keyEmail; }
  const string get_keyPassword(void) { return this->keyPassword; }
  const strength get_keyIntegrity(void) { return this->keyIntegrity; }
  //? -- 3. is_null (empty)
  bool is_null(void) {
    //*
    if (this->keyDestination == _null && this->keyUsername == _null &&
        this->keyEmail == _null && this->keyPassword == _null &&
        this->keyIntegrity == empty && this->keyAccess == 0)
      return true;

    //*
    return false;
  }

  //? -- 4. operator= (hard copy)
  key &operator=(const key &object) {
    this->keyDestination = object.keyDestination;
    this->keyUsername = object.keyUsername;
    this->keyEmail = object.keyEmail;
    this->keyPassword = object.keyPassword;
    this->keyAccess = object.keyAccess;
    return *this;
  }

  //? -- 5. operator<< (console out)
  friend ostream &operator<<(ostream &output, const key &object) {
    output << "<" << object.keyDestination << " Key>" << endl
           << "\t- Username:\t" << object.keyUsername << endl
           << "\t-    Email:\t" << object.keyEmail << endl
           << "\t- Password:\t" << object.keyPassword << endl
           << "\t- Strength:\t" << object.keyIntegrity << endl;

    return output;
  }

  //* - DESTRUCTOR -
  ~key() {
    if (debugger == _on)
      cout << "<" << this->keyDestination << " key>: destroyed" << endl;
  }
};