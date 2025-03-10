// TODO: class=<key>
#pragma once
#include "../master.h"
class key
{
private:                  //!! -Attributes-
  string cKeyname;        //^^ cKeyname             -- what the key unlocks (accounts, servers, etc.)
  string cUsername;       //^^ cUsername            -- username for any given key
  string cEmail;          //^^ cEmail               -- email for any given key
  string cPassword;       //^^ cPassword            -- password for any given key
  strength cKeyintegrity; //^^ cKeyintegrity        -- password integrity for the current stored password

public: //!! -Functions-
  //^^ -constructor
  key(string keyname = _null, string username = _null, string email = _null,
      string password = _null, strength integrity = empty);

  //^^ -set
  void setKeyname(const string &nKeyname);
  void setUsername(const string &nUsername);
  void setEmail(const string &nEmail);
  void setPassword(const string &nPassword);
  void setKeyintegrity(const strength &nIntegrity);

  //^^ -get
  const string getKeyname(void);
  const string getUsername(void);
  const string getEmail(void);
  const string getPassword(void);
  const strength getKeyintegrity(void);

  //^^ -class_functions
  bool is_null(void);

  //^ -overloads
  friend istream &operator>>(istream &input, key &object);        //^^ operator>>
  friend ostream &operator<<(ostream &output, const key &object); //^^ operator<<
  key &operator=(const key &object);                              //^^ operator=

  //^^ -destructor
  ~key();
};