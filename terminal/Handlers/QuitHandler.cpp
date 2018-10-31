#include <iostream>
#include "QuitHandler.h"
#include "../Helpers/CommunicationHelper.h"

QuitHandler::QuitHandler(LogInService *logInService, bool mustBeLoggedIn)
        :Handler(logInService)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool QuitHandler::CanHandle(const Command *com)
{
    response = Response();

    if(com->value == "quit")
    {
        command = com;
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

    response = Response("See you later...", Quit);
}
