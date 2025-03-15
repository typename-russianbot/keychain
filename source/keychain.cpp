#include "../include/Keychain/keychain.h"

//^ -[PROTECTED]- ^

//^ - inputPasskey
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

//^ - isEmpty()
//^ return true if empty, otherwise false
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //* keychain empty, return true
        return true;

    return false; //! keychain not empty, return false
}

//^ - isRestricted()
//^ returns true if restricted, otherwise false
bool keychain::isRestricted()
{
    if (cAccess == restricted) //! access restricted, return true
        return true;

    return false; //* access is permitted, return false
}

//^ - requestAccess()
//^ returns true if access is permitted, false if denied
bool keychain::requestAccess(string passkey)
{
    char input;       //? -input    | input for attempt looping
    int attempts = 3; //? -attempts | # of attempts

    if (passkey == cPassword) //* parameter passed
    {
        cAccess = permitted;
        return true;
    }
    else //! no parameter passed
    {
        while (input != 'n' && attempts >= 0) //? continue loop until exited or passkey attempts has reached 0
        {
            //* match
            if (cPassword == inputPasskey())
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

//^ - setPasskey()
//^ sets passkey to the passed in string, or if none is passed, the user is prompted
bool keychain::setPasskey(string passkey)
{
    if (passkey == _none) //! no parameter, set equal to _none
    {
        this->cPassword = _none;

        //? update access permissions
        if (this->cAccess == restricted)
            this->cAccess = permitted;

        //* successfully set passkey
        return true;
    }
    else //* parameter passed, set equal to passkey
    {
        this->cPassword = passkey;

        //? update access permissions
        if (this->cAccess == permitted)
            this->cAccess = restricted;

        //* successfully set passkey
        return true;
    }

    return false; //! unknown error
}

//^ - add()
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

//^ - remove()
//^ removes a specified key from the chain
bool keychain::remove(const key &nKey)
{
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

//^ - lookup()
//^ searches for a specific key on the chain & displays
bool keychain::lookup(string keyident)
{
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

//* -[PUBLIC]- *

//* <CONSTRUCTOR>
//* @public
keychain::keychain(string passkey)

    : cKeys(0), cPassword(passkey), cAccess(restricted), cHead(nullptr), cTail(nullptr)
{
    if (cPassword == "")
        cPassword = _none;

    if (cPassword == _none)
        cAccess = permitted;
}

//* <DESTRUCTOR>
//* @public
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    this->cHead = this->cTail = nullptr;
}

//* <FUNCTIONS>
//* @public

//** create() */
//* @def: 
//* creates a key w/ the passed in parameters; if no parameters were passed, prompt user for input
bool keychain::create(const string &keyname, const string &username, const string &email, const string &password)
{
    key nKey(keyname, username, email, password); //? create a key object with passed in strings

    if (keyname == _none && username == _none && email == _none && password == _none) //! key is empty
    {
        if (_debugger)
            cout << "prompt user for input with empty param call" << endl;
        return false;
    }
    else //* add key onto the chain
    {
        this->add(nKey);
        return true;
    }

    return false;
}

//** remove() */ 
//* def: 
bool keychain::remove()
{
    return false;
}

//** search() */
//* @def:
bool keychain::search()
{
    return false;
}

//** display() */
//* @def: 
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

//* <OVERLOADS>
//* @public
ostream &operator<<(ostream &out, const keychain &keychain)
{
    if (keychain.cAccess == restricted) //! <access=RESTRICTED>
    {
        _clear;
        out << "<ACCESS DENIED>" << endl;
        return out;
    }

    keynode *copy = keychain.cHead; //? create a copy of keychain

    if (!copy) //! keychain is empty
    {
        out << "| Keys on Record: 0 |" << endl;
    }
    else //* display keychain
    {
        out << "| Keys on Record: " << keychain.cKeys << " |" << endl
            << endl
            << copy->getKey() << endl;

        copy = copy->getNext();

        while (copy != keychain.cHead)
        {
            out << copy->getKey() << endl;
            copy = copy->getNext();
        }
    }

    return out;
}