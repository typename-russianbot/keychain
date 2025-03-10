#include "../include/Keychain/keynode.h"


keynode::keynode(void) //?
{

}

keynode::~keynode(void) //* 2. destructor
{
  if (debugger == _on)
    cout << "deleting node" << endl;
}

//^^ | -keynode functions- |
key *keynode::getKey(void) { return &cKey; }
keynode *keynode::getNext(void) { return this->cNext; }
keynode *keynode::getPrev(void) { return this->cPrev; }

//^^
void keynode::setKey(key* nData) { this->cKey = * nData; }
void keynode::setNext(keynode *nNode) { this->cNext = nNode; }
void keynode::setPrev(keynode *nNode) { this->cPrev = nNode; }
