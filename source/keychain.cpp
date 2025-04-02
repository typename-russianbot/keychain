#include "../include/Keychain/keychain.h"

//^ <MUTATORS> ^//

//^^ get_keys() | @def: returns the number of keys on this chain
const unsigned int keychain::get_keys() { return cKeys; }

//^^ get_key() | @def: returns the key specified by
const key keychain::get_key(const string &target) {
  key nKey;

  if (is_empty() || !search_key(target)) //! @note: empty, return blank key
    return nKey;

  keynode *copy = this->cHead;

  if (copy->getKey().getKeyname() == target)
    return copy->getKey();

  else
    copy = copy->getNext();

  while (copy != cHead) {
    if (copy->getKey().getKeyname() == target)
      return copy->getKey();

    copy = copy->getNext();
  }

  return nKey; //! @note: return empty key if not found
}

//^^ get_owner() | @def: returns owner of the keychain
const string keychain::get_owner() { return cOwner; }

//^^ set_owner() | @def: sets the owner of the keychain to 'owner'
void keychain::set_owner(const string &owner) { this->cOwner = owner; }

//^ <HELPERS> ^//

//^^ new_key() | @def: adds 'nKey' onto the chain
bool keychain::new_key(const key &nKey) {

  keynode *newNode = new keynode(nKey);
  bool flag = false;

  if (cHead == nullptr && cTail == nullptr) {
    //* @note: set both, cHead & cTail to newNode

    cHead = newNode;
    cTail = newNode;
    cHead->setNext(cTail);
    cHead->setPrev(cTail);

    flag = true;

  } else if (cHead != nullptr && cTail == cHead) {
    //* @note: cHead is occupied, store in cTail
    cTail = newNode;

    cHead->setPrev(cTail);
    cHead->setNext(cTail);
    cTail->setNext(cHead);
    cTail->setPrev(cHead);

    flag = true;

  } else {
    //* @note: both, cHead & cTail are occupied, link the newNode to cHead
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

//^^ delete_key()
//^ @def: deletes a key object (if found) from the chain
bool keychain::delete_key(const string &keyident) {

  //* @note: only one element in the keychain exists
  if (cHead == cTail && cHead->getKey().getKeyname() == keyident) {
    delete cHead;
    cHead = cTail = nullptr;
    cKeys--;
    return true;
  }

  //* @note: first element in keychain is the target
  if (cHead->getKey().getKeyname() == keyident) {
    cHead = cHead->getNext();
    cHead->setPrev(cTail);
    cTail->setNext(cHead);
    cKeys--;

    return true;
  }

  keynode *copy = cHead->getNext(), *prev = nullptr;

  while (copy != cHead) {
    if (copy->getKey().getKeyname() == keyident) {
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

//^^ search_key()
//^ @def: returns true if 'keyident' matches a 'keyname' on the chain
bool keychain::search_key(const string &keyident) {
  if (is_empty()) //! @note: keychain is empty
    return false;

  if (keyident == _none) //! @note: no keyident specified
    return false;

  keynode *copy = this->cHead; //* @note: copy keychain's head node

  if (copy->getKey().getKeyname() ==
      keyident) //* @note: keyident is in the head node
    return true;

  else //* @note: if keyident was not in cHead, begin to compare to all other
       // elements
    copy = copy->getNext();

  while (copy != cHead) {
    if (copy->getKey().getKeyname() == keyident)
      return true;

    copy = copy->getNext();
  }

  return false;
}

//^^ is_empty() | @def: returns true if empty, false otherwise
bool keychain::is_empty() {
  if (cHead == nullptr && cTail == nullptr)
    return true;

  return false;
}

//^^ load_keychain() | @def: loads keychain data from
bool keychain::load_keychain(const string &target) {

  string savefile = "data/keychains/" + target + ".txt";

  ifstream readfile(savefile);

  if (!ValidateFile(readfile)) {
    cerr << "file opening failure" << endl;
    return false;
  }

  string line;

  while (getline(readfile, line)) {

    stringstream currentline(line);
    string keyname, username, email, password;

    if (getline(currentline, keyname, ',') &&
        getline(currentline, username, ',') &&
        getline(currentline, email, ',') && getline(currentline, password)) {

      key filekey(keyname, username, email, password);

      newKey(filekey);
    }
  }

  readfile.close();
  return true;
}

//^^ save_keychain() | @def: creates the savefile for
bool keychain::save_keychain() {
  string savefile = "data/keychains/" + this->cOwner + ".txt";

  ofstream writefile(savefile);

  if (!ValidateFile(writefile)) //! @note: file failed to ope
  {
    cerr << "file opening failure" << endl;
    return false;
  }

  writefile << cHead->getKey().getKeyname() << ","
            << cHead->getKey().getUsername() << ","
            << cHead->getKey().getEmail() << ","
            << cHead->getKey().getPassword() << endl;

  keynode *copy = cHead->getNext();

  while (copy != cHead) {
    writefile << copy->getKey().getKeyname() << ","
              << copy->getKey().getUsername() << ","
              << copy->getKey().getEmail() << ","
              << copy->getKey().getPassword() << endl;
    copy = copy->getNext();
  }

  writefile.close(); //* @note: close file

  return true;
}

//^^ delete_keychain() | @def: wipes the target file in 'data/keychains'
bool keychain::delete_keychain(const string &target) {
  string savefile;

  savefile = "data/keychains/" + target + ".txt";

  ifstream file(savefile);

  if (file) {
    file.close();
    remove(savefile.c_str());
    return true;
  }

  file.close();
  return false;
}

//^ [-------------] ^//

//* [---RESOURCE MANAGERS---] *//

keychain::keychain(const string &owner)
    : cOwner(owner), cHead(nullptr), cTail(nullptr), cKeys(0) {}
keychain::~keychain() {
  if (_debugger)
    cout << "destroying keychain" << endl;

  if (is_empty()) //* @note: keychain is empty
    return;

  keynode *temp = cHead;
  keynode *next = nullptr;

  do {
    next = temp->getNext();
    delete temp;
    temp = next;
  } while (temp != cHead);

  cHead = cTail = nullptr;
}

//* [---FUNCTIONS---] *//

//** newKey() | @def:
bool keychain::newKey(const key &nKey) {
  if (new_key(nKey))
    return true;

  return false;
}

//** deleteKey() | @def:
bool keychain::deleteKey(const string &target) {

  if (target == _none || is_empty())
    return false;

  else if (delete_key(target))
    return true;

  return false;
}

//** searchKey() | @def:
bool keychain::searchKey(const string &target) {

  if (target == _none || is_empty())
    return false;

  else if (search_key(target))
    return true;

  return false;
}

//** printKey() | @def:
bool keychain::printKey(const string &target) {

  //! @note: test to ensure working
  if (!searchKey(target) || is_empty())
    return false;

  cout << get_key(target) << endl;
  return true;
}

//** printKeychain() | @def: prints all keys in the chain
void keychain::printKeychain() { cout << *this << endl; }

//** loadKeychain() | @def: loads target keychain
bool keychain::loadKeychain(const string &target) {

  //! @def: no target specified
  if (target == _none) {
    cerr << "<error>: no target specified" << endl;
    return false;
  }

  //? @def: keychain loaded
  else if (load_keychain(target))
    return true;

  return false;
}

//** saveKeychain() | @def: saves keychain to 'owner'.txt
bool keychain::saveKeychain() {

  //! @def: failed saving keychain
  if (!save_keychain()) {
    cerr << "<error>: failed saving keychain" << endl;
    return false;
  }

  //? @def: keychain is empty
  else if (is_empty()) {
    cerr << "<error>: keychain empty" << endl;
    return false;
  }
  
  //? @def: keychain saved
  else
    return true;

  return false;
}

//** deleteKeychain() | @def:
bool keychain::deleteKeychain(const string &target) {

  //! @def: no target specified
  if (target == _none) {
    cerr << "<error>: no target specified" << endl;
    return false;
  }

  //? @def: keychain deleted
  else if (delete_keychain(target))
    return true;

  return false;
}

//** operator<<()
ostream &operator<<(ostream &out, const keychain &keychain) {
  keynode *copy = keychain.cHead;

  //? @def: keychain is empty
  if (!copy)
    out << "| Keys on Record: 0 |" << endl;

  //? @def: loop until all keychain elements are dipslayed
  else {
    out << "|-------------------------------------|" << endl
        << endl
        << "Keys on Record: " << keychain.cKeys << endl
        << endl
        << copy->getKey() << endl;

    copy = copy->getNext();

    while (copy != keychain.cHead) {
      out << copy->getKey() << endl;
      copy = copy->getNext();
    }

    out << "|-------------------------------------|" << endl;
  }

  return out;
}
