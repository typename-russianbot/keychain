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
    else if (cHead != nullptr && cTail == nullptr)
    {
        cTail = newNode;
        cTail->setNext(cHead);
        cTail->setPrev(cHead);

        cHead->setPrev(cTail);
        cHead->setNext(cTail);
    }
    //? 3. if both start & end are occupied, store key between start & end, then link all keys
    else if (cHead != nullptr && cTail != nullptr)
    {
    }

    this->cKeys++; //* update the number of keys in this chain
}

ostream &operator<<(ostream &out, const keychain &object)
{
    keynode *copy = object.cHead; //* copy of head node

    if (!copy) //! keychain is empty
    {
        out << "<keychain>=EMPTY" << endl;
    }
    else if (copy->getNext() == copy->getPrev()) //! only cHead && cTail exist
    {
        out << "-My Keys-" << endl
            << endl
            << copy->getKey() << endl;

        copy->getNext();
        out << copy->getKey() << endl;
    }
    else //! print Head Node, n Nodes between head & tail, then tail node
    {
        out << "-My Keys-" << endl
            << endl
            << object.cKeys
            << endl;

        while (copy)
        {
            out << copy->getKey() << endl;
            copy = copy->getNext();
        }
    }

    return out;
}