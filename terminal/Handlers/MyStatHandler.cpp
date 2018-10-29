#include <iostream>
#include "MyStatHandler.h"
#include "../Helpers/FileHelper.h"

MyStatHandler::MyStatHandler()
{
    this->mustBeLoggedIn = false;
}

MyStatHandler::MyStatHandler(bool mustBeLoggedIn)
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
    response = GetFileInfo("./users.txt");
}


