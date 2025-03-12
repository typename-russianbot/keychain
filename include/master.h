// TODO -PROGRAM <KEYCHAIN>
#pragma once

//!! -DEPENDENCIES-
#include <iostream> //! iostream
#include <string>   //! string
#include <unistd.h> //! unistd.h
#include <getopt.h> //! getopt.h

//~~ -NAMESPACES-
using namespace std;

//^^ -MACROS-
#define _on true       //^ -on
#define _off false     //^ -off
#define _none "<none>" //^ -none

//&& -ENUMS-
enum integrity //& -integrity
{
  none,     //& <none>        -- no password
  poor,     //& <poor>        -- poor password
  weak,     //& <weak>        -- weak password
  strong,   //& <strong>      -- strong password
  excellent //& <excellent>   -- excellent password
};
enum clearance //& -clearance
{
  restricted, //& <restricted>    -- all access restricted | default clearance state
  permitted   //& <permitted>     -- complete access | when password for account is given
};

//** -GLOBAL FUNCTIONS-
ostream &operator<<(ostream &output, const integrity &object); //* -operator<< (enum=INTEGRITY)
ostream &operator<<(ostream &out, const clearance &object);    //* -operator<< (enum=CLEARANCE)

//?? -GLOBAL VARS-
extern bool _debugger; //? -debugger