#include <iostream>
#include "QuitHandler.h"
#include "../Helpers/CommunicationHelper.h"

QuitHandler::QuitHandler(LogInService *logInService, bool mustBeLoggedIn, int parentSocket, int childSocket)
        :Handler(logInService)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
    this->parentSocket = parentSocket;
    this->childSocket = childSocket;
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

    Close(childSocket);
    Close(parentSocket);

    response = "See you later.";
 //   exit(0);
}


