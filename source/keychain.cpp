#include "../include/Keychain/keychain.h"

//^ -[PROTECTED]- ^

//^^ inputPassword() ^/
string keychain::inputPassword()
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

//^^ isEmpty() ^/
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //* keychain empty
        return true;

    return false; //! keychain not empty
}

//^^ isRestricted() ^/
bool keychain::isRestricted()
{
    if (cAccess == restricted) //* access restricted
        return true;

    return false; //! access permitted
}

//^^ accessKeychain() ^/
bool keychain::accessKeychain(string passkey)
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
            if (cPassword == inputPassword())
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

//^^ addKey() ^/
void keychain::addKey(const key &nKey)
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

//^^ removeKey() ^/
bool keychain::deleteKey(const key &nKey)
{
    if (isEmpty()) //! nothing to remove
        return false;

    //& request keychain permissions
    if (this->accessKeychain()) //* <access==GRANTED>
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

//^^ lookupKey() ^/
bool keychain::lookupKey(string keyident)
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

bool keychain::addPassword(const string &password)
{
    if (password == _none) //! no password
    {
        cPassword = _none;
        cAccess = permitted; //? unlock access
        return true;
    }
    else //* password param accepted
    {
        cPassword = password;
        cAccess = restricted; //? restrict access
        return true;
    }

    return false;
}

//* -[PUBLIC]- *

//* <CONSTRUCTOR>
//* @public
keychain::keychain(const string &password)
    : cKeys(0), cPassword(password), cAccess(restricted), cHead(nullptr), cTail(nullptr)
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

//** createKey() */
//* @def: creates a key w/ the passed in parameters; if no parameters were passed, prompt user for input
bool keychain::createKey(const string &keyname, const string &username, const string &email, const string &password)
{
    key nKey(keyname, username, email, password); //? create a key object with passed in strings

    if (keyname == _none && username == _none && email == _none && password == _none) //! key is empty, cancel createKey()
    {
        return false;
    }
    else //* add key onto the chain
    {
        this->addKey(nKey);
        return true;
    }

    return false; //! unknown error
}

//**TODO: removeKey() */
//* def:
bool keychain::removeKey(const string &target)
{
    return false;
}

//**TODO: searchKey() */
//* @def:
bool keychain::searchKey()
{
    return false;
}

//** printKeychain() */
//* @def:
bool keychain::printKeychain()
{
    //& request keychain permissions
    if (this->accessKeychain()) //* <access==GRANTED>
    {
        cout << "<KEYCHAIN ACCESS PERMITTED>" << endl
             << *this << endl;
    }
    else //! <access==DENIED>
    {
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