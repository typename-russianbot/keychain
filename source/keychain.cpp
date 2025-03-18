#include "../include/Keychain/keychain.h"

//^ -[PROTECTED]- ^// @protectedsection

//^ <GETTERS> ^// @protected

//^ @def: returns the number of keys found on this chain
unsigned int keychain::getKeys()
{
    return cKeys;
}

key keychain::getKey(const string &keyident)
{
    key nKey;
    if (isEmpty()) //! @note: empty, return blank key
        return nKey;

    if (!keySearch(keyident)) //! @note: keysearch failed to find keyident, return blank key
        return nKey;

    keynode *copy = this->cHead;

    if (copy->getKey().getKeyname() == keyident)
        return copy->getKey();

    else
        copy = copy->getNext();

    while (copy != cHead)
    {
        if (copy->getKey().getKeyname() == keyident)
            return copy->getKey();

        copy = copy->getNext();
    }

    return nKey; //! @note: return empty key if not found
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
bool keychain::keyDelete(const string &keyident)
{
    if (isEmpty()) //! @note: keychain is empty
        return false;

    else
    {
        //* @note: if both cHead & cTail have the same keyname, only one element exists
        if (cHead->getKey().getKeyname() == keyident && cTail->getKey().getKeyname() == keyident)
        {
            cHead = cTail = nullptr;
            cKeys--;
            return true;
        }

        //* @note: if cHead & cTail do not equal
        else if (cHead->getKey().getKeyname() == keyident)
        {
            keynode *temp = cHead, *prev = cHead->getPrev(), *next = cHead->getNext();

            prev = temp->getPrev();
            next = temp->getNext();

            next->setPrev(prev);
            prev->setNext(next);

            cHead = next;
            cTail = prev; 
            cKeys--;

            delete temp;
            delete next;
            delete prev;

            return true;
        }
        else
        {
            keynode *temp = cHead->getNext(), *prev, *next;

            while (temp != cHead)
            {
                if (temp->getKey().getKeyname() == keyident)
                {
                    prev = temp->getPrev();
                    next = temp->getNext();

                    next->setPrev(prev);
                    prev->setNext(next);

                    while (next != cHead)
                    {
                        next = next->getPrev();
                    }

                    cHead = next; 
                    cTail = cHead->getPrev(); 
                    cKeys--; 
                    return true; 
                }

                temp = temp->getNext();
            }
        }
    }

    return false;
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

//** 1. newKeychain() */
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

//** 2. newKey() */
bool keychain::newKey(const key &nKey)
{
    if (keyNew(nKey))
        return true;

    return false;
}

//** 2. deleteKey() */
//* def:
bool keychain::deleteKey(const string &keyident)
{
    if(isEmpty())
        return false; 

    if (keyDelete(keyident))
        return true;

    return false;
}

//** 3. searchKey() */
//* @def:
bool keychain::searchKey(const string &keyident)
{
    if (keySearch(keyident))
        return true;

    return false;
}

//** 4. printKey() */
bool keychain::printKey(const string &keyident)
{
    if(isEmpty())
        return false; 

    if (!searchKey(keyident))
        return false;
   
    cout << getKey(keyident) << endl; 
    return true; 
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