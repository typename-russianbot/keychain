// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:              //!! -Attributes-
  unsigned int cKeys; //^^ 
  keynode *cStart;    //^^
  keynode *cEnd;      //^^

public: //!! -Functions-
  //^^ -construct
  keychain();

  //^^ -destruct
  ~keychain();

  //^^ -class_functions
  bool is_empty();
  keynode* add_key();
  void remove_key();

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keychain &object);
};
