#include "../include/Keychain/key.h"
#include "../include/Keychain/keychain.h"
#include "../include/Keychain/keynode.h"

void TEST_BENCH(void) // TODO <TEST-BENCH>
{

  key keyA;
  if (keyA.is_null())
  {
    cout << "keyA={null}" << endl;
  }

  key keyB("github", "typename-russianbot", "axix01@yahoo.com");

  cout << "keyB=" << endl
       << keyB << endl;
}

int main(void) // TODO <main>
{
  cout << "||==== Keychain ====||==== {v.0.0.1.1} ====||"
       << endl; //^^ -v.0.0.1.1

  TEST_BENCH(); //^^ -TESTING BENCH

  cout << "||=========================================||"
       << endl; //^^ -end_of_program
  return 0;
}