#include "master.h"

//& |--- MAIN ---|
int main(void)
{
    if (debugger == _off)
    {
        system("clear");
    }

    cout << "||==== Keychain ====||==== {v.0.0.1} ====||" << endl; //* v0.0.1
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
    cout << "||=======================================||" << endl; //* end of keychain
    return 0;
}