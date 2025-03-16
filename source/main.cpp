#include "../include/Account/account.h"
// ^^ <keychain_testing>
void keychain_testing(void)
{
  cout << "| -Keychain- | -Testing- |" << endl
       << endl;

  account myAccount("mjh2001", "password");

  myAccount.details(); 

  
}

// && <keychain_usage>
void keychain_usage(void)
{
  //** -FLAG LIST-
  //^ -h || displays all program flags & their purpose
  //* -d || activates debugger
  //! -a || adds a new key to the chain
  //& -r: || removes a specified key from the chain
  //? -p: || prints a specified key to the command line
  //~ -t || enter testing bench

  cout << "| -Keychain- | -Usage- |" << endl
       << endl
       << "| Program Flags: |" << endl
       << "\t-h | HELP -- " << endl
       << "\t-p | PROFILE INTERFACE --" << endl
       << "\t-t | TESTING INTERFACE --" << endl
       << "\t-h | description" << endl;

  //* concept flags:
  //* 1. -c : create a new account
  //* 2. -r : remove a pre-existing account
  //* 3. -p : print an account's keychain
  //* 4. -
}

// ~~ <main program>
int main(int argc, char *argv[])
{
  //?? -PROGRAM VARIABLES-
  int flags;

  //** -FLAG PARSER-
  while ((flags = getopt(argc, argv, "hdar:p:t")) != -1)
  {
    switch (flags)
    {
      //^^ 1. <HELP>
    case 'h':
      keychain_usage();
      break;

    //~~ 6. <TESTING> ||
    case 't':
      if (_debugger)
        cout << "flag=TESTING" << endl;

      keychain_testing();
      break;

    //** 7. <DEFAULT> ||
    default:
      keychain_usage();
      break;
    }
  }

  return 0;
}