#include <iostream>
#include <dirent.h>
#include <cstring>

#include "MyFindHandler.h"
#include "../Helpers/FileHelper.h"

MyFindHandler::MyFindHandler(LogInService *logInService, bool mustBeLoggedIn)
        :Handler(logInService)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool MyFindHandler::CanHandle(const Command *com)
{
    response = Response();

    if(com->value == "myfind")
    {
        if(com->GetArgument(0) != NULL)
        {
            command = com;
            return true;
        }
        else
        {
            response =  Response("No file provided.", Error);
        }
    }

    return false;
}

void MyFindHandler::Handle()
{
    if(!CheckLogIn())
    {
        return;
    }

    std::string pathToFile;

    if(command->GetArgument(1) != NULL)
    {
        pathToFile = FindFile(command->GetArgument(1)->value, command->GetArgument(0)->value);
    }
    else
    {
        pathToFile = FindFile("./", command->GetArgument(0)->value);
    }

    if(pathToFile.empty())
    {
        response = Response("File not found.", Error);
    }
    else
    {
        std::string result = "Path: " + pathToFile + "\n";
        result += GetFileInfo(pathToFile);

        response = Response(result, Success);
    }
}



