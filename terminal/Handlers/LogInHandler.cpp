#include <fstream>
#include <iostream>
#include "LogInHandler.h"

#define DATABASE "users.txt"

LogInHandler::LogInHandler()
{

}

bool LogInHandler::CanHandle(const Command *command)
{
    if (command->value == "login")
    {
        if(command->GetArgument(0) != NULL)
        {
            this->command = command;
            return true;
        }

        response = "Username not specified.";
    }

    return false;
}

void LogInHandler::Handle()
{
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
            this->isLoggedIn = true;
            this->username = command->GetArgument(0)->value;

            response = "Welcome " + this->username + "!";
        }
    }

    fin.close();
}

bool LogInHandler::IsLoggedIn()
{
    return isLoggedIn;
}
