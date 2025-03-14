#include "../include/Profile/profile.h"

//^ -[PROTECTED]- ^

//^ -getters-
const string profile::getUsername()
{
    return this->cUsername; 
}
const string profile::getPasskey()
{
    return this->cPassword; 
}

//^ -setters-
void profile::setUsername(const string &username)
{
    this->cUsername = username; 
}
void profile::setPassword(const string &password)
{
    this->cPassword = password; 
}

//* -[PUBLIC]- *

//* -constructor-
profile::profile(string username, string passkey) {}

//* -destructor-
profile::~profile()
{
    
}