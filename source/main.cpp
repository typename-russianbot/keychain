//? | @author: Matthew H. | @github: typename-russianbot | ?

#include "../include/Account/account.h"
#include <bits/getopt_core.h>
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

//&* _usage() | @def: displays the usage of keychain
void _usage(void) {
  _clear;

  cout << "|--Keychain---------------------------------------------------------"
          "----------|"
       << endl
       << endl
       << " -Usage:" << endl
       << "\t./keychain <command>" << endl
       << endl;

  cout << " -Commands: " << endl
       << "  [ -v ] || { displays program version }" << endl
       << "  [ -h ] || { displays program usage }" << endl
       << "  [ -n ] || { creates a new account }" << endl
       << "  [ -l <username> ] || { loads designated account }" << endl
       << "  [ -d <username> ] || { deletes designated account }" << endl
       << "  [ -f <keyname> ]  || { searches designated key }" << endl
       << "  [ -r <keyname> ]  || { removes designated key }" << endl
       << "  [ -p ] || { prints all keys }" << endl
       << "  [ -a ] || { adds a new key }" << endl
       << endl
       << "|-------------------------------------------------------------------"
          "----------|"
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

  account Account;
  string Username = _none;
  string Keyname;
  int Flags;

  while ((Flags = getopt(argc, argv, "v h n l: d: p f: a r: ")) != -1) {

    switch (Flags) {

      //^ --version
    case 'v':
      cout << "{ Bitchain || <version - 1.0.1> }" << endl;
      break;

      //^ --help
    case 'h':
      _usage();
      break;

      //^ --new
    case 'n':
      cout << "<under construction>" << endl << endl;
      
      //? should prompt for username, password
      //? should then set the username/owner & the password as the current account variables
      //? save the inputted account data to profiles.txt & create a 'username'.txt file

      break;

      //^ --load
    case 'l':
      Username = optarg;

      if (!Account.load(Username)) {
        cerr << "<error>: account loading failure" << endl << endl;
        exit(1);
      } else {
        cout << "<success>: account loaded" << endl << endl;
        Account.info();
      }

      break;

    //^ --delete
    case 'd':
      Username = optarg;

      if (Account.searchProfile(Username) && Account.wipe(Username))
        cout << "<success>: " << Username << " deleted" << endl;
      else
        cout << "<error>: account deletion failure" << endl;

      break;

      //^ --print-keys
    case 'p':
      _verify(Username);

      if (Account.getAccess()) {
        _clear;
        cout << "permissions: <granted>" << endl << endl;
        Account.printKeychain();
        Account.setRestricted();
      } else
        cerr << "permissions: <denied>" << endl << endl;

      break;

      //^ --find
    case 'f':
      _verify(Username);

      Keyname = optarg;

      if (Account.searchKey(Keyname) && Account.getAccess()) {
        _clear;
        cout << Keyname << ": <found>" << endl << endl;
        Account.keyinfo(Keyname);
      } else {
        _clear;
        cout << Keyname << ": <not found>" << endl << endl;
      }

      break;

      //^ --add
    case 'a':
      _verify(Username);

      if (Account.keyadd() && Account.save()) {
        cout << "adding key: <success>" << endl << endl;
        Account.info();
      } else {
        cout << "adding key: <failed>" << endl << endl;
        Account.info();
      }

      break;

      //^ --remove
    case 'r':
      _verify(Username);

      Keyname = optarg;

      if (Account.searchKey(Keyname) && Account.keyremove(Keyname)) {
        cout << "deleting key: <success>" << endl << endl;
        Account.info();
        Account.save();
      } else {
        cout << "deleting key: <failed>" << endl << endl;
        Account.info();
      }

      break;

    default:
      _usage();
      break;
    }
  }

  return 0;
}