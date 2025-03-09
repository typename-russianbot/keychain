#pragma once
#include "keynode.h"

//^ <class: keychain>
class keychain {
private:            //^ -- MEMBERS --
  int m_KeyCounter; //* # of keys in the keychain
  keynode *m_Start; //* start of keychain
  keynode *m_End;   //* end of keychain

public: //^ -- OPERATIONS --
  //* - CONSTRUCTOR -
  keychain() : m_KeyCounter(0), m_Start(nullptr), m_End(nullptr) {}

  //* - FUNCTIONS -
  //? 1. display()
  //? 2. is_empty()
  //? 3.

  //* - DESTRUCTOR -
};
