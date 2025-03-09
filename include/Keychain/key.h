// TODO: class=<key>
#pragma once
#include "../master.h"
class key {
private: //!! -Attributes-
  string keyDestination;
  string keyUsername;
  string keyEmail;
  string keyPassword;
  strength keyIntegrity;
  unsigned int keyAccess;

public: //!! -Functions-
  //^^ -constructor
  key(string destination = _null, string username = _null, string email = _null,
      string password = _null, strength integrity = empty, int access = 0);

  //^^ -set
  void set_keyDestination(const string &nDestination);
  void set_mUsername(const string &nUsername);
  void set_mEmail(const string &nEmail);
  void set_mPassword(const string &nPassword);
  void set_mIntegrity(const strength &nIntegrity);

  //^^ -get
  const string get_keyDestination(void);
  const string get_keyUsername(void);
  const string get_keyEmail(void);
  const string get_keyPassword(void);
  const strength get_keyIntegrity(void);

  //^^ -class_functions
  bool is_null(void);

  //^ -overloads
  key &operator=(const key &object);
  friend ostream &operator<<(ostream &output, const key &object);

  //^^ -destructor
  ~key();
};