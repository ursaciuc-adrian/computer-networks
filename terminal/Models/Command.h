#pragma once

#include <vector>
#include <string>
#include "Argument.h"

class Command {
public:
    std::string value;
    Command();
    Command(std::string command);
    void AddArgument(std::string arg);
    const Argument * GetArgument(int index) const;
private:
    std::vector<Argument*> arguments;
};
