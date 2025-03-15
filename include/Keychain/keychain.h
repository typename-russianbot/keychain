#pragma once
#include "keynode.h"

//? -[CLASS: Keychain]- ?
class keychain
{
  //! -[PRIVATE]- !
private:
  unsigned int cKeys; //! cKeys
  string cPassword;   //! cPassword
  clearance cAccess;  //! cAccess
  keynode *cHead;     //! cHead
  keynode *cTail;     //! cTail

  //^ -[PROTECTED]- ^
protected:
  //^ <HELPERS>
  string inputPasskey();                       //^ inputPasskey()
  bool isEmpty();                              //^ isEmpty()
  bool isRestricted();                         //^ isRestricted()
  bool requestAccess(string password = _none); //^ requestAccess()
  bool setPasskey(string password = _none);    //^ setPasskey()
  void add(const key &nKey);                   //^ add()
  bool remove(const key &nKey);                //^ remove()
  bool lookup(string keyident = _none);        //^ lookup()

  //* -[PUBLIC]- *
public:
  //* <CONSTRUCTOR>
  keychain(string passkey = _none);

  //* <DESTRUCTOR>
  ~keychain();

  //* <FUNCTIONS>
  bool create(const string &keyname = _none, const string &username = _none,
              const string &email = _none, const string &password = _none); //* create()
  bool remove();                                                            //* remove()
  bool search();                                                            //* search()
  bool print();                                                             //* print()
  bool load();                                                              //* load()
  bool save();                                                              //* save()

  //* <OVERLOADS>
  friend ostream &operator<<(ostream &out, const keychain &keychain); //* operator<<
};
