#pragma once
using namespace std;

//& |--- DEPENDENCIES ---|
#include <iostream>
#include <string>   //* string
#include <unistd.h> //* unistd.h

//& |--- MACROS ---|
#define _on true       //* _on
#define _off false     //* _off
#define _null "{null}" //* _null

extern bool debugger; 

//& |--- ENUMERATIONS ---|
//^  1. ENUM -- STRENGTH
enum strength {
  empty,    //* -- represents _null in the case there's no current password
  poor,     //* -- poor password protection
  weak,     //* -- weak password protection
  strong,   //* -- strong password protection
  excellent //* -- excellent password protection
};

//& |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object); 



//^  1. CLASS -- key
class key {
private:                 //^ -- MEMBERS --
  string keyDestination; //? 1. key_destination -- unlock destination for key
  string keyUsername;    //? 2. key_username -- username for this key
  string keyEmail;       //? 3. key_email -- email for this key
  string keyPassword;    //? 4. key_password -- password for this key
  strength keyIntegrity; //? 5. key_integrity -- strength of this key's password
  unsigned int keyAccess; //? 6. key_accessed -- number of times this key has been

public: //^ -- OPERATIONS --
  //* - CONSTRUCTOR -
  key(string destination = _null, string username = _null, string email = _null,
      string password = _null, strength integrity = empty, int access = 0);

  //* - FUNCTIONS -
  //? -- 1. setters
  void set_keyDestination(const string &nDestination);
  void set_mUsername(const string &nUsername);
  void set_mEmail(const string &nEmail);
  void set_mPassword(const string &nPassword);
  void set_mIntegrity(const strength &nIntegrity);

  //? -- 2. getters
  const string get_keyDestination(void);
  const string get_keyUsername(void);
  const string get_keyEmail(void);
  const string get_keyPassword(void);
  const strength get_keyIntegrity(void);

  //? -- 3. is_null (empty)
  bool is_null(void);
  key &operator=(const key &object);
  friend ostream &operator<<(ostream &output, const key &object);
  //* - DESTRUCTOR -
  ~key(); 
};