#include "../include/Keychain/key.h"
#include "../include/Keychain/keychain.h"
#include "../include/Keychain/keynode.h"

// ^^ <test_bench>
void test_bench(void)
{
  if (_debugger)
    cout << "<debugger activated>" << endl;

  keychain tester;
  cout << tester.add_key() << endl; 
}

// && <keychain>
void keychain(void)
{
  //&& -KEYCHAIN-
  cout << "||==== Keychain ====||==== <v.0.0.2> ====||"
       << endl
       << endl;

  cout << "||=======================================||"
       << endl;
}

// TODO <main>
int main(int argc, char *argv[])
{
  //** -PROGRAM VARIABLES-
  int flags;
  //** -FLAG LIST-
  //^ -h || displays all program flags & their purpose
  //* -d || activates debugger
  //! -a || adds a new key to the chain
  //& -r: || removes a specified key from the chain
  //? -p: || prints a specified key to the command line
  //~ -t || enter testing bench

  //!! -FLAG PARSER-
  while ((flags = getopt(argc, argv, "hdar:p:t")) != -1)
  {
    switch (flags) //!++ flag handling goes here
    {
      //^^ 1. <HELP> ||
    case 'h':
      if (_debugger)
        cout << "flag=HELP" << endl;
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
      test_bench();
      break;

    default:
      cout << "default=HELP" << endl;
      break;
    }
  }

  return 0;
}