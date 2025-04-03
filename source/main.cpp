//? | @author: Matthew H. | @github: typename-russianbot | ?

#include "../include/Account/account.h"
#include <ostream>
// void xorEncryptDecrypt(const std::string &filename, const std::string &key)
// {
//   std::ifstream inFile(filename, std::ios::binary);
//   if (!inFile)
//   {
//     std::cerr << "Error opening file: " << filename << std::endl;
//     return;
//   }

//   std::string data((std::istreambuf_iterator<char>(inFile)),
//   std::istreambuf_iterator<char>()); inFile.close();

//   // XOR encryption/decryption
//   for (size_t i = 0; i < data.size(); ++i)
//   {
//     data[i] ^= key[i % key.length()];
//   }

//   std::ofstream outFile(filename, std::ios::binary);
//   if (!outFile)
//   {
//     std::cerr << "Error writing to file: " << filename << std::endl;
//     return;
//   }

//   outFile.write(data.c_str(), data.size());
//   outFile.close();
// }

//^^ <account_testing>
void account_testing(void) {
  cout << "| -Account- | -Testing- |" << endl;

  account a("matthew", "hong");
  a.load("jimm");
  a.keyinfo("github");

  a.info();

  if (a.save())
    cout << "account saved" << endl;
  else
    cout << "save failure" << endl;
}

//&* _usage() | @def: displays the usage of keychain
void _usage(void) {
  _clear;

  cout
      << "|--Keychain---------------------------------------------------------|"
      << endl
      << endl
      << " -Usage:" << endl
      << "\t./keychain [-v | version] , [-h | help] ," << endl
      << "\t\t   [-l <username> | load account]" << endl
      << endl;

  cout
      << " -Commands: " << endl
      << "\t[ -i ]\t{ displays loaded account information }" << endl
      << "\t[ -p ]\t{ prints all keys on the loaded account }" << endl
      << "\t[ -a ]\t{ adds a new key to the loaded account }" << endl
      << "\t[ -r ]\t{ removes specified key from the loaded account }" << endl
      << "|-------------------------------------------------------------------|"
      << endl
      << endl;
}

//&* _verify() | @def: checks if the Username in driver is '_none' or not
bool _verify(const string &username) {
  if (username == _none) {
    cerr << "username: <none specified>" << endl << endl;
    exit(1);
    return false;
  }

  return true;
}

//&* main() | @def: driver for keychain
int main(int argc, char *argv[]) {

  //? @note: program variables
  account Account;
  int Flags;
  string Username = _none;

  while ((Flags = getopt(argc, argv, "v h n l: i p f: a r: ")) != -1) {

    //&* @def: Parse flags
    switch (Flags) {

      //^ --version
    case 'v':
      cout << "{ Bitchain || <version - 0.2.1> }" << endl;
      break;

      //^ --help
    case 'h':
      _usage(); //? @def: jump to program usage
      break;

      //^ --new
    case 'n':
      cout << "<under construction>" << endl << endl;
      break;

      //^ --load
    case 'l':
      Username = optarg;

      //? @def: loaded successfully
      if (Account.load(Username))
        cout << "loading: <success>" << endl << endl;

      //! @def: loading failure
      else {
        cerr << "loading: <failed>" << endl << endl;
        exit(1);
      }
      break;

      //^ --info
    case 'i':
      _verify(Username);

      Account.info();
      break;

      //^ --printkeychain
    case 'p':
      _verify(Username);

      //&* @def: access granted
      if (Account.accessProfile()) {
        _clear;
        cout << "permissions: <granted>" << endl << endl;
        Account.printKeychain();
        Account.restrictProfile();
      }

      //!! @def: access denied
      else
        cerr << "permissions: <denied>" << endl << endl;
      break;

      //^ --add
    case 'a':
      _verify(Username);

      //&*
      if (Account.keyadd() && Account.save()) {
        cout << "keyadd: <success>" << endl << endl;
        Account.info();
      }

      //! @def: keyadd failure
      else {
        cout << "keyadd: <failed>" << endl << endl;
        Account.info();
      }
      break;

      //^ --test
    case 't':
      account_testing();
      break;

    default:
      _usage();
      break;
    }
  }

  return 0;
}