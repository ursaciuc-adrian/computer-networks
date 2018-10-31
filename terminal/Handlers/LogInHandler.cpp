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
    response = "";

    if (com->value == "login")
    {
        if(com->GetArgument(0) != NULL)
        {

            this->command = com;
            return true;
        }

        response = "Username not specified.";
    }

    return false;
}

void LogInHandler::Handle()
{
    response = "";

    std::ifstream fin(DATABASE);

    if(!fin)
    {
        response = "Error while opening the database.";
        return;
    }

    char str[100];
    while(fin)
    {
        fin.getline(str, 100);
        if(str == command->GetArgument(0)->value)
        {
            logInService->LogIn(command->GetArgument(0)->value);

            response = "Welcome " + logInService->GetUsername() + "!";
        }
    }

    fin.close();

    if(!logInService->IsLoggdedIn())
    {
        response = "Invalid username.";
    }
}

