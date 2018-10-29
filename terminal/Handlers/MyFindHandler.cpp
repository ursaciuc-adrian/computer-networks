#include <iostream>
#include <dirent.h>
#include <cstring>

#include "MyFindHandler.h"
#include "../Helpers/FileHelper.h"

MyFindHandler::MyFindHandler()
{
    this->mustBeLoggedIn = false;
}

MyFindHandler::MyFindHandler(bool mustBeLoggedIn)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool MyFindHandler::CanHandle(const Command *com)
{
    response = "";

    if(com->value == "myfind")
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

void MyFindHandler::Handle()
{
    std::string pathToFile = FindFile("./", command->GetArgument(0)->value);

    if(pathToFile.empty())
    {
        response = "File not found.";
    }
    else
    {
        response = pathToFile;
    }
}



