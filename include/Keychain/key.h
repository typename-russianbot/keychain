//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../master.h"

class key
{
  //! -[PRIVATE]- !
private:
  string cKeyname;         //! cKeyname
  string cUsername;        //! cUsername
  string cEmail;           //! cEmail
  string cPassword;        //! cPassword
  integrity cKeyintegrity; //! cKeyintegrity

  //* -[PUBLIC]- *
public:
  //* <RESOURCE MANAGERS> *//
  key(string keyname = _none, string username = _none, string email = _none, string password = _none, integrity integrity = none);
  ~key();

  //* <SETTERS> *//
  void setKeyname(const string &nKeyname);
  void setUsername(const string &nUsername);
  void setEmail(const string &nEmail);
  void setPassword(const string &nPassword);
  void setKeyintegrity(const integrity &nIntegrity);

  //* <GETTERS> *//
  const string getKeyname(void);
  const string getUsername(void);
  const string getEmail(void);
  const string getPassword(void);
  const integrity getKeyintegrity(void);

  //* <OVERLOADS> *//
  friend istream &operator>>(istream &in, key &object);           //* operator>>
  friend ostream &operator<<(ostream &output, const key &object); //* operator<<
  key &operator=(const key &object);                              //* operator=
};