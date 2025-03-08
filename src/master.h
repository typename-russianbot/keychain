#pragma once
using namespace std;
//& ---COLOR CODES---
//!
//?
//~
//*
//^
// TODO

//& |--- INCLUDES ---|
#include <iostream> //* iostream
#include <string>   //* string
#include <unistd.h> //* unistd.h

//& |--- MACROS ---|
#define _on true       //* _on
#define _off false     //* _off
#define _null "{null}" //* _null

//& |--- ENUMERATIONS ---|
//^  1. ENUM -- STRENGTH
enum strength
{
    empty,    //* -- represents _null in the case there's no current password
    poor,     //* -- poor password protection
    weak,     //* -- weak password protection
    strong,   //* -- strong password protection
    excellent //* -- excellent password protection
};

//& |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object)
{
    switch (object)
    {
    default:
        output << "{null}";
        break;
    case 1:
        output << "poor";
        break;
    case 2:
        output << "weak";
        break;
    case 3:
        output << "strong";
        break;
    case 4:
        output << "excellent";
        break;
    }

    return output;
}

//& |--- GLOBAL VARIABLES ---|
//^  1. BOOL -- debugger
bool debugger = _off;

//& |--- CLASSES ---|
//^  1. CLASS -- key
class key
{
private:                    //^ -- MEMBERS --
    string keyDestination;  //? 1. key_destination -- unlock destination for key
    string keyUsername;     //? 2. key_username -- username for this key
    string keyEmail;        //? 3. key_email -- email for this key
    string keyPassword;     //? 4. key_password -- password for this key
    strength keyIntegrity;  //? 5. key_integrity -- strength of this key's password
    unsigned int keyAccess; //? 6. key_accessed -- number of times this key has been

public: //^ -- OPERATIONS --
    //* - CONSTRUCTOR -
    key(string destination = _null, string username = _null, string email = _null, string password = _null, strength integrity = empty, int access = 0)
        : keyDestination(destination), keyUsername(username), keyEmail(email), keyPassword(password), keyIntegrity(integrity), keyAccess(access) {}

    //* - FUNCTIONS -
    //? -- 1. setters
    void set_keyDestination(const string &nDestination)
    {
        this->keyDestination = nDestination;
    }
    void set_mUsername(const string &nUsername)
    {
        this->keyUsername = nUsername;
    }
    void set_mEmail(const string &nEmail)
    {
        this->keyEmail = nEmail;
    }
    void set_mPassword(const string &nPassword)
    {
        this->keyPassword = nPassword;
    }
    void set_mIntegrity(const strength &nIntegrity)
    {
        this->keyIntegrity = nIntegrity;
    }
    //? -- 2. getters
    const string get_keyDestination(void)
    {
        return this->keyDestination;
    }
    const string get_keyUsername(void)
    {
        return this->keyUsername;
    }
    const string get_keyEmail(void)
    {
        return this->keyEmail;
    }
    const string get_keyPassword(void)
    {
        return this->keyPassword;
    }
    const strength get_keyIntegrity(void)
    {
        return this->keyIntegrity;
    }
    //? -- 3. is_null (empty)
    bool is_null(void)
    {
        //*
        if (this->keyDestination == _null && this->keyUsername == _null && this->keyEmail == _null && this->keyPassword == _null && this->keyIntegrity == empty && this->keyAccess == 0)
            return true;

        //*
        return false;
    }

    //? -- 4. operator= (hard copy)
    key &operator=(const key &object)
    {
        this->keyDestination = object.keyDestination;
        this->keyUsername = object.keyUsername;
        this->keyEmail = object.keyEmail;
        this->keyPassword = object.keyPassword;
        this->keyAccess = object.keyAccess;
        return *this;
    }

    //? -- 5. operator<< (console out)
    friend ostream &operator<<(ostream &output, const key &object)
    {
        output << "<" << object.keyDestination << " Key>" << endl
               << "\t- Username:\t" << object.keyUsername << endl
               << "\t-    Email:\t" << object.keyEmail << endl
               << "\t- Password:\t" << object.keyPassword << endl
               << "\t- Strength:\t" << object.keyIntegrity << endl;

        return output;
    }

    //* - DESTRUCTOR -
    ~key()
    {
        if (debugger == _on)
            cout << "<" << this->keyDestination << " key>: destroyed" << endl;
    }
};

//^  2. CLASS -- keynode
class keynode
{
private:             //^ -- MEMBERS --
    key m_Data;      //? 1. mData -- key data for current key in chain
    keynode *m_Next; //? 2. mNext -- next key in the chain
    keynode *m_Prev; //? 3. mPrev -- previous key in the chain

public: //^ -- OPERATIONS --
    //* - CONSTRUCTOR -
    keynode(const key &nKey)
    {
        this->set_mData(nKey);
        this->m_Prev = this->m_Next = nullptr;
    }

    //* - FUNCTIONS -
    //? -- 1. getters
    key get_mData(void)
    {
        return m_Data;
    }
    keynode *get_mNext(void)
    {
        return this->m_Next;
    }
    keynode *get_mPrev(void)
    {
        return this->m_Prev;
    }

    //? -- 2. setters
    void set_mData(const key &nData)
    {
        this->m_Data = nData;
    }
    void set_mNext(keynode *&nNode)
    {
        this->m_Next = nNode;
    }
    void set_mPrev(keynode *&nNode)
    {
        this->m_Prev = nNode;
    }

    //* - DESTRUCTOR -
    ~keynode(void)
    {
        if (debugger == _on)
            cout << "deleting node" << endl;
    }
};

//^  3. CLASS -- keychain
//^
//^ NOTES: using a circular linked list, to best represent our keychain
//^ NOTES: each individual keynode can access the left & right nodes (prev & next)
class keychain
{
private:              //^ -- MEMBERS --
    int m_KeyCounter; //* # of keys in the keychain
    keynode *m_Start; //* start of keychain
    keynode *m_End;   //* end of keychain

public: //^ -- OPERATIONS --
    //* - CONSTRUCTOR -
    keychain() : m_KeyCounter(0), m_Start(nullptr), m_End(nullptr) {}

    //* - FUNCTIONS -
    //? 1. display()
    //? 2. is_empty()
    //? 3.

    //* - DESTRUCTOR -
};