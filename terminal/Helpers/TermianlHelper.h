#pragma once

#include <string>
#include <iterator>
#include <sstream>
#include <iostream>

#include "../Models/Command.h"

const Command* deserializeInput(const std::string &inputString)
{
    auto *command = new Command();

    std::istringstream iss(inputString);
    std::string token;

    bool firstToken = true;
    while (std::getline(iss, token, ' '))
    {
        if(firstToken)
        {
            command->value = token;
            firstToken = false;
        }
        else
        {
            command->AddArgument(token);
        }
    }

    return command;
}