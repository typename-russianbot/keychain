#include "../include/Keychain/keychain.h"
#include "../include/Profile/profile.h"
// ^^ <keychain_testing>
void keychain_testing(void)
{
  cout << "| -Keychain- | -Testing- |" << endl
       << endl;

  //^ proto keychain
  keychain myKeychain("mjhsnake2001!!");

  //^ prototype profile:
  profile myProfile("username", "password");

  myProfile.save(); 
  

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
       << "Program Flags:" << endl
       << "\t-h\t| displays all program flags & their purpose" << endl
       << "\t-d\t| activates debug mode" << endl
       << "\t-t\t| runs test build of keychain" << endl
       << "\t-a\t| adds a new key onto the keychain" << endl
       << "\t-r\t| removes a key from the keychain" << endl
       << "\t-p\t| searches for a certain key & displays it" << endl;
}

// TODO <main>
int main(int argc, char *argv[])
{
  //** -PROGRAM VARIABLES-
  int flags;

  //!! -FLAG PARSER-
  while ((flags = getopt(argc, argv, "hdar:p:t")) != -1)
  {
    switch (flags)
    {
      //^^ 1. <HELP> ||
    case 'h':
      if (_debugger)
        cout << "flag=HELP" << endl;

      keychain_usage();
      break;

      //** 2. <DEBUGGER> ||
    case 'd':
      _debugger = _on;
      cout << "_debugger=ON" << endl;
      break;

      //!! 3. <ADD> ||
    case 'a':
      if (_debugger)
        cout << "flag=ADD" << endl;
      break;

      //&& 4. <REMOVE> ||
    case 'r':
      if (_debugger)
        cout << "flag=REMOVE" << endl;
      break;

      //?? 5. <DISPLAY> ||
    case 'p':
      if (_debugger)
        cout << "flag=DISPLAY" << endl;
      break;

    //~~ 6. <TESTING> ||
    case 't':
      if (_debugger)
        cout << "flag=TESTING" << endl;

      keychain_testing();
      break;

    //** 7. <DEFAULT> ||
    default:
      if (_debugger)
        cout << "flag=DEFAULT" << endl;

      keychain_usage();
      break;
    }
  }

  // string line;
  // cout << "input: ";
  // getline(cin, line);

  return 0;
}