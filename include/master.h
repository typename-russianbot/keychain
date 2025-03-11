// TODO |--- PROGRAM::KEYCHAIN ---|
#pragma once

//!! -DEPENDENCIES-
#include <iostream> //** iostream
#include <string>   //** string
#include <unistd.h> //** unistd.h
#include <getopt.h> //** getopt.h

using namespace std;
//^^ -MACROS-
#define _on true       //** _on
#define _off false     //** _off
#define _none "<none>" //** _none

//&& -ENUMS-
enum strength
{
  none,     //* <none>        -- no password
  poor,     //* <poor>        -- poor password
  weak,     //* <weak>        -- weak password
  strong,   //* <strong>      -- strong password
  excellent //* <excellent>   -- excellent password
};

//** -GLOBAL FUNCTIONS-
ostream &operator<<(ostream &output, const strength &object); //**  1. operator<< (overload for password strength levels)

//?? -GLOBAL VARIABLES-
extern bool _debugger; //** debugger