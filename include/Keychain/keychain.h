// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain {
private:           //!! -Attributes-
  int cCounter;    //^^
  keynode *cStart; //^^
  keynode *cEnd;   //^^

public: //!! -Functions-
  //^^ -construct
  keychain();

  //^^ -class_functions
  bool is_empty();
  void add_key();
  void remove_key();

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keychain &object);

  //^^ -destruct
  ~keychain();
};
