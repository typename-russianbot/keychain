#include "../include/Keychain/keynode.h"

//* <RESOURCE MANAGERS> *//
keynode::keynode(const key &nKey) : cKey(nKey), cPrev(nullptr), cNext(nullptr)
{
}
keynode::~keynode(void)
{
  if (_debugger == _on)
    cout << "deleting node" << endl;
}

//* <SETTERS> *//
void keynode::setKey(const key &nKey) { this->cKey = nKey; }
void keynode::setNext(keynode *nNode) { this->cNext = nNode; }
void keynode::setPrev(keynode *nNode) { this->cPrev = nNode; }

//* <GETTERS> *//
key keynode::getKey(void) { return cKey; }
keynode *keynode::getNext(void) { return this->cNext; }
keynode *keynode::getPrev(void) { return this->cPrev; }

//* <OVERLOADS> *//
ostream &operator<<(ostream &out, const keynode *keynode)
{
  out << "\t" << keynode->cKey << endl
      << "\tPrevious Key:\t" << keynode->cPrev << endl
      << "\tNext Key:    \t" << keynode->cNext << endl;

  return out;
}