#include "../include/Keychain/keychain.h"
//! <protected functions>
string keychain::inputPasskey()
{
    string input, verification;

    HideTerminal();

    cout << "Passkey: ";
    cin >> input;
    cout << endl;

    cout << "Re-enter Passkey: ";
    cin >> verification;
    cout << endl;

    ShowTerminal();

    if (input == verification)
        return input;
    else
        return _none;
}

//* <public functions>
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
    if (passkey == cPasskey) //* if a passkey was passed as a parameter
    {
        cAccess = permitted;
        return true;
    }
    else //! no parameter passed
    {
        if (cPasskey == inputPasskey())
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
bool keychain::remove(string keyident) //^ -remove
{
    if (keyident == _none)
        return false;
    else
    {
        //? search thru chain
        //? 1. by keyname
        //? 2. by email
        //? 3. by username
        return true; 
    }
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