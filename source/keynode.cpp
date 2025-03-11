#include "../include/Keychain/keynode.h"

//^^ constructor
keynode::keynode(key &nKey)
{
  this->cKey = nKey; 
  this->cPrev = this->cNext = nullptr; 
}

//^^ -destructor
keynode::~keynode(void) 
{
  if (_debugger == _on)
    cout << "deleting node" << endl;
}

//^^ -get
key keynode::getKey(void) { return cKey; }
keynode *keynode::getNext(void) { return this->cNext; }
keynode *keynode::getPrev(void) { return this->cPrev; }

//^^ -set
void keynode::setKey(key &nData) { this->cKey = nData; }
void keynode::setNext(keynode *nNode) { this->cNext = nNode; }
void keynode::setPrev(keynode *nNode) { this->cPrev = nNode; }