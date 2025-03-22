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
  string cSaveFile;   //! cSaveFile || if cSaveFile = _none, don't do certain operations

  //^ -[PROTECTED]- ^
protected:
  //^ <SETTERS>
  bool setSaveFile(const string &username); //^ setSaveFile()

  //^ <GETTERS>
  const unsigned int getKeys();                     //^ getKeys()
  const key getKey(const string &keyident = _none); //^ getKey()
  const string getSaveFile();                       //^ getSaveFile()

  //^ <HELPERS>
  bool keyNew(const key &nKey);                    //^ 1. keyNew()
  bool keyDelete(const string &keyident);          //^ 2. keyDelete()
  bool keySearch(const string &keyident);          //^ 3. keySearch()
  bool keychainLoad();                             //^ 5. keychainLoad()
  bool keychainSave();                             //^ 6. keychainSave()
  bool savefileDelete(const string &file = _none); //^ 7. savefileDelete()
  bool isEmpty();                                  //^ 8. isEmpty()

  //* -[PUBLIC]- *
public:
  //* <RESOURCE MANAGERS *//
  keychain(const string &username = _none);
  ~keychain();

  //* <FUNCTIONS> *//
  bool newKey(const key &nKey);                   //* 1. newKey()
  bool deleteKey(const string &keyident = _none); //* 2. deleteKey()
  bool searchKey(const string &keyident = _none); //* 3. searchKey()
  bool printKey(const string &keyident);          //* 4. printKey()
  void printKeychain();                           //* 5. printKeychain()

  bool loadKeychain();   //* 6. loadKeychain() | @note: implementation required
  bool saveKeychain();   //* 7. saveKeychain() 
  bool deleteKeychain(); //* 8. deleteKeychain() | @note: implementation required

  //* <OVERLOADS> *//
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
};
