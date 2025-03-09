#pragma once
#include "key.h"

//^  2. CLASS -- keynode
class keynode {
private:           //^ -- MEMBERS --
  key m_Data;      //? 1. mData -- key data for current key in chain
  keynode *m_Next; //? 2. mNext -- next key in the chain
  keynode *m_Prev; //? 3. mPrev -- previous key in the chain

public: //^ -- OPERATIONS --
  //* - CONSTRUCTOR -
  keynode(const key &nKey) {
    this->set_mData(nKey);
    this->m_Prev = this->m_Next = nullptr;
  }

  //* - FUNCTIONS -
  //? -- 1. getters
  key get_mData(void) { return m_Data; }
  keynode *get_mNext(void) { return this->m_Next; }
  keynode *get_mPrev(void) { return this->m_Prev; }

  //? -- 2. setters
  void set_mData(const key &nData) { this->m_Data = nData; }
  void set_mNext(keynode *&nNode) { this->m_Next = nNode; }
  void set_mPrev(keynode *&nNode) { this->m_Prev = nNode; }

  //* - DESTRUCTOR -
  ~keynode(void) {
    if (debugger == _on)
      cout << "deleting node" << endl;
  }
};