#include <fstream>
#include <iostream>
#include "LogInHandler.h"

#define DATABASE "users.txt"

LogInHandler::LogInHandler()
{
    this->mustBeLoggedIn = false;
}

LogInHandler::LogInHandler(bool mustBeLoggedIn)
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
    this->LogOut();
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
            isLoggedIn = true;
            username = command->GetArgument(0)->value;

            response = "Welcome " + username + "!";
        }
    }

    fin.close();

    if(isLoggedIn == false)
    {
        response = "Invalid username.";
    }
}

bool LogInHandler::IsLoggedIn()
{
    return isLoggedIn;
}

void LogInHandler::LogOut()
{
    this->isLoggedIn = false;
    this->username = "";
}

