#include "../include/Keychain/key.h"
//!! <master>
struct termios oldt, newt; //?? termios struct to edit terminal settings
bool _debugger = _off;     //?? _debugger

ostream &operator<<(ostream &output, const integrity &object) //** 1. operator<< (enum==STRENGTH)
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
ostream &operator<<(ostream &out, const clearance &object) //** 2. operator<< (enum==ACCESS)
{
  switch (object)
  {
  default: //* by default, access to most info should be restricted
    cout << "<Restricted>";
    break;

  case 1:
    cout << "<Granted>";
    break;
  }

  return out;
}
void HideTerminal() //** 3. HideTerminal
{
  //& Get terminal attributes
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  //&s Disable echo
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}
void ShowTerminal() //** 4. ShowTerminal
{
  //& Restore terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  cout << endl;
}

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
