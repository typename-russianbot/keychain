//? | @author: Matthew H. | @github: typename-russianbot | ?
#include "../include/Account/account.h"

// ^^ <keychain_testing>
void keychain_testing(void)
{
  cout << "| -Keychain- | -Testing- |" << endl;

  profile p;
  cout << p << endl;

  p.printProfile();

  if (p.loadProfile("matthew"))
    cout << "<SUCCESS> - profile loaded" << endl;

  cout << p << endl;

  if (p.accessProfile())
    cout << "<SUCCESS> - profile accessed" << endl;

  cout << p << endl;

  if (p.restrictProfile())
    cout << "<SUCCESS> - profile restricted" << endl;

  cout << p << endl;
}

// && <keychain_usage>
void keychain_usage(void)
{
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