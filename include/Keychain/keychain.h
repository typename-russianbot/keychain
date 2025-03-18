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

  //^ -[PROTECTED]- ^
protected:
  //^ <GETTERS>
  unsigned int getKeys(); //^ getKeys()

  //^ <HELPERS>
  void keyNew(const key &nKey);                   //^ 1. keyNew()
  bool keyDelete(const key &nKey);                //^ 2. keyDelete()
  bool keySearch(const string &keyident = _none); //^ 3. keySearch()
  bool keyPrint();                                //^ 4. keyPrint()
  bool isEmpty();                                 //^ 5. isEmpty()

  //* -[PUBLIC]- *
public:
  //* <CONSTRUCTOR>
  keychain(const string &password = _none);

  //* <DESTRUCTOR>
  ~keychain();

  //* <FUNCTIONS>
  bool newKey(const string &keyname = _none, const string &username = _none,
              const string &email = _none, const string &password = _none); //* 1. newKey()
  bool deleteKey(const string &target);                                     //* 2. deleteKey()
  bool searchKey();                                                         //* 3. searchKey()
  bool printKey();                                                          //* 4. printKey()
  void printKeychain();                                                     //* 5. printKeychain()
  bool loadKeychain();                                                      //* 6. loadKeychain()
  bool saveKeychain();                                                      //* 7. saveKeychain()

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
};
