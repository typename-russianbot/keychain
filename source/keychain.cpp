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
bool keychain::keyNew(const key &nKey)
{
    keynode *newNode = new keynode(nKey); //* @note: allocate space for a new node
    bool flag = false; 

    if (cHead == nullptr && cTail == nullptr) //* @note: set both, cHead & cTail to newNode
    {
        cHead = newNode;
        cTail = newNode;
        cHead->setNext(cTail);
        cHead->setPrev(cTail);

        flag = true; 
    }
    else if (cHead != nullptr && cTail == cHead) //* @note: cHead is occupied, store in cTail
    {
        cTail = newNode;

        cHead->setPrev(cTail);
        cHead->setNext(cTail);
        cTail->setNext(cHead);
        cTail->setPrev(cHead);

        flag = true; 
    }
    else //* @note: both, cHead & cTail are occupied, link the newNode to cHead & cTail, then set newNode as cTail
    {
        //* set next & prev to head & tail respectively
        newNode->setNext(cHead);
        newNode->setPrev(cTail);

        cTail->setNext(newNode);
        cHead->setPrev(newNode);

        cTail = newNode;

        flag = true; 
    }

    this->cKeys++; //* @note: iterate the number of keys stored on this chain

    return flag; 
}

//^^ 2. keyDelete() ^/
bool keychain::keyDelete()
{
    if (isEmpty()) //! @note: keychain is empty
        return false;

    return true;
}

//^^ 3. keySearch() ^/
//^ @def: takes 'keyident' & compares it to all the keynames of each key on the current chain
bool keychain::keySearch(const string &keyident)
{
    if (isEmpty()) //! @note: keychain is empty
        return false;

    if (keyident == _none) //! @note: no keyident specified
        return false;

    keynode *copy = this->cHead; //* @note: copy keychain's head node

    if (copy->getKey().getKeyname() == keyident) //* @note: keyident is in the head node
        return true;

    else //* @note: if keyident was not in cHead, begin to compare to all other elements
        copy = copy->getNext();

    while (copy != cHead)
    {
        if (copy->getKey().getKeyname() == keyident)
            return true;

        copy = copy->getNext(); 
    }

    return false;
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

//** newKeychain() */
bool keychain::newKeychain(const string &owner)
{
    if (owner == _none)
        return false;
    else
    {
        cOwner = owner;
        cKeys = 0;
        cHead = nullptr;
        cTail = nullptr;
    }
    return false;
}

bool keychain::newKey(const key &nKey)
{
    if (keyNew(nKey))
        return true; 
    
    return false; 
}

//**TODO: 2. deleteKey() */
//* def:
bool keychain::deleteKey()
{
    return false;
}

//**TODO: 3. searchKey() */
//* @def:
bool keychain::searchKey(const string& keyident)
{
    if(keySearch(keyident))
        return true; 

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