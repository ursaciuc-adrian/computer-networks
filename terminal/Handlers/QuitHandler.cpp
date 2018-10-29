#include <iostream>
#include "QuitHandler.h"

bool QuitHandler::CanHandle(const Command *com)
{
    response = "";

    if(com->value == "quit")
    {
        command = com;
        response = "da";
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


