// TODO: class=<profile>
#pragma once
#include "../Keychain/keychain.h"
class profile
{
private:              //!! -Attributes-
    string mUsername; //* mUsername   | profile's username
    string mPasskey;  //* mPasskey    | profile's passkey

protected:                                                    //!! -Protected Functions-

public:                                                       //!! -Private Functions-
    profile(string username = _none, string passkey = _none); //^^ -constructor
    ~profile();                                               //^^ -destructor
};
