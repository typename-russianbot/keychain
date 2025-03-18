#include "../include/Keychain/keychain.h"

//^ -[PROTECTED]- ^// @protectedsection

//^ <GETTERS> ^// @protected

//^ @def: returns the number of keys found on this chain
unsigned int keychain::getKeys()
{
    return cKeys;
}

//^ <HELPERS> ^// @protected

//^^ 1. keyNew() ^/
void keychain::keyNew(const key &nKey)
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

//^^ 2. keyDelete() ^/
bool keychain::keyDelete(const key &nKey)
{
    if (isEmpty()) //! nothing to remove
        return false;

    return true;
}

//^^ 3. keySearch() ^/
bool keychain::keySearch(const string &keyident)
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

//^^ 4. isEmpty() ^/
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //* keychain empty
        return true;

    return false; //! keychain not empty
}

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *// @public
keychain::keychain(const string &password)
    : cKeys(0), cHead(nullptr), cTail(nullptr)
{
}

//* <DESTRUCTOR> *// @public
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    this->cHead = this->cTail = nullptr;
}

//* <FUNCTIONS> *// @public

//** 1. newKey() */
//* @def: creates a key w/ the passed in parameters
bool keychain::newKey(const string &keyname, const string &username, const string &email, const string &password)
{
    key nKey(keyname, username, email, password); //? create a key object with passed in strings

    if (keyname == _none && username == _none && email == _none && password == _none) //! do not add an empty key
        return false;

    else //* add key
    {
        this->keyNew(nKey);
        return true;
    }

    return false; //! unknown error
}

//**TODO: 2. deleteKey() */
//* def:
bool keychain::deleteKey(const string &target)
{
    return false;
}

//**TODO: 3. searchKey() */
//* @def:
bool keychain::searchKey()
{
    return false;
}

//** 5. printKeychain() */
void keychain::printKeychain()
{
    cout << *this << endl;
}

//* <OVERLOADS> *// @public
ostream &operator<<(ostream &out, const keychain &keychain)
{
    keynode *copy = keychain.cHead;

    if (!copy) //! keychain is empty
        out << "| Keys on Record: 0 |" << endl;

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