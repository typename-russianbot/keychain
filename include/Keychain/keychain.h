// TODO: class=<keychain>
#pragma once
#include "keynode.h"
class keychain
{
private:              //!! -Attributes-
  unsigned int cKeys; //*  -cKeys     | numbers of keys found on chain
  string cPasskey;    //*  -cPasskey  | passkey for keychain, same profile passkey
  clearance cAccess;  //*  -cAccess   | keychain permissions
  keynode *cHead;     //*  -cHead     | head of keychain
  keynode *cTail;     //*  -cTail     | tail of keychain

protected:                                  //!! -Protected Functions-
  string inputPasskey();                    //& -inputPasskey()
  void lookuptKeyname(const string &ident); // TODO -lookupKeyname()
  void lookupUsername(const string &ident); // TODO -lookupUsername()
  void lookupEmail(const string &ident);    // TODO -lookupEmail()

public:                             //!! -Private Functions-
  keychain(string passkey = _none); //^^ -constructor
  ~keychain();                      //^^ -destructor

  //^^ -<keychain> Functions-
  bool isEmpty();                             //& -isEmpty()        | if empty: return true ; otherwise: return false
  bool isRestricted();                        //& -isRestricted()   | if restricted: return true ; otherwise: return false
  bool requestAccess(string passkey = _none); //& -requestAccess()  | prompts user for access to keychain
  bool setPasskey(string passkey = _none);    // TODO -setPasskey()     | sets passkey to the passed in string, or if none is passed, the user is prompted
  void add(const key &nKey);                  //& -add()            | adds a new key to the chain
  bool remove(string keyident = _none);       // TODO -remove()         | removes a specified key via keyident, if no keyident is specified,
  bool lookup(string keyident = _none);       // TODO -lookup()         |
  bool print();                               //& -print()          | prints keychain
  void loadKeychain();                        // TODO -loadKeychain()   |
  void saveKeychain();                        // TODO -saveKeychain()   |

  //^^ -Overloads-
  friend ostream &operator<<(ostream &out, const keychain &object); //& -operator<< |
  keychain operator=(const keychain &object);                       //& -operator=  |
};
