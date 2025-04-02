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

  //& -TEST LIST-
  //& 1. test save
  //& 2. test wipe
  //& 3. test
  account a("matthew", "hong");
  a.load("jimm");
  a.keyinfo("github");

  a.info();

  if (a.save())
    cout << "account saved" << endl;
  else
    cout << "save failure" << endl;
}

//&& keychain_usage() | @def: displays the usage of keychain
void keychain_usage(void) {
  _clear;

  cout
      << "|--Keychain---------------------------------------------------------|"
      << endl
      << endl
      << " -Usage:" << endl
      << "\t./keychain [-v | --version] , [-h | --help] ," << endl
      << "\t\t   [-i <username> | --init] , [-t | --test]" << endl
      << endl;

  cout
      << " -Commands: " << endl
      << "\tadd\tadds a new key to the current chain" << endl
      << "\trm\tremoves the specified key" << endl
      << "\tmv\tswitches to another keychain account" << endl
      << endl
      << "|-------------------------------------------------------------------|"
      << endl;
}

//&& keychain_swap() | @def:
void keychain_swap();

//&* main() | @def: driver for keychain
int main(int argc, char *argv[]) {

  //? @note: program variables
  account mAccount;
  keychain m;
  m.loadKeychain("jimm");
  int mFlags;
  string mUsername;

  //** @note: FLAG HANDLING
  while ((mFlags = getopt(argc, argv, "vhi:t")) != -1) {

    switch (mFlags) {

    case 'v':
      _clear;
      cout << "Bitchain || <version - 0.0.1>" << endl;
      break;

    case 'h':
      keychain_usage();
      break;

    case 'i':
      mUsername = optarg;

      if (mAccount.load(mUsername))
        cout << "loading: <success>" << endl;
      else
        cout << "loading: <failure>" << endl;

      mAccount.info();

      mAccount.keyadd();

      mAccount.info();

      mAccount.save();

      break;

    case 't':
      account_testing();
      break;

    default:
      keychain_usage();
      break;
    }
  }

  return 0;
}