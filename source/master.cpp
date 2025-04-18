#include "../include/master.h"

//! -[MASTER]- !

//? <GLOBAL VARIABLES>

//?? termios structs ?/
//? @def: edit terminal state
struct termios oldt, newt;

//?? debugger ?/
//? @def: displays data to terminal when enabled
bool _debugger = _off;

//* <GLOBAL FUNCTIONS>

//** HideTerminal() */
void HideTerminal() {
  //& Get terminal attributes
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  //&s Disable echo
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

//** ShowTerminal() */
void ShowTerminal() {
  //& Restore terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  cout << endl;
}

//** ValidateInput() */
//* @def: prompts user for
bool ValidateInput(char &input) {
  if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
    return false;
  }

  return true;
}

//** ValidateInput() */
//* @def: forbidden characters - \ / : * ? " < > |
bool ValidateInput(string &input) {
  bool flag = true;

  //! detect for illegal characters
  for (char character : input) {
    switch (character) {
    case ' ':
      flag = false;
      break;
    case ',':
      flag = false;
      break;
    case '\'':
      flag = false;
      break;
    case '/':
      flag = false;
      break;
    case ':':
      flag = false;
      break;
    case '*':
      flag = false;
      break;
    case '?':
      flag = false;
      break;
    case '"':
      flag = false;
      break;
    case '<':
      flag = false;
      break;
    case '>':
      flag = false;
      break;
    case '|':
      flag = false;
      break;
    }
  }

  if (flag == false) {
    cout << "<ERROR> - Illegal character detected" << endl;

    input = _none;
  }

  return flag;
}

//** ValidateFile() */
//* @param: ifstream
bool ValidateFile(ifstream &readfile) {
  if (!readfile) //! file wasn't opened, return false
    return false;

  return true; //* file opened, return true
}

//* @param: ofstream
bool ValidateFile(ofstream &writefile) {
  if (!writefile) //! file wasn't opened, return false
    return false;

  return true; //* file opened, return true
}

//** username_verify()
//* @def: checks if Username is _none or not
bool ValidateUsername(const string &username) {

  if (username == _none) {
    cerr << "username: <none specified>" << endl << endl;
    exit(1);
    return false;
  }

  return true;
}

//** account_input()
//* @def: prompts for username, password input
void AccountInput(string &username, string &password, string &verification) {

  do {
    cout << "Username: ";
    cin >> username;
  } while (!ValidateInput(username));

  //* get password
  do {
    cout << "Password: ";

    HideTerminal();
    cin >> password;
    ShowTerminal();
  } while (!ValidateInput(password));

  //* verify
  do {

    cout << "Re-enter Password: ";

    HideTerminal();
    cin >> verification;
    ShowTerminal();
  } while (!ValidateInput(verification));

  return;
}

//^ <GLOBAL OVERLOADS>

//^^ operator<< | (enum=INTEGRITY) ^/
ostream &operator<<(ostream &out, const integrity &object) {
  switch (object) {
  default:
    out << "<none>";
    break;
  case 1:
    out << "<poor>";
    break;
  case 2:
    out << "<weak>";
    break;
  case 3:
    out << "<strong>";
    break;
  case 4:
    out << "<excellent>";
    break;
  }

  return out;
}

//^^ operator<< | (enum=CLEARANCE) ^/
ostream &operator<<(ostream &out, const clearance &object) {
  switch (object) {
  default: //* by default, access to most info should be restricted
    out << "<Restricted>";
    break;

  case 1:
    out << "<Unrestricted>";
    break;
  }

  return out;
}

//^^ operator<< | (enum=LOCK) ^/
ostream &operator<<(ostream &out, const lock &object) {
  switch (object) {
  default:
    out << "<Locked>";
    break;

  case 1:
    out << "<Unlocked>";
    break;
  }

  return out;
}