// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:              //!! -Attributes-
  unsigned int cKeys; //*  -cKeys     | numbers of keys found on chain
  clearance cAccess;  //*  -cAccess   | keychain permissions
  keynode *cHead;     //*  -cHead     | head of keychain
  keynode *cTail;     //*  -cTail     | tail of keychain

public:        //!! -Functions-
  keychain();  //^^ -construct
  ~keychain(); //^^ -destruct

  //^^ -<keychain>_functions
  bool isEmpty();            //& -isEmpty         | returns true if empty
  bool isRestricted();       //& -isRestricted    | returns true if restricted
  bool requestAccess();      //& -requestAccess   | returns true if access is permitted
  void add(const key &nKey); //& -add             | adds a new key to the chain
  void remove();             //& -remove          | removes a specified key from the chain
  void lookup();             //& -lookup          | searches for a specific key on the chain

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keychain &object); //& -operator<<
  keychain operator=(const keychain &object);                       //& -operator=
};
