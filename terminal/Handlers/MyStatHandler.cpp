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
    response = "";

    if(com->value == "mystat")
    {
        if(com->GetArgument(0) != NULL)
        {
            command = com;
            return true;
        }
        else
        {
            response = "No file provided.";
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

    response = GetFileInfo(command->GetArgument(0)->value);
}


