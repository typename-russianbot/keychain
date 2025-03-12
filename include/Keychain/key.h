// TODO: class=<key>
#pragma once
#include "../master.h"
class key
{
private:                   //!! -Attributes-
  string cKeyname;         //* cKeyname      | what the key unlocks (accounts, servers, etc.)
  string cUsername;        //* cUsername     | username for any given key
  string cEmail;           //* cEmail        | email for any given key
  string cPassword;        //* cPassword     | password for any given key
  integrity cKeyintegrity; //* cKeyintegrity | password integrity for the current stored password

public: //!! -Functions-
  key(string keyname = "none", string username = _none, string email = _none,
      string password = _none, integrity integrity = none); //^^ -constructor
  ~key();                                                   //^^ -destructor

  //^^ -set
  void setKeyname(const string &nKeyname);           //& setKeyname
  void setUsername(const string &nUsername);         //& setUsername
  void setEmail(const string &nEmail);               //& setEmail
  void setPassword(const string &nPassword);         //& setPassword
  void setKeyintegrity(const integrity &nIntegrity); //& setKeyintegrity

  //^^ -get
  const string getKeyname(void);         //& getKeyname
  const string getUsername(void);        //& getUsername
  const string getEmail(void);           //& getEmail
  const string getPassword(void);        //& getPassword
  const integrity getKeyintegrity(void); //& getKeyintegrity

  //^ -overloads
  friend istream &operator>>(istream &input, key &object);        //& operator>>
  friend ostream &operator<<(ostream &output, const key &object); //& operator<<
  key &operator=(const key &object);                              //& operator=
};