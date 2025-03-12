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

protected: //!! -Protected Functions-
  //& | inputPasskey |
  //? - returns user inputted passkey
  string inputPasskey();

public:                             //!! -Private Functions-
  keychain(string passkey = _none); //^^ -constructor
  ~keychain();                      //^^ -destructor

  //^^ -<keychain> Functions-

  //& | isEmpty() |
  //? return true if empty, otherwise false
  bool isEmpty();

  //& | isRestricted() |
  //? returns true if restricted, otherwise false
  bool isRestricted();

  //& | requestAccess() |
  //? returns true if access is permitted, false if denied
  bool requestAccess(string passkey = _none);

  //& | setPassword() |
  //? - sets cPasskey to the passed string parameter
  bool setPassword(string passkey = _none);

  //& | add() |
  //? - adds a new key to the chain
  void add(const key &nKey);

  //& | remove() |
  //? - removes a specified key from the chain
  bool remove(string keyident = _none);

  //& | lookup() |
  //? - searches for a specific key on the chain & displays
  bool lookup(string keyident = _none);

  //^^ -Overloads-
  friend ostream &operator<<(ostream &out, const keychain &object); //& -operator<<
  keychain operator=(const keychain &object);                       //& -operator=
};
