#pragma once

//!! -DEPENDENCIES-
#include <iostream>  //! iostream
#include <fstream>   //! fstream
#include <sstream>   //! sstream
#include <cctype>    //! cctype
#include <string.h>  //! string.h
#include <unistd.h>  //! unistd.h
#include <getopt.h>  //! getopt.h
#include <termios.h> //! termios.h

using namespace std;

//^^ <MACROS>
#define _on true               //^ _on
#define _off false             //^ _off
#define _none "<none>"         //^ _none
#define _clear system("clear") //^ _clear
#define _censor "**********"   //^ _censor

//^^ <ENUMS>
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
enum lock //& -lock
{
  locked,  //& 1. <locked>
  unlocked //& 2. <unlocked>
};

//** <GLOBAL FUNCTIONS>
void HideTerminal();                    //* HideTerminal()
void ShowTerminal();                    //* ShowTerminal()
void ValidateInput(char &input);        //* ValidateInput()
bool ValidateFile(ifstream &readfile);  //* ValidateFile()
bool ValidateFile(ofstream &writefile); //* ValidateFile()

//^^ <GLOBAL OVERLOADS>
ostream &operator<<(ostream &output, const integrity &object); //^ -operator<< (enum=INTEGRITY)
ostream &operator<<(ostream &out, const clearance &object);    //^ -operator<< (enum=CLEARANCE)
ostream &operator<<(ostream &out, const lock &object);         //^ -operator<< (enum=LOCK)

//?? <GLOBAL VARIABLES>
extern bool _debugger; //? -DEBUGGER