#include "../include/master.h"

//! -[MASTER]- !

//? <GLOBAL VARIABLES>

//?? termios structs ?/
//? @def: edit terminal state
struct termios oldt, newt;

//?? debugger ?/
//? @def: displays data to terminal when enabled
bool _debugger = _off;

//* <GLOBAL FUNCTIONS>

//** HideTerminal() */
void HideTerminal()
{
    //& Get terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    //&s Disable echo
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

//** ShowTerminal() */
void ShowTerminal()
{
    //& Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    cout << endl;
}

//** ValidateInput() */
//* @param: char
void ValidateInput(char &input)
{
    while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
    {
        cout << "Request Permission? [y/n]: ";
        cin >> input;
    }
    cout << endl;
}

//** ValidateInput() */
//* @param: string
bool ValidateInput(string &input)
{
    if(input == "")
        input = _none; 

    //! detect for illegal characters
    for (char character : input)
    {
        switch (character)
        {
        case ' ':
            cout << "<ERROR>: use '-' or '_'" << endl;
            return false; 
            break;

        case ',':
            cout << "<ERROR>: illegal character detected" << endl;
            return false; 
            break;

        }
    }

    return true; //* input valid
}

//** ValidateFile() */
//* @param: ifstream
bool ValidateFile(ifstream &readfile)
{
    if (!readfile) //! file wasn't opened, return false
        return false;

    return true; //* file opened, return true
}

//** ValidateFile() */
//* @param: ofstream
bool ValidateFile(ofstream &writefile)
{
    if (!writefile) //! file wasn't opened, return false
        return false;

    return true; //* file opened, return true
}

//^ <GLOBAL OVERLOADS>

//^^ operator<< | (enum=INTEGRITY) ^/
ostream &operator<<(ostream &out, const integrity &object)
{
    switch (object)
    {
    default:
        out << "<none>";
        break;
    case 1:
        out << "<poor>";
        break;
    case 2:
        out << "<weak>";
        break;
    case 3:
        out << "<strong>";
        break;
    case 4:
        out << "<excellent>";
        break;
    }

    return out;
}

//^^ operator<< | (enum=CLEARANCE) ^/
ostream &operator<<(ostream &out, const clearance &object)
{
    switch (object)
    {
    default: //* by default, access to most info should be restricted
        out << "<Restricted>";
        break;

    case 1:
        out << "<Granted>";
        break;
    }

    return out;
}

//^^ operator<< | (enum=LOCK) ^/
ostream &operator<<(ostream &out, const lock &object)
{
    switch (object)
    {
    default:
        out << "<Locked>";
        break;

    case 1:
        out << "<Unlocked>";
        break;
    }

    return out;
}