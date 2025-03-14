#pragma once
#include "key.h"

//? -[CLASS: Keynode]- ?
class keynode
{
  //! -[PRIVATE]- !
private:
  key cKey;       //! cKey
  keynode *cNext; //! cNext
  keynode *cPrev; //! cPrev

  //* -[PUBLIC]- *
public:
  //* -constructor-
  keynode(const key &nKey);

  //* -destructor-
  ~keynode(void);

  //* -getters-
  key getKey(void);
  keynode *getNext(void);
  keynode *getPrev(void);

  //* -setters-
  void setKey(const key &nKey);
  void setStart(keynode *nStart);
  void setNext(keynode *nNode);
  void setPrev(keynode *nNode);

  //* -overloads-
  friend ostream &operator<<(ostream &out, const keynode *keynode); //* operator<<
};