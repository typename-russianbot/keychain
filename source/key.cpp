#include "../include/Keychain/key.h"
//!! <master>
//** 1. operator<< (enum==STRENGTH)
ostream &operator<<(ostream &output, const integrity &object)
{
  switch (object)
  {
  default:
    output << "<none>";
    break;
  case 1:
    output << "<poor>";
    break;
  case 2:
    output << "<weak>";
    break;
  case 3:
    output << "<strong>";
    break;
  case 4:
    output << "<excellent>";
    break;
  }

  return output;
}
//** 2. operator<< (enum==ACCESS)
ostream &operator<<(ostream &out, const clearance &object)
{
  switch (object)
  {
  default: //* by default, access to most info should be restricted
    cout << "<restricted>";
    break;

  case 1:
    cout << "<unrestricted>";
    break;
  }

  return out;
}

//??  1. BOOL -- debugger
bool _debugger = _off;

//& <key>
//^^ -constructor
key::key(string destination, string username, string email, string password,
         integrity integrity)
    : cKeyname(destination), cUsername(username), cEmail(email),
      cPassword(password), cKeyintegrity(integrity) {}

//^^ -destructor
key::~key()
{
  if (_debugger == _on)
    cout << "<" << this->cKeyname << " key>: destroyed" << endl;
}

//^^ -set
void key::setKeyname(const string &nKeyname)
{
  this->cKeyname = nKeyname;
}
void key::setEmail(const string &nEmail)
{
  this->cEmail = nEmail;
}
void key::setUsername(const string &nUsername)
{
  this->cUsername = nUsername;
}
void key::setPassword(const string &nPassword)
{
  this->cPassword = nPassword;
}
void key::setKeyintegrity(const integrity &nIntegrity)
{
  this->cKeyintegrity = nIntegrity;
}

//^^ -get
const string key::getKeyname(void) { return this->cKeyname; }
const string key::getUsername(void) { return this->cUsername; }
const string key::getEmail(void) { return this->cEmail; }
const string key::getPassword(void) { return this->cPassword; }
const integrity key::getKeyintegrity(void) { return this->cKeyintegrity; }

//^^ -<key>_functions

//^^ -overloads
ostream &operator<<(ostream &output, const key &object) //& -operator<<
{
  output << "<" << object.cKeyname << ">" << endl
         << "\t-    Email:\t" << object.cEmail << endl
         << "\t- Username:\t" << object.cUsername << endl
         << "\t- Password:\t" << object.cPassword << endl
         << "\t- Strength:\t" << object.cKeyintegrity << endl;

  return output;
}
key &key::operator=(const key &object) //& -operator=
{
  this->cKeyname = object.cKeyname;
  this->cUsername = object.cUsername;
  this->cEmail = object.cEmail;
  this->cPassword = object.cPassword;
  return *this;
}
