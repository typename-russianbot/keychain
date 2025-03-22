//? | @author: Matthew H. | @github: typename-russianbot | ?

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
  //* <RESOURCE MANAGERS>
  keynode(const key &nKey);
  ~keynode(void);

  //* <SETTERS>
  void setKey(const key &nKey);
  void setNext(keynode *nNode);
  void setPrev(keynode *nNode);
  
  //* <GETTERS>
  key getKey(void);
  keynode *getNext(void);
  keynode *getPrev(void);

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keynode *keynode); //* operator<<
};