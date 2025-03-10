#include "../include/Keychain/key.h"

//& |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object)
{
  switch (object)
  {
  default:
    output << "{null}";
    break;
  case 1:
    output << "poor";
    break;
  case 2:
    output << "weak";
    break;
  case 3:
    output << "strong";
    break;
  case 4:
    output << "excellent";
    break;
  }

  return output;
}

//& |--- GLOBAL VARIABLES ---|
//^  1. BOOL -- debugger
bool debugger = _on;

//^^ -constructor
key::key(string destination, string username, string email, string password,
         strength integrity)
    : cKeyname(destination), cUsername(username), cEmail(email),
      cPassword(password), cKeyintegrity(integrity) {}

//^^ -set
void key::setKeyname(const string &nKeyname) //^^ 1.
{
  this->cKeyname = nKeyname;
}
void key::setEmail(const string &nEmail) //^^ 2.
{
  this->cEmail = nEmail;
}
void key::setUsername(const string &nUsername) //^^ 3.
{
  this->cUsername = nUsername;
}
void key::setPassword(const string &nPassword) //^^ 4.
{
  this->cPassword = nPassword;
}
void key::setKeyintegrity(const strength &nIntegrity) //^^ 5.
{
  this->cKeyintegrity = nIntegrity;
}

//^^ -get
const string key::getKeyname(void) { return this->cKeyname; }
const string key::getUsername(void) { return this->cUsername; }
const string key::getEmail(void) { return this->cEmail; }
const string key::getPassword(void) { return this->cPassword; }
const strength key::getKeyintegrity(void) { return this->cKeyintegrity; }

//^^ -key_functions
bool key::is_null(void)
{
  if (this->cKeyname == _null && this->cUsername == _null &&
      this->cEmail == _null && this->cPassword == _null &&
      this->cKeyintegrity == empty)
    return true;

  return false;
}

//^^ -overloads
ostream &operator<<(ostream &output, const key &object)
{
  output << "<Keyname - " << object.cKeyname << ">" << endl
         << "\t-    Email:\t" << object.cEmail << endl
         << "\t- Username:\t" << object.cUsername << endl
         << "\t- Password:\t" << object.cPassword << endl
         << "\t- Strength:\t" << object.cKeyintegrity << endl;

  return output;
}
key &key::operator=(const key &object)
{
  this->cKeyname = object.cKeyname;
  this->cUsername = object.cUsername;
  this->cEmail = object.cEmail;
  this->cPassword = object.cPassword;
  return *this;
}

//^^ -destructor
key::~key()
{
  if (debugger == _on)
    cout << "<" << this->cKeyname << " key>: destroyed" << endl;
}
