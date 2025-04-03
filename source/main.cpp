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

//&& _init() | @def:
void _init() {
  // //?
  // account newAccount;
  // string username, password, verification;
  // char input;

  // //* @def: get username
  // do {
  //   cout << "Username: ";
  //   cin >> username;
  // } while (!ValidateInput(username));

  // cout << username << endl;
  // do {
  //   //* @def: get password
  //   do {
  //     // ShowTerminal();
  //     cout << "Password: ";
  //     // HideTerminal();
  //     cin >> password;
  //   } while (!ValidateInput(password));

  //   //* @def: get verification:
  //   do {
  //     cout << "Re-enter Password: ";
  //     cin >> verification;
  //   } while (!ValidateInput(verification));

  //   //! password mismatch:
  //   if (password != verification) {
  //     cout << "<error>: mismatch detected" << endl;

  //     do {
  //       cout << "Re-attempt? [y/n]: ";
  //       cin >> input;
  //     } while (!ValidateInput(input));
  //   }

  //   //* password == verification
  //   else {
  //     newAccount = new account(username, password);
  //     newAccount.save();
  //   }
  // } while (!ValidateInput(input));
}

//&& _load() | @def:
void _load();

//&* main() | @def: driver for keychain
int main(int argc, char *argv[]) {

  //? @note: program variables
  account Account;
  int Flags;
  string Username;

  //** @note: FLAG HANDLING
  while ((Flags = getopt(argc, argv, "vhil:t")) != -1) {

    switch (Flags) {

    case 'v':
      _clear;
      cout << "Bitchain || <version - 0.0.1>" << endl;
      break;

    case 'h':
      _usage();
      break;

    case 'i':
      _init();
      break;

    case 'l':
      Username = optarg;

      if (Account.load(Username))
        cout << "Loading status: <success>" << endl;
      else
        cout << "Loading status: <failure>" << endl;

      break;

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