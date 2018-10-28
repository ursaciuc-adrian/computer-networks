#pragma once

#include <string>
#include <iterator>
#include <sstream>
#include <iostream>

#include "../Models/Command.h"

const Command* deserializeInput(std::string inputString)
{
    Command *command = new Command();

    std::istringstream buf(inputString);
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end);

    bool firstToken = false;
    for(auto& s: tokens)
    {
        if(firstToken == false)
        {
            command->value = s;
            firstToken = true;
        }
        else
        {
            command->AddArgument(s);
        }
    }

    return command;
}