#pragma once

//!! -DEPENDENCIES-
#include <iostream>  //! iostream
#include <cctype>    //! cctype
#include <string.h>  //! string.h
#include <unistd.h>  //! unistd.h
#include <getopt.h>  //! getopt.h
#include <termios.h> //! termios.h

//~~ -NAMESPACES-
using namespace std; 

//^^ -MACROS-
#define _on true               //^ _on
#define _off false             //^ _off
#define _none "<none>"         //^ _none
#define _clear system("clear") //^ _clear

//&& -ENUMS-
enum integrity //& -integrity
{
  none,     //& 1. <none>        -- no password
  poor,     //& 2. <poor>        -- poor password
  weak,     //& 3. <weak>        -- weak password
  strong,   //& 4. <strong>      -- strong password
  excellent //& 5. <excellent>   -- excellent password
};
enum clearance //& -clearance
{
  restricted, //& 1. <restricted>    -- access restricted
  permitted   //& 2. <permitted>     -- access permitted
};

//** -GLOBAL FUNCTIONS-
ostream &operator<<(ostream &output, const integrity &object); //* -operator<< (enum=INTEGRITY)
ostream &operator<<(ostream &out, const clearance &object);    //* -operator<< (enum=CLEARANCE)
void HideTerminal();                                           //* -HideTerminal()    | alters shell to hide input
void ShowTerminal();                                           //* -ShowTerminal()    | returns shell to original state
void ValidateInput(char &input);                               //* -ValidateInput()   |

//?? -GLOBAL VARS-
extern bool _debugger; //? -debugger