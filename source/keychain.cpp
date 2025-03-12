#include "../include/Keychain/keychain.h"
//^^ -constructor
keychain::keychain()
    : cKeys(0), cHead(nullptr), cTail(nullptr)
{
}

//^^ -destructor
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    this->cHead = this->cTail = nullptr; 
}

//^^ -keychain-functions
bool keychain::is_empty()
{
    if (cHead == nullptr && cTail == nullptr)
        return true;

    return false;
}

void keychain::add(const key &nKey)
{
    keynode *newNode = new keynode(nKey);
    //** CONDITIONS */
    //* 1. if both, start & end are empty, store key in start & keep end nullptr
    if (cHead == nullptr && cTail == nullptr)
    {
        cHead = newNode;
        cHead->setNext(cTail);
    }

    //& 2. if a startings node exists, but end is empty, store key in end node
    //? 3. if both start & end are occupied, store key between start & end, then link all keys

    this->cKeys++; //* update the number of keys in this chain
}

ostream &operator<<(ostream &out, const keychain &object)
{
    keynode *copy = object.cHead; //* dupe head node from object into the copy node

    if (!copy)
        out << "<keychain>=EMPTY" << endl;
    else
        out << "Existing Keys: " << object.cKeys << endl
            << endl;
    while (copy)
    {
        out << copy->getKey() << endl;
        copy = copy->getNext();
    }

    return out;
}