// TODO class=<main>
#include "../include/Keychain/key.h"
#include "../include/Keychain/keychain.h"
#include "../include/Keychain/keynode.h"

//&& <main-functions>
void testingbay(void) {
  //* test keys
  key key1, key2;

  //* test nodes
  keynode *keynode2 = new keynode(key2);
  keynode *keynode1 = new keynode(key1);

  //* testing bay
  keynode1->set_mNext(keynode2);

  cout << "Keynode1 Data: " << endl;
  cout << keynode1->get_mData() << endl;
  cout << endl;

  keynode1 = keynode1->get_mNext();
  cout << "mNext() data: " << endl;
  cout << keynode1->get_mData() << endl;
}

int main(void) {
  cout << "||==== Keychain ====||==== {v.0.0.1.1} ====||" << endl; //* v0.0.1

  testingbay(); //* testing function

  cout << "||=======================================||" << endl;
  return 0;
}