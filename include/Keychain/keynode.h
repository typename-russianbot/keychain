// TODO: class=<keynode>
#pragma once
#include "key.h"
class keynode {
  //!! -Attributes-
private:
  key m_Data;      //^^ 1. mData -- key data for current key in chain
  keynode *m_Next; //^^ 2. mNext -- next key in the chain
  keynode *m_Prev; //^^ 3. mPrev -- previous key in the chain

  //!! -Functions-
public:
  //^^ -constructor
  keynode(const key &nKey);

  //^^ -get
  key get_mData(void);
  keynode *get_mNext(void);
  keynode *get_mPrev(void);

  //^^ -set
  void set_mData(const key &nData);
  void set_mNext(keynode *&nNode);
  void set_mPrev(keynode *&nNode);

  //^^ -destructor
  ~keynode(void);
};