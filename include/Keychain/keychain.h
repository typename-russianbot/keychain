// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain {
  //!! -Attributes-
private:
  int m_KeyCounter; //^^ 
  keynode *m_Start; //^^
  keynode *m_End;   //^^

  //!! -Functions-
public:
  //^^ -constructor
  keychain();

  //^^ -class_functions
  //? 1. display()
  //? 2. is_empty()
  //? 3.

  //^^ -destructor
  ~keychain();
};
