#include "../include/Keychain/keynode.h"

keynode::keynode(const key &nKey) {
  this->set_mData(nKey);
  this->m_Prev = this->m_Next = nullptr;
}

//?? 1. get
key keynode::get_mData(void) { return m_Data; }

keynode *keynode::get_mNext(void) { return this->m_Next; }
keynode *keynode::get_mPrev(void) { return this->m_Prev; }

//?? 2. set
void keynode::set_mData(const key &nData) { this->m_Data = nData; }
void keynode::set_mNext(keynode *&nNode) { this->m_Next = nNode; }
void keynode::set_mPrev(keynode *&nNode) { this->m_Prev = nNode; }

keynode::~keynode(void) {
  if (debugger == _on)
    cout << "deleting node" << endl;
}


