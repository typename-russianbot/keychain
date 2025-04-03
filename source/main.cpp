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

//&& _usage() | @def: displays the usage of keychain
void _usage(void) {
  _clear;

  cout
      << "|--Keychain---------------------------------------------------------|"
      << endl
      << endl
      << " -Usage:" << endl
      << "\t./keychain [-v | --version] , [-h | --help] ," << endl
      << "\t\t   [-i | --init] , [-t | --test] , " << endl
      << "\t\t   [-l <username> | --load]" << endl;

  cout
      << " -Commands: " << endl
      << "\tadd\tadds a new key to the current chain" << endl
      << "\trm\tremoves the specified key" << endl
      << "\tmv\tswitches to another keychain account" << endl
      << endl
      << "|-------------------------------------------------------------------|"
      << endl
      << endl;
}

//&& _load() | @def:
void _load();

//&* main() | @def: driver for keychain
int main(int argc, char *argv[]) {

  //? @note: program variables
  account Account;
  int Flags;
  string Username = _none;

  //** @note: FLAG HANDLING
  while ((Flags = getopt(argc, argv, "vhl:iat")) != -1) {

    switch (Flags) {
      //^ --version
    case 'v':
      cout << "Bitchain || <version - 0.0.1>" << endl;
      break;

      //^ --help
    case 'h':
      _usage();
      break;

    case 'n':
      cout << "<under construction>" << endl << endl;
      _usage();
      break;

      //^ --load
    case 'l':
      Username = optarg;

      //? @def: loading successful
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
      Account.info();
      break;

      //^ --add
    case 'a':
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