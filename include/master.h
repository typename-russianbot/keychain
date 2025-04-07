//? | @author: Matthew H. | @github: typename-russianbot | ?

#pragma once

//!! <DEPENDENCIES>
#include <cctype>     //! cctype
#include <filesystem> //! filesystem
#include <fstream>    //! fstream
#include <getopt.h>   //! getopt.h
#include <iostream>   //! iostream
#include <sstream>    //! sstream
#include <string.h>   //! string.h
#include <termios.h>  //! termios.h
#include <unistd.h>   //! unistd.h

//^^ <MACROS>
using namespace std;
#define _on true               //^ _on
#define _off false             //^ _off
#define _none "none"           //^ _none
#define _clear system("clear") //^ _clear
#define _censor "**********"   //^ _censor

//^^ <ENUMS>

//^^ @enum: <INTEGRITY> ^/
enum integrity {
  none,     //& 1. <none>        -- no password
  poor,     //& 2. <poor>        -- poor password
  weak,     //& 3. <weak>        -- weak password
  strong,   //& 4. <strong>      -- strong password
  excellent //& 5. <excellent>   -- excellent password
};

//^^ @enum: <CLEARANCE> ^/
enum clearance {
  restricted,  //& 1. <restricted>    -- access restricted
  unrestricted //& 2. <unrestricted>     -- access permitted
};

//^^ @enum: <LOCK> ^/
enum lock {
  locked,  //& 1. <locked>
  unlocked //& 2. <unlocked>
};

//** <GLOBAL FUNCTIONS>
void HideTerminal(void); //* HideTerminal() @param: void
void ShowTerminal(void); //* ShowTerminal() @param: void

bool ValidateInput(char &input);   //* ValidateInput() @param: char
bool ValidateInput(string &input); //* ValidateInput() @param: string

bool ValidateFile(ifstream &readfile);  //* ValidateFile() @param: ifstream
bool ValidateFile(ofstream &writefile); //* ValidateFile() @param: ofstream

bool ValidateUsername(const string &username);
void AccountInput(string &username, string &password, string &verification);

//^^ <GLOBAL OVERLOADS>
ostream &operator<<(ostream &out,
                    const integrity &object); //^ -operator<< | @enum=INTEGRITY
ostream &operator<<(ostream &out,
                    const clearance &object); //^ -operator<< | @enum=CLEARANCE
ostream &operator<<(ostream &out,
                    const lock &object); //^ -operator<< | @enum=LOCK

//?? <GLOBAL VARIABLES>
extern bool _debugger; //? -DEBUGGER