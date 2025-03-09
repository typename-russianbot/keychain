#include "../include/Keychain/keychain.h"

keychain::keychain()
    : cCounter(0), cStart(nullptr), cEnd(nullptr) //^^ -construct
{
    cStart->setPrev(cEnd); 
    cStart->setNext(nullptr); 


    cout << cStart->getNext();
}

keychain::~keychain() //^^ -destruct
{}
