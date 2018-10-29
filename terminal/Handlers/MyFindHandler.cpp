#include <iostream>
#include <dirent.h>
#include <cstring>

#include "MyFindHandler.h"
#include "../Helpers/FileHelper.h"

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
    total = 0;
    std::cout<<"Arg: "<<command->GetArgument(0)->value << std::endl;
    std::string pathToFile = FindFile("./", "Argumednt.h");
    if(pathToFile.empty())
    {
        response = "File not found.";
    }
    else
    {
        response = pathToFile;
    }
}

MyFindHandler::MyFindHandler()
{

}


