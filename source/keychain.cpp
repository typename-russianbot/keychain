#include "../include/Keychain/keychain.h"

//^ -[PROTECTED]- ^// @protectedsection

//^ <SETTERS> ^// @protected

//^ @def: takes the username param, then creates a file w/ the same name
bool keychain::setSaveFile(const string &username)
{
    cSaveFile = "data/keychains/ff.txt";

    ofstream newSaveFile(cSaveFile);

    if (ValidateFile(newSaveFile))
        newSaveFile.close();
    else
        return false;

    return true;
}

//^ <GETTERS> ^// @protected

//^^ getKeys() ^/
//^ @def: returns the number of keys found on this chain
const unsigned int keychain::getKeys()
{
    return cKeys;
}

//^^ getKey() ^/
//^ @def: returns the key specified by 'keyident'
const key keychain::getKey(const string &keyident)
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

//^^ getSaveFile() ^/
//^ @def: returns the savefile for this keychain
const string keychain::getSaveFile()
{
    return cSaveFile;
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

    if (keyident == _none) //! @note: no key identifier specified
        return false;

    //* @note: only one element in the keychain exists
    if (cHead == cTail && cHead->getKey().getKeyname() == keyident)
    {
        delete cHead;
        cHead = cTail = nullptr;
        cKeys--;
        return true;
    }

    //* @note: first element in keychain is the target
    if (cHead->getKey().getKeyname() == keyident)
    {
        cHead = cHead->getNext();
        cHead->setPrev(cTail);
        cTail->setNext(cHead);
        cKeys--;

        return true;
    }

    keynode *copy = cHead->getNext(), *prev = nullptr;

    while (copy != cHead)
    {
        if (copy->getKey().getKeyname() == keyident)
        {
            prev = copy->getPrev();
            prev->setNext(copy->getNext());
            copy->getNext()->setPrev(prev);
            cKeys--;

            if (copy == cTail)
                cTail = prev;

            delete copy;
            return true;
        }
        copy = copy->getNext();
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

//^^ 4. keychainLoad() ^/
bool keychain::keychainLoad()
{
    if (!loadKeychain())
        return false;

    return true;
}

//^^ 5. keychainSave() ^/
bool keychain::keychainSave()
{
    if (!saveKeychain())
        return false;

    return true;
}

//^^ 6. savefileDelete() ^/
//^ @def: removes the
bool keychain::savefileDelete(const string &file)
{
    if (remove(cSaveFile.c_str()) == 0)
    {
        cSaveFile = _none;
        return true;
    }

    return false;
}

//^^ 7. isEmpty() ^/
//^ @def: returns true if keychain is empty
bool keychain::isEmpty()
{
    if (cHead == nullptr && cTail == nullptr) //* keychain empty
        return true;

    return false; //! keychain not empty
}

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *// @public
keychain::keychain(const string &username)
    : cKeys(0), cHead(nullptr), cTail(nullptr)
{
}

//* <DESTRUCTOR> *// @public
keychain::~keychain()
{
    if (_debugger)
        cout << "destroying keychain" << endl;

    if (isEmpty()) //* @note: keychain is empty
        return;

    keynode *temp = cHead;
    keynode *next = nullptr;

    do
    {
        next = temp->getNext();
        delete temp;
        temp = next;
    } while (temp != cHead);

    cHead = cTail = nullptr;
}

//* <FUNCTIONS> *// @public

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
    if (isEmpty())
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
    if (isEmpty())
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

//** 6. loadKeychain() */
bool keychain::loadKeychain()
{
    ifstream readfile(cSaveFile);

    if (!ValidateFile(readfile))
        return false;

    return false;
}

//** 7. saveKeychain() */
bool keychain::saveKeychain()
{
    setSaveFile(cSaveFile);

    ofstream writefile(cSaveFile);

    if (!ValidateFile(writefile))
        return false;

    writefile << cHead->getKey().getKeyname() << "," << cHead->getKey().getUsername() << "," << cHead->getKey().getEmail() << "," << cHead->getKey().getPassword() << endl;

    keynode *copy = cHead->getNext();

    while (copy != cHead)
    {
        writefile << copy->getKey().getKeyname() << "," << cHead->getKey().getUsername() << "," << cHead->getKey().getEmail() << "," << cHead->getKey().getPassword() << endl;
        copy = copy->getNext();
    }

    return true;
}

bool keychain::deleteKeychain()
{
    return false; 
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