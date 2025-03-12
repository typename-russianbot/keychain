// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:                //!! -Attributes-
  unsigned int cKeys;   //*  -cKeys
  clearance cKeyaccess; //*  -cKeyaccess
  keynode *cHead;       //*  -cHead
  keynode *cTail;       //*  -cTail

public:        //!! -Functions-
  keychain();  //^^ -construct
  ~keychain(); //^^ -destruct

  //^^ -<keychain>_functions
  bool isEmpty();            //& -isEmpty
  void add(const key &nKey); //& -add
  void remove();             //& -remove
  void lookup();             //& -lookup

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keychain &object); //& -operator<<
  keychain operator=(const keychain &object);                       //& -operator=
};
