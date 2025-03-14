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

//^ return true if empty, otherwise false
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //* keychain empty, return true
        return true;

    return false; //! keychain not empty, return false
}

//^ returns true if restricted, otherwise false
bool keychain::isRestricted()
{
    if (cAccess == restricted) //! access restricted, return true
        return true;

    return false; //* access is permitted, return false
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
                cout << "| Remaining Attempts: " << attempts << " |" << endl
                     << "Re-enter Passkey? [y/n]: ";
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

//^ sets passkey to the passed in string, or if none is passed, the user is prompted
bool keychain::setPasskey(string passkey)
{
    if (passkey == _none) //! no parameter, set equal to _none
    {
        this->cPasskey = _none;

        //? update access permissions
        if (this->cAccess == restricted)
            this->cAccess = permitted;

        //* successfully set passkey
        return true;
    }
    else //* parameter passed, set equal to passkey
    {
        this->cPasskey = passkey;

        //? update access permissions
        if (this->cAccess == permitted)
            this->cAccess = restricted;

        //* successfully set passkey
        return true;
    }

    return false; //! unknown error
}

//^ adds a new key to the chain
void keychain::add(const key &nKey)
{
    cout << "| -Keychain: Add- |" << endl;

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
bool keychain::remove(const key &nKey)
{
    cout << "| -Keychain: Remove- |" << endl; //^ OPERATION: remove()

    if (isEmpty()) //! nothing to remove
        return false;

    //& request keychain permissions
    if (this->requestAccess()) //* <access==GRANTED>
    {
        _clear;
        cout << "<KEYCHAIN ACCESS PERMITTED>" << endl
             << *this << endl;
    }
    else //! <access==DENIED>
    {
        _clear;
        cout << "<KEYCHAIN ACCESS DENIED>" << endl;
        return false;
    }

    return true; 
}

//^ searches for a specific key on the chain & displays
bool keychain::lookup(string keyident)
{
    cout << "| -Keychain: Search- |" << endl; //^ OPERATION: lookup()

    if (isEmpty()) //! nothing to lookup
        return false;

    //! request keychain permissions

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
    cout << "| -Keychain: Display- |" << endl; //^ OPERATION: print()

    //& request keychain permissions
    if (this->requestAccess()) //* <access==GRANTED>
    {
        _clear;
        cout << "<KEYCHAIN ACCESS PERMITTED>" << endl
             << *this << endl;
    }
    else //! <access==DENIED>
    {
        _clear;
        cout << "<KEYCHAIN ACCESS DENIED>" << endl;
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
    if (object.cAccess == restricted) //! <access=RESTRICTED>
    {
        _clear;
        out << "<ACCESS DENIED>" << endl;
        return out;
    }

    keynode *copy = object.cHead; //? create a copy of keychain

    if (!copy) //! keychain is empty
    {
        out << "| Keys on Record: 0 |" << endl;
    }
    else //* display keychain
    {
        out << "| Keys on Record: " << object.cKeys << " |" << endl
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