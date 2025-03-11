#include "../include/Keychain/keychain.h"
//^^ -constructor
keychain::keychain()
    : cKeys(0), cStart(nullptr), cEnd(nullptr)
{
}

//^^ -destructor
keychain::~keychain()
{
}

keynode *keychain::add_key() { return cStart; }
