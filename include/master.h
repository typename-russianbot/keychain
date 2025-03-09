//TODO |--- PROGRAM::KEYCHAIN ---|
#pragma once
using namespace std;

//!! |--- DEPENDENCIES ---|
#include <iostream>
#include <string>   //* string
#include <unistd.h> //* unistd.h

//~~ |--- MACROS ---|
#define _on true       //* _on
#define _off false     //* _off
#define _null "{null}" //* _null

//& |--- ENUMERATIONS ---|
enum strength //& - strength
{
  empty,    //* -- represents _null in the case there's no current password
  poor,     //* -- poor password protection
  weak,     //* -- weak password protection
  strong,   //* -- strong password protection
  excellent //* -- excellent password protection
};

//?? |--- GLOBAL VARIABLES ---|
extern bool debugger;

//** */ |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object);
