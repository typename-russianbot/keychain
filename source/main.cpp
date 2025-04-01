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
  account a;

  a.swap("jimm");

  a.info();
  a.save();
}

//&& keychain_usage() | @def: displays the usage of keychain
void keychain_usage(void) {
  cout << "Usage:" << endl
       << "./keychain" << endl
       << "\t   [-v | --version] " << endl
       << "\t   [-h | --help]" << endl
       << "\t   [-l | --load <username>]" << endl
       << "\t   [-i | --info <username>]" << endl
       << "\t   [-a | --add]" << endl
       << "\t   [-r | --remove <keyname>]" << endl
       << "\t   [-p | --print <keyname>]" << endl
       << "\t   [-P | --print-keychain]" << endl
       << "\t   [-t | --test]" << endl
       << endl;

  cout << "Commands: " << endl
       << "\tadd\tadds a new key to the current chain" << endl
       << "\trm\tremoves the specified key" << endl
       << "\tmv\tswitches to another keychain account" << endl;
}

//&* main() | @def: main driver for keychain
int main(int argc, char *argv[]) {
  int flags;

  //** @note: FLAG HANDLING
  while ((flags = getopt(argc, argv, "vhl:i:ar:p:Pt")) != -1) {

    switch (flags) {

    case 'v':
      cout << "<version - 0.0.1>" << endl;
      break;

    case 'h':
      keychain_usage();
      break;

    case 'l':
      cout << "<load>" << endl;
      break;

    case 'i':
      cout << "<info>" << endl;
      break;

    case 'a':
      cout << "<add>" << endl;
      break;

    case 'r':
      cout << "<remove>" << endl;
      break;

    case 'p':
      cout << "<print 'keyname'>" << endl;
      break;

    case 'P':
      cout << "<print keychain>" << endl;
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