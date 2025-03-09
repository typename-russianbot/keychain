// TODO: class=<keynode>
#pragma once
#include "key.h"
class keynode {

private:          //!! -Attributes-
  key cKey;       //^^ 1. cKey -- key data for current key in chain
  keynode *cNext; //^^ 2. cNext -- next key in the chain
  keynode *cPrev; //^^ 3. cPrev -- previous key in the chain

public: //!! -Functions-
  //^^ -constructor
  keynode(key *nKey);
  keynode(void);

  //^^ -get
  key* getKey(void);
  keynode *getNext(void);
  keynode *getPrev(void);

  //^^ -set
  void setKey(key *nData);
  void setNext(keynode *nNode);
  void setPrev(keynode *nNode);

  //^^ -destructor
  ~keynode(void);
};