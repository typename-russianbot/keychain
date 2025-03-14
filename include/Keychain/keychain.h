#pragma once
#include "keynode.h"

//? -[CLASS: Keychain]- ?
class keychain
{
  //! -[PRIVATE]-
private:
  unsigned int cKeys; //! cKeys
  string cPasskey;    //! cPasskey
  clearance cAccess;  //! cAccess
  keynode *cHead;     //! cHead
  keynode *cTail;     //! cTail

  //^ -[PROTECTED]- ^
protected:
  string inputPasskey();                      //^ inputPasskey()
  bool requestAccess(string passkey = _none); //^ requestAccess()
  bool setPasskey(string passkey = _none);    //^ setPasskey()
  bool isEmpty();                             //^ isEmpty()
  bool isRestricted();                        //^ isRestricted()
  void add(const key &nKey);                  //^ add()
  bool remove(const key &nKey);               //^ remove()
  bool lookup(string keyident = _none);       //^ lookup()

  //* -[PUBLIC]- *
public:
  //* -constructor-
  keychain(string passkey = _none);

  //* -destructor-
  ~keychain();

  //* -class_functions-
  bool print(); //* print()
  //* create()
  //* delete()

  //* -overloads-
  friend ostream &operator<<(ostream &out, const keychain &object); //* operator<<
  keychain operator=(const keychain &object);                       //* operator=
};
