#include <iostream>
#include "QuitHandler.h"

QuitHandler::QuitHandler()
{
    this->mustBeLoggedIn = false;
}

QuitHandler::QuitHandler(bool mustBeLoggedIn)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool QuitHandler::CanHandle(const Command *com)
{
    response = "";

    if(com->value == "quit")
    {
        command = com;
        response = "da";
        return true;
    }

    return false;
}

void QuitHandler::Handle()
{
    response = "See you later.";
    exit(0);
}


