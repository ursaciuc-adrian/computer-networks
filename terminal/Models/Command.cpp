#include <utility>

#include <utility>

#include "Command.h"
#include "Argument.h"

Command::Command(std::string command)
{
    this->value = std::move(command);
}

void Command::AddArgument(std::string arg)
{
    this->arguments.push_back(new Argument(std::move(arg)));
}

const Argument * Command::GetArgument(unsigned long index) const
{
    if(arguments.size() > index)
    {
        return arguments.at(index);
    }

    return nullptr;
}
