#pragma once
using namespace std;

//& |--- DEPENDENCIES ---|
#include <iostream>
#include <string>   //* string
#include <unistd.h> //* unistd.h

//& |--- MACROS ---|
#define _on true       //* _on
#define _off false     //* _off
#define _null "{null}" //* _null

//& |--- ENUMERATIONS ---|
//^  1. ENUM -- STRENGTH
enum strength {
  empty,    //* -- represents _null in the case there's no current password
  poor,     //* -- poor password protection
  weak,     //* -- weak password protection
  strong,   //* -- strong password protection
  excellent //* -- excellent password protection
};

//& |--- GLOBAL FUNCTIONS ---|
//^  1. operator<< (overload for password strength levels)
ostream &operator<<(ostream &output, const strength &object) {
  switch (object) {
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

//& |--- KEYCHAIN ---|
#include "Keychain/key.h"
#include "Keychain/keynode.h"
#include "Keychain/keychain.h"

//& |--- ACCOUNT ---|
