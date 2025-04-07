//? | @author: Matthew H. | @github: typename-russianbot | ?

#include "../include/Account/account.h"
// #include <bits/getopt_core.h>
// #include <ostream>
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

//&* program_usage() | @def: displays the usage of keychain
void program_usage(void) {

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
       << "  [ -p <keyname> ]  || { prints designated key }" << endl
       << "  [ -r <keyname> ]  || { removes designated key }" << endl
       << "  [ -P ] || { prints all keys }" << endl
       << "  [ -a ] || { adds a new key }" << endl
       << endl
       << "|-------------------------------------------------------------------"
          "----------|"
       << endl
       << endl;
}

//&* main() | @def: driver for keychain
int main(int argc, char *argv[]) {

  account Account;
  string Username = _none, Password = _none, Verification = _none,
         Keyname = _none;
  int Flags;

  while ((Flags = getopt(argc, argv, "v h n l: d: P p: a r: ")) != -1) {

    switch (Flags) {

      //^ --version
    case 'v':
      cout << "{ Bitchain || <version - 1.5> }" << endl;
      break;

      //^ --help
    case 'h':
      program_usage();
      break;

      //^ --new
    case 'n':
      Username = _none;
      Password = _none;
      Verification = _none;

      AccountInput(Username, Password, Verification);

      if (Account.init(Username, Password) && Account.save()) {
        _clear;
        cout << "<success>: Account " << Username << " created" << endl << endl;
        Account.info();
      } else {
        cout << "<error>: Account " << Username << " not created" << endl
             << endl;
      }
      break;

      //^ --load
    case 'l':
      Username = optarg;

      if (Account.load(Username)) {
        cout << "<success>: account loaded" << endl << endl;
        Account.info();
      } else {
        cerr << "<error>: account loading failure" << endl << endl;
        cout << "| -Known Profiles- | " << endl << endl;  
        Account.getProfiles();
        exit(1);
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
    case 'P':
      ValidateUsername(Username);

      if (Account.getAccess()) {
        _clear;
        cout << "<success>: access granted" << endl << endl;
        Account.printKeychain();
        Account.setRestricted();
      } else
        cerr << "<error>: access denied" << endl << endl;

      break;

      //^ --print-key
    case 'p':
      ValidateUsername(Username);

      Keyname = optarg;

      if (Account.searchKey(Keyname) && Account.getAccess()) {
        _clear;
        cout << "<success>: " << Keyname << " found" << endl << endl;
        Account.keyinfo(Keyname);
      } else {
        _clear;
        cout << "<error>: " << Keyname << " not found" << endl << endl;
      }

      break;

      //^ --add
    case 'a':
      ValidateUsername(Username);

      if (Account.keyadd() && Account.save()) {
        cout << "<success>: added key" << endl << endl;
        Account.info();
      } else {
        cout << "<error>: key wasn't added" << endl << endl;
        Account.info();
      }

      break;

      //^ --remove
    case 'r':
      ValidateUsername(Username);

      Keyname = optarg;

      if (Account.searchKey(Keyname) && Account.keyremove(Keyname)) {
        cout << "<success>: deleted key '" << Keyname << "'" << endl << endl;
        Account.info();
        Account.save();
      } else {
        cout << "<error>: failed to delete key '" << Keyname << "'" << endl
             << endl;
        Account.info();
      }

      break;

    default:
      program_usage();
      break;
    }
  }

  return 0;
}