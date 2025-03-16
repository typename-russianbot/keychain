#include "../include/Keychain/key.h"

//^ -[PROTECTED]- ^// @protectedsection

//^^ ^/
void key::inputKeyname(istream &in, key &object)
{
  cout << "Keyname: ";
  getline(in, object.cKeyname);

  while (!ValidateInput(object.cKeyname))
  {
    cout << "Keyname: ";
    getline(in, object.cKeyname);
  }
}

//^^ ^/
void key::inputUsername(istream &in, key &object)
{
  cout << "Username: ";
  getline(in, object.cUsername);

  while (!ValidateInput(object.cUsername))
  {
    cout << "Username: ";
    getline(in, object.cUsername);
  }
}

//^^ inputEmail() ^/
void key::inputEmail(istream &in, key &object)
{
  cout << "Email: ";
  getline(in, object.cEmail);

  while (!ValidateInput(object.cEmail))
  {
    cout << "Email: ";
    getline(in, object.cEmail);
  }
}

//^^ inputPassword() ^/
void key::inputPassword(istream &in, key &object)
{
  cout << "Password: ";

  HideTerminal(); 

  getline(in, object.cPassword);
  cout << endl; 

  while (!ValidateInput(object.cPassword))
  {
    ShowTerminal(); 
    cout << "Password: ";

    HideTerminal();
    getline(in, object.cPassword);
    cout << endl; 
  }

  ShowTerminal(); 
}

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR>
key::key(string destination, string username, string email, string password, integrity integrity) : cKeyname(destination),
                                                                                                    cUsername(username), cEmail(email), cPassword(password), cKeyintegrity(integrity)
{
}

//* <DESTRUCTOR>
//* @public
key::~key()
{
  if (_debugger == _on)
    cout << "<" << this->cKeyname << " key>: destroyed" << endl;
}

//* <SETTERS>
//* @public
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

//* <GETTERS>
//* @public
const string key::getKeyname(void) { return this->cKeyname; }
const string key::getUsername(void) { return this->cUsername; }
const string key::getEmail(void) { return this->cEmail; }
const string key::getPassword(void) { return this->cPassword; }
const integrity key::getKeyintegrity(void) { return this->cKeyintegrity; }

//* <OVERLOADS>
//* @public

//** operator>> */
istream &operator>>(istream &in, key &key)
{

  key.inputKeyname(in, key);
  key.inputUsername(in, key); 
  key.inputEmail(in, key); 
  key.inputPassword(in, key);

  return in;
}

//** operator<< */
ostream &operator<<(ostream &output, const key &object)
{
  output << "<" << object.cKeyname << ">" << endl
         << "\t-    Email:\t" << object.cEmail << endl
         << "\t- Username:\t" << object.cUsername << endl
         << "\t- Password:\t" << object.cPassword << endl
         << "\t- Strength:\t" << object.cKeyintegrity << endl;

  return output;
}

//** operator= */
key &key::operator=(const key &object)
{
  this->cKeyname = object.cKeyname;
  this->cUsername = object.cUsername;
  this->cEmail = object.cEmail;
  this->cPassword = object.cPassword;
  return *this;
}
