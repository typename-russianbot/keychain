#include "../include/Keychain/keychain.h"
//^^ -constructor
keychain::keychain(string passkey)
    : cKeys(0), cPasskey(passkey), cAccess(restricted), cHead(nullptr), cTail(nullptr)
{
    if (cPasskey == "")
        cPasskey = _none;

    if (cPasskey == _none)
        cAccess = permitted;
}

//^^ -destructor
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    this->cHead = this->cTail = nullptr;
}

//^^ -<keychain>_functions
bool keychain::isEmpty() //^ -isEmpty
{
    if (cHead == nullptr && cTail == nullptr) //! if cHead & cTail = nullptr, return true
        return true;

    return false;
}
bool keychain::isRestricted() //^ -isRestricted
{
    if (cAccess == restricted) //! if cAccess = restricted, return true
        return true;

    return false;
}
bool keychain::requestAccess(string passkey) //^ -requestAccess
{
    if (passkey == cPasskey) //* if a passkey was passed
    {
        cAccess = permitted;
        return true;
    }
    else //! no passkey was passed
    {
        string input;

        HideTerminal(); 

        cout << "Password: ";
        cin >> input;

        ShowTerminal(); 

        if (input == cPasskey)
        {
            cAccess = permitted;
            return true;
        }
    }

    return false;
}
void keychain::add(const key &nKey) //^ -add
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
    //* create a copy of keychain
    keynode *copy = object.cHead;

    out << "| Keychain Access: " << object.cAccess << " | ";

    if (object.cAccess == restricted) //! keychain access restricted
        return out;

    if (!copy) //! keychain is empty
    {
        out << "Keys Found: 0" << endl;
    }
    else //* print keys if access reqs. met or no passkey exists
    {
        out << "Keys Found: " << object.cKeys << " |" << endl
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