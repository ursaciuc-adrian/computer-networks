#include <iostream>
#include "MyStatHandler.h"
#include "../Helpers/FileHelper.h"

MyStatHandler::MyStatHandler(LogInService *logInService, bool mustBeLoggedIn)
        :Handler(logInService)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool MyStatHandler::CanHandle(const Command *com)
{
    response = Response();

    if(com->value == "mystat")
    {
        if(com->GetArgument(0) != NULL)
        {
            command = com;
            return true;
        }
        else
        {
            response = Response("No file provided.", Error);
        }
    }

    return false;
}

void MyStatHandler::Handle()
{
    if(!CheckLogIn())
    {
        return;
    }

    response = Response(GetFileInfo(command->GetArgument(0)->value), Success);
}


