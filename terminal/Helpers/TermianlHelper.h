#pragma once

#include <string>
#include <iterator>
#include <sstream>
#include <iostream>

#include "../Models/Command.h"

const Command* deserializeInput(std::string inputString)
{
    auto *command = new Command();
    

    std::istringstream buf(inputString);
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end);

    bool firstToken = true;
    for(auto& s: tokens)
    {
        if(firstToken)
        {
            command->value = s;
            firstToken = false;
        }
        else
        {
            command->AddArgument(s);
        }
    }

    return command;
}