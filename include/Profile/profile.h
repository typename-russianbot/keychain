// TODO: class=<profile>
#pragma once
#include "../Keychain/keychain.h"
class profile
{
private:                //!! -Attributes-
    string mUsername;   //* mUsername   | profile's username
    string mPasskey;    //* mPasskey    | profile's passkey

public:         //!! -Functions-
    profile(string username = _none, string passkey = _none);  //^^ -constructor
    ~profile(); //^^ -destructor
};
