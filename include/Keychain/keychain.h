// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:              //!! -Attributes-
  unsigned int cKeys; //*  -cKeys     | numbers of keys found on chain
  string cPasskey;    //*  -cPasskey  | passkey for keychain, same profile passkey
  clearance cAccess;  //*  -cAccess   | keychain permissions
  keynode *cHead;     //*  -cHead     | head of keychain
  keynode *cTail;     //*  -cTail     | tail of keychain

protected:               //!! -Protected Functions-
  string inputPasskey(); //& inputPasskey()

public:                             //!! -Private Functions-
  keychain(string passkey = _none); //^^ -constructor
  ~keychain();                      //^^ -destructor

  //^^ -<keychain> Functions-
  bool isEmpty();                             //& isEmpty()
  bool isRestricted();                        //& isRestricted()
  bool requestAccess(string passkey = _none); //& requestAccess()
  bool setPassword(string passkey = _none);   //& setPassword()
  void add(const key &nKey);                  //& add()
  bool remove(string keyident = _none);       //& remove()
  bool lookup(string keyident = _none);       //& lookup()

  //^^ -Overloads-
  friend ostream &operator<<(ostream &out, const keychain &object); //& -operator<<
  keychain operator=(const keychain &object);                       //& -operator=
};
