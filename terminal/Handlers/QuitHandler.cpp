#include <iostream>
#include "QuitHandler.h"

bool QuitHandler::CanHandle(const Command *command)
{
    if(command->value == "quit")
    {
        this->command = command;
        return true;
    }

    return false;
}

void QuitHandler::Handle()
{
    response = "See you later.";
    exit(0);
}

QuitHandler::QuitHandler()
{

}


