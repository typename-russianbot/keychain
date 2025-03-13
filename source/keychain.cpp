#include "../include/Keychain/keychain.h"

//! <protected functions>
//^ returns the user inputted
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
//^ constructs chain
keychain::keychain(string passkey)

    : cKeys(0), cPasskey(passkey), cAccess(restricted), cHead(nullptr), cTail(nullptr)
{
    if (cPasskey == "")
        cPasskey = _none;

    if (cPasskey == _none)
        cAccess = permitted;
}
// TODO - destroys chain
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    this->cHead = this->cTail = nullptr;
}

//^^ -<keychain> Functions-
//^ return true if empty, otherwise false
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //! if cHead & cTail = nullptr, return true
        return true;

    return false;
}
//^ returns true if restricted, otherwise false
bool keychain::isRestricted()
{
    if (cAccess == restricted) //! if cAccess = restricted, return true
        return true;

    return false;
}
//^ returns true if access is permitted, false if denied
bool keychain::requestAccess(string passkey)
{
    char input;       //? -input    | input for attempt looping
    int attempts = 3; //? -attempts | # of attempts

    if (passkey == cPasskey) //* parameter passed
    {
        cAccess = permitted;
        return true;
    }

    else //! no parameter passed
    {
        while (input != 'n' && attempts >= 0) //? continue loop until exited or passkey attempts has reached 0
        {
            //* match
            if (cPasskey == inputPasskey())
            {
                cAccess = permitted;
                return true;
            }

            //! mismatch encountered
            while (true)
            {
                cout << "Remaining Attempts: " << attempts << " | " << "Re-enter Passkey? [y/n]: ";
                cin >> input;
                input = tolower(input);

                if (input == 'n') //! exit function when equal to 'n'
                    return false;
                else if (input == 'y') //* break free of loop when valid
                    break;
            }
            attempts--;
        }
    }

    return false;
}
// TODO - sets cPasskey to the passed string parameter
bool keychain::setPasskey(string passkey)
{
    return false;
}
//^ adds a new key to the chain
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
//^ removes a specified key from the chain
bool keychain::remove(string keyident)
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
//^ searches for a specific key on the chain & displays
bool keychain::lookup(string keyident)
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
//^ prints the whole keychain if access is granted
bool keychain::print()
{
    if (this->requestAccess()) //* <access==GRANTED>
    {
        _clear;
        cout << "<PASSKEY ACCEPTED>" << endl
             << *this << endl;
    }
    else //! <access==DENIED>
    {
        _clear;
        cout << "<ACCESS DENIED>" << endl;
        return false;
    }

    //? re-lock access permissions
    if (this->cAccess == permitted)
        this->cAccess = restricted;

    return true;
}

//^^ -overloads-
ostream &operator<<(ostream &out, const keychain &object)
{
    //* create a copy of keychain
    keynode *copy = object.cHead;
    char input;

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