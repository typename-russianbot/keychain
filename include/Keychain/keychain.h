//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "keynode.h"

//? -[CLASS: Keychain]- ?
class keychain {
  //! -[PRIVATE]- !
private:
  string cOwner;      //! cUsername | @def: owner of keychain
  keynode *cHead;     //! cHead     | @def: start of keychain
  keynode *cTail;     //! cTail     | @def: end of keychain
  unsigned int cKeys; //! cKeys     | @def: # of keys on this chain

  //^ -[PROTECTED]- ^//
protected:
  //^ <GETTERS>
  const unsigned int getKeys();                     //^ getKeys()
  const key getKey(const string &keyident = _none); //^ getKey()
  const string getOwner();                          //^ getUsername()

  //^ <SETTERS>
  void setOwner(const string &owner);

  //^ <HELPERS>
  bool new_key(const key &nKey);           //^ new_key()
  bool delete_key(const string &keyident); //^ delete_key()
  bool search_key(const string &keyident); //^ search_key()
  bool is_empty();                         //^ is_empty()

  bool load_keychain(const string &target);   //^ load_keychain()
  bool save_keychain();                       //^ save_keychain()
  bool delete_keychain(const string &target); //^ delete_keychain()

  //* -[PUBLIC]- *//
public:
  //* <RESOURCE MANAGERS> *//
  keychain(const string &owner = _none); //* keychain()
  ~keychain();                           //* ~keychain()

  //* <FUNCTIONS> *//
  bool newKey(const key &nKey);                   //* newKey()
  bool deleteKey(const string &keyident = _none); //* deleteKey()
  bool searchKey(const string &keyident = _none); //* searchKey()
  bool printKey(const string &keyident);          //* printKey()

  void printKeychain(); //* printKeychain()
  bool
  loadKeychain(const string &target =
                   _none); //* loadKeychain() | @note: implementation required
  bool saveKeychain();     //* saveKeychain()
  bool deleteKeychain(const string &target = _none); //* deleteKeychain()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const keychain &keychain); //* operator<<
};
