// TODO: class=<key>
#pragma once
#include "../master.h"
class key {
private: //!! -Attributes-
  string cDestination;
  string cUsername;
  string cEmail;
  string cPassword;
  strength cIntegrity;
  unsigned int cAccess;

public: //!! -Functions-
  //^^ -constructor
  key(string destination = _null, string username = _null, string email = _null,
      string password = _null, strength integrity = empty, int access = 0);

  //^^ -set
  void setDest(const string &nDestination);
  void setUsername(const string &nUsername);
  void setEmail(const string &nEmail);
  void setPassword(const string &nPassword);
  void setIntegrity(const strength &nIntegrity);
  void setAccess(const int &nAccess);

  //^^ -get
  const string getDest(void);
  const string getUsername(void);
  const string getEmail(void);
  const string getPassword(void);
  const strength getIntegrity(void);
  const int getAccess(void);

  //^^ -class_functions
  bool is_null(void);

  //^ -overloads
  friend ostream &operator<<(ostream &output, const key &object);
  key &operator=(const key &object);

  //^^ -destructor
  ~key();
};