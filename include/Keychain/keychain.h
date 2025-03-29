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
  //^ <MUTATORS>
  const unsigned int get_keys();           //^ get_keys()
  const key get_key(const string &target); //^ get_key()
  const string get_owner();                //^ get_owner
  void set_owner(const string &target);    //^ set_owner()

  //^ <HELPERS>
  bool new_key(const key &nKey);         //^ new_key()
  bool delete_key(const string &target); //^ delete_key()
  bool search_key(const string &target); //^ search_key()
  bool is_empty();                       //^ is_empty()

  bool save_keychain();                       //^ save_keychain()
  bool load_keychain(const string &target);   //^ load_keychain()
  bool delete_keychain(const string &target); //^ delete_keychain()

  //* -[PUBLIC]- *//
public:
  //* <RESOURCE MANAGERS> *//
  keychain(const string &owner = _none); //* keychain()
  ~keychain();                           //* ~keychain()

  //* <FUNCTIONS> *//
  bool newKey(const key &nKey);                 //* newKey()
  bool deleteKey(const string &target = _none); //* deleteKey()
  bool searchKey(const string &target = _none); //* searchKey()
  bool printKey(const string &target = _none);  //* printKey()
  void printKeychain();                         //* printKeychain()

  bool saveKeychain();                               //* saveKeychain()
  bool loadKeychain(const string &target = _none);   //* loadKeychain()
  bool deleteKeychain(const string &target = _none); //* deleteKeychain()

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out,
                             const keychain &keychain); //* operator<<
};
