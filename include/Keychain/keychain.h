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
  bool keyNew(const key &nKey);           //^ 1. keyNew()
  bool keyDelete(const string &keyident); //^ 2. keyDelete()
  bool keySearch(const string &keyident); //^ 3. keySearch()
  bool keychainLoad();                    //^ 5. keychainLoad()
  bool keychainSave();                    //^ 6. keychainSave()
  bool savefileDelete();                  //^ 7. savefileDelete()
  bool isEmpty();                         //^ 8. isEmpty()

  //* -[PUBLIC]- *
public:
  //* <CONSTRUCTOR>
  keychain(const string &username = _none);

  //* <DESTRUCTOR>
  ~keychain();

  //* <FUNCTIONS>
  bool newKeychain(const string &owner);          //* 1. newKeychain()
  bool deleteKeychain();                          //* 2. deleteKeychain()
  bool newKey(const key &nKey);                   //* 3. newKey()
  bool deleteKey(const string &keyident = _none); //* 4. deleteKey()
  bool searchKey(const string &keyident = _none); //* 5. searchKey()
  bool printKey(const string &keyident);          //* 6. printKey()
  void printKeychain();                           //* 7. printKeychain()
  bool loadKeychain();                            //* 8. loadKeychain() @note: needs implementing
  bool saveKeychain();                            //* 9. saveKeychain() @note: needs implementation

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
};
