//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "../master.h"

//? -[CLASS: Key]- ?
class key
{
  //! -[PRIVATE]- !
private:
  string cKeyname;         //! cKeyname
  string cUsername;        //! cUsername
  string cEmail;           //! cEmail
  string cPassword;        //! cPassword
  integrity cKeyintegrity; //! cKeyintegrity

  //^ -[PROTECTED]- ^
protected:
  void inputKeyname(istream &in, key &object);  //^ inputKeyname()
  void inputUsername(istream &in, key &object); //^ inputUsername()
  void inputEmail(istream &in, key &object);    //^ inputEmail()
  void inputPassword(istream &in, key &object); //^ inputPassword()

  //* -[PUBLIC]- *
public:
  //* -constructor-
  key(string keyname = "none", string username = _none, string email = _none,
      string password = _none, integrity integrity = none);

  //* -destructor-
  ~key();

  //* -setters-
  void setKeyname(const string &nKeyname);           //* setKeyname
  void setUsername(const string &nUsername);         //* setUsername
  void setEmail(const string &nEmail);               //* setEmail
  void setPassword(const string &nPassword);         //* setPassword
  void setKeyintegrity(const integrity &nIntegrity); //* setKeyintegrity

  //* -getters-
  const string getKeyname(void);         //* getKeyname
  const string getUsername(void);        //* getUsername
  const string getEmail(void);           //* getEmail
  const string getPassword(void);        //* getPassword
  const integrity getKeyintegrity(void); //* getKeyintegrity

  //* -overloads-
  friend istream &operator>>(istream &in, key &object);           //* operator>>
  friend ostream &operator<<(ostream &output, const key &object); //* operator<<
  key &operator=(const key &object);                              //* operator=
};