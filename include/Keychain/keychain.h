//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once
#include "keynode.h"

//? -[CLASS: Keychain]- ?
class keychain
{
  //! -[PRIVATE]- !
private:
  unsigned int cKeys; //! cKeys
  keynode *cHead;     //! cHead
  keynode *cTail;     //! cTail
  string cOwner;      //! cOwner

  //^ -[PROTECTED]- ^
protected:
  //^ <GETTERS>
  unsigned int getKeys();                     //^ getKeys()
  key getKey(const string &keyident = _none); //^ getKey()

  //^ <HELPERS>
  bool keyNew(const key &nKey);           //^ 1. keyNew()
  bool keyDelete(const string &keyident); //^ 2. keyDelete()
  bool keySearch(const string &keyident); //^ 3. keySearch()
  bool keyPrint();                        //^ 4. keyPrint()
  bool isEmpty();                         //^ 5. isEmpty()

  //* -[PUBLIC]- *
public:
  //* <CONSTRUCTOR>
  keychain(const string &password = _none);

  //* <DESTRUCTOR>
  ~keychain();

  //* <FUNCTIONS>
  bool newKeychain(const string &owner);          //* 1. newKeychain()
  bool newKey(const key &nKey);                   //* 2. newKey()
  bool deleteKey(const string &keyident = _none); //* 3. deleteKey()
  bool searchKey(const string &keyident = _none); //* 4. searchKey()
  bool printKey(const string &keyident);          //* 5. printKey()
  void printKeychain();                           //* 6. printKeychain()
  bool loadKeychain();                            //* 7. loadKeychain()
  bool saveKeychain();                            //* 8. saveKeychain()

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
};
