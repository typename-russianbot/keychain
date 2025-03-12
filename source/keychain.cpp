#include "../include/Keychain/keychain.h"
//^^ -constructor
keychain::keychain()
    : cKeys(0), cKeyaccess(restricted), cHead(nullptr), cTail(nullptr)
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
bool keychain::isEmpty() //^ -isEmpty
{
    if (cHead == nullptr && cTail == nullptr) //! 
        return true;

    return false;
}
void keychain::add(const key &nKey)
{
    keynode *newNode = new keynode(nKey); //* allocate space for a new node

    if (cHead == nullptr && cTail == nullptr) //! 1. if both, start & end are empty, store key in start & keep end nullptr
    {
        cHead = newNode;
        cTail = newNode;
        cHead->setNext(cTail);
        cHead->setPrev(cTail);
    }
    else if (cHead != nullptr && cTail == cHead) //! 2. if a startings node exists, but end is empty, store key in end node
    {
        cTail = newNode;

        cHead->setPrev(cTail);
        cHead->setNext(cTail);
        cTail->setNext(cHead);
        cTail->setPrev(cHead);
    }
    else //! 3. if both start & end are occupied, store key between start & end, then link all keys
    {
        //* set next & prev to head & tail respectively
        newNode->setNext(cHead);
        newNode->setPrev(cTail);

        cTail->setNext(newNode);
        cHead->setPrev(newNode);

        cTail = newNode;
    }

    this->cKeys++; //* update the number of keys in this chain
}

//^^ -overloads
ostream &operator<<(ostream &out, const keychain &object)
{
    keynode *copy = object.cHead; //! make a copy of cHead

    if (!copy) //! keychain is empty
    {
        out << "-Keychain Empty-" << endl;
    }
    else
    {
        out << "-My Keys-" << endl
            << endl
            << copy->getKey() << endl;

        copy = copy->getNext();

        while (copy != object.cHead)
        {
            out << copy->getKey() << endl;
            copy = copy->getNext();
        }
    }

    return out;
}