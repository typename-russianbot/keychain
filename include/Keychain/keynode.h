// TODO: class=<keynode>
#pragma once
#include "key.h"
class keynode
{
private:          //!! -Attributes-
  key cKey;       //* -cKey   | key data for current key in chain
  keynode *cNext; //* -cNext  | next key in the chain
  keynode *cPrev; //* -cPrev  | previous key in the chain

public:                     //!! -Functions-
  keynode(const key &nKey); //^^ -constructor
  ~keynode(void);           //^^ -destructor

  //^^ -get
  key getKey(void);       //& -getKey
  keynode *getNext(void); //& -getNext
  keynode *getPrev(void); //& -getPrev

  //^^ -set
  void setKey(const key &nKey);   //& -setKey
  void setStart(keynode *nStart); //& -setStart
  void setNext(keynode *nNode);   //& -setNext
  void setPrev(keynode *nNode);   //& -setPrev

  //^^ -overloads
  friend ostream &operator<<(ostream &out, const keynode *object); //& operator<<
};