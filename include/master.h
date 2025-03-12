// TODO -PROGRAM <KEYCHAIN>
#pragma once

//!! -DEPENDENCIES-
#include <iostream>  //! iostream
#include <string.h>  //! string.h
#include <unistd.h>  //! unistd.h
#include <getopt.h>  //! getopt.h
#include <termios.h> //! termios.h

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
  restricted, //& <restricted>    -- access restricted
  permitted   //& <permitted>     -- access permitted
};

//** -GLOBAL FUNCTIONS-
ostream &operator<<(ostream &output, const integrity &object); //* -operator<< (enum=INTEGRITY)
ostream &operator<<(ostream &out, const clearance &object);    //* -operator<< (enum=CLEARANCE)
void HideTerminal();                                           //* HideTerminal
void ShowTerminal();                                           //* ShowTerminal

//?? -GLOBAL VARS-
extern bool _debugger; //? -debugger