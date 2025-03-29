//? | @author: Matthew H. | @github: typename-russianbot | ?

#include "../include/Account/account.h"
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
  string username = "jimothy";
  string password = "abcdefghi";

  account a;

  a.loadAccount("jimothy"); 

  a.info(); 

}

//^^ <profile_testing>
void profile_testing(void) {
  cout << "| -Profile | -Testing- |" << endl;
  string username = "jimothy";
  string password = "abcdefghi";
  profile p(username, password);

  p.printProfile();
}

//^^ <keychain_testing>
void keychain_testing(void) {
  cout << "| -Keychain- | -Testing- |" << endl;

  keychain k("jimmy"); 

  key k1("github"), k2("yahoo"), k3("newegg"), k4("ebay"), k5("best-buy"); 

  k.newKey(k1); 
  k.newKey(k2); 
  k.newKey(k3); 
  k.newKey(k4); 
  k.newKey(k5); 

  k.printKeychain(); 

  k.saveKeychain(); 


  //! @note: encryption code
  // xorEncryptDecrypt(filename, key);
  // std::cout << "File encrypted/decrypted successfully!" << std::endl;
}

// && <keychain_usage>
void keychain_usage(void) {}

// ~~ <main program>
int main(int argc, char *argv[]) {
  //?? -PROGRAM VARIABLES-
  int flags;

  //** -FLAG PARSER-
  while ((flags = getopt(argc, argv, "hdar:p:t")) != -1) {
    switch (flags) {
      //^^ 1. <HELP>
    case 'h':
      keychain_usage();
      break;

    //~~ 6. <TESTING> ||
    case 't':
      if (_debugger)
        cout << "flag=TESTING" << endl;

      keychain_testing();
      // profile_testing();
      // account_testing();
      break;

    //** 7. <DEFAULT> ||
    default:
      keychain_usage();
      break;
    }
  }

  return 0;
}