// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:              //!! -Attributes-
  unsigned int cKeys; //^^  -cKeys
  keynode *cHead;     //^^  -cHead
  keynode *cTail;     //^^  -cTail

  void getHead();

public: //!! -Functions-
  //^^ -construct
  keychain();

  //^^ -destruct
  ~keychain();

  //^^ -<keychain>_functions

  bool is_empty();           //^ -is_empty || returns true is 
  void add(const key &nKey); //^ -add
  void remove();             //^ -remove 

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keychain &object);
};
