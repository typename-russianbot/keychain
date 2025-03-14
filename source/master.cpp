#include "../include/master.h"

//!! <master>
//? -[GLOBAL VARIABLES]- ?
struct termios oldt, newt; //?? termios struct to edit terminal settings
bool _debugger = _off;     //?? _debugger

//* -[GLOBAL FUNCTIONS]- *

//* HideTerminal
//*
void HideTerminal()
{
    //& Get terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    //&s Disable echo
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

//* ShowTerminal
//*
void ShowTerminal()
{
    //& Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    cout << endl;
}

//* ValidateInput
//*
void ValidateInput(char &input)
{
    while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
    {
        cout << "Request Permission? [y/n]: ";
        cin >> input;
    }
    cout << endl;
}

//* ValidateFile
//*
bool ValidateFile(ifstream &readfile)
{
    if (!readfile) //! file wasn't opened, return false
        return false;

    return true; //* file opened, return true
}
bool ValidateFile(ofstream &writefile)
{
    if (!writefile) //! file wasn't opened, return false
        return false;

    return true; //* file opened, return true
}

//! -[GLOBAL OVERLOADS]- !

//! operator<< | [enum==integrity]
ostream &operator<<(ostream &output, const integrity &object)
{
    switch (object)
    {
    default:
        output << "<none>";
        break;
    case 1:
        output << "<poor>";
        break;
    case 2:
        output << "<weak>";
        break;
    case 3:
        output << "<strong>";
        break;
    case 4:
        output << "<excellent>";
        break;
    }

    return output;
}

//! operator<< | [enum==clearance]
ostream &operator<<(ostream &out, const clearance &object)
{
    switch (object)
    {
    default: //* by default, access to most info should be restricted
        cout << "<Restricted>";
        break;

    case 1:
        cout << "<Granted>";
        break;
    }

    return out;
}