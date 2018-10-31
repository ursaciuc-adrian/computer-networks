#include <utility>

#include <fstream>
#include <iostream>
#include "LogInHandler.h"

#define DATABASE "users.txt"

LogInHandler::LogInHandler(LogInService *logInService, bool mustBeLoggedIn)
    :Handler(logInService)
{
    this->mustBeLoggedIn = mustBeLoggedIn;
}

bool LogInHandler::CanHandle(const Command *com)
{
    response = Response();

    if (com->value == "login")
    {
        if(com->GetArgument(0) != NULL)
        {

            this->command = com;
            return true;
        }

        response = Response("Username not specified.", ResponseType(Error));
    }

    return false;
}

void LogInHandler::Handle()
{
    response = Response();

    std::ifstream fin(DATABASE);

    if(!fin)
    {
        response = Response("Error while opening the database.", ResponseType(Error));
        return;
    }

    char str[100];
    bool isUserValid = false;
    while(fin)
    {
        fin.getline(str, 100);
        if(str == command->GetArgument(0)->value)
        {
            isUserValid = true;

            logInService->LogIn(command->GetArgument(0)->value);
            response = Response("Welcome " + logInService->GetUsername() + "!", ResponseType(Success));
        }
    }

    fin.close();

    if(!isUserValid)
    {
        response = Response("Invalid username.", ResponseType(Error));
    }
}