#include <iostream>
#include "QuitHandler.h"

QuitHandler::QuitHandler(LogInService *logInService, bool mustBeLoggedIn)
        :Handler(logInService)
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
    if(!CheckLogIn())
    {
        return;
    }

    response = "See you later.";
    exit(0);
}


