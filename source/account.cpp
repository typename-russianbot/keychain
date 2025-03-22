#include "../include/Account/account.h"

//* -[PUBLIC]- *// @publicsection

//* <CONSTRUCTOR> *//
account::account(const string &username)
{
}

//* <DESTRUCTOR> *//
account::~account()
{
}

//* <FUNCTIONS> *//

//** details() */
//* @def:
void account::details()
{
    cout << "|--Account---------------|" << endl
         << endl;

    cout << " - Account: " << endl; //* @note: display current account state

    this->printProfile(); //* @note: print profile data

    cout << " - Keys Found: " << getKeys() << endl //* @note: display the number of keys on this account
         << endl;

    cout << "|------------------------|" << endl;
}

//** add() */
//* @def:
void account::add()
{
    key newKey; //* @note: create a new key object

    cin >> newKey; //* @note: get data for new key

    system("clear");

    this->keyNew(newKey); //* @note: add the key
}
