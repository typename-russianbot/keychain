#pragma once
#include "keynode.h"

//? -[CLASS: Keychain]- ?
class keychain
{
  //! -[PRIVATE]- !
private:
  unsigned int cKeys; //! cKeys
  string cPassword;   //! cPassword
  clearance cAccess;  //! cAccess
  keynode *cHead;     //! cHead
  keynode *cTail;     //! cTail

  //^ -[PROTECTED]- ^
protected:
  //^ <HELPERS>
  string inputPassword();                                  //^ inputPasskey()
  bool isEmpty();                                          //^ isEmpty()
  bool requestPermissions(const string &password = _none); //^ accessKeychain()
  void addKey(const key &nKey);                            //^ addKey()
  bool deleteKey(const key &nKey);                         //^ removeKey()
  bool lookupKey(const string &keyident = _none);          //^ lookupKey()
  bool addPassword(const string &password = _none);        //^ addPassword()
  bool keychainAccess();                                   //^ keychainAccess()

  //* -[PUBLIC]- *
public:
  //* <CONSTRUCTOR>
  keychain(const string &password = _none);

  //* <DESTRUCTOR>
  ~keychain();

  //* <FUNCTIONS>
  bool createKey(const string &keyname = _none, const string &username = _none,
                 const string &email = _none, const string &password = _none); //* createKey()
  bool removeKey(const string &target);                                        //* removeKey()
  bool searchKey();                                                            //* searchKey()
  unsigned int getKeys();                                                      //* getKeys()
  bool printKeychain();                                                        //* printKeychain()
  bool loadKeychain();                                                         //* loadKeychain()
  bool saveKeychain();                                                         //* saveKeychain()

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
  friend istream &operator>>(istream &in, const keychain &keychain);  //* operator>>
};
