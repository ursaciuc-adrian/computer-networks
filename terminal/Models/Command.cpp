#include "Command.h"
#include "Argument.h"

Command::Command(std::string command)
{
    this->value = command;
}

void Command::AddArgument(std::string arg)
{
    this->arguments.push_back(new Argument(arg));
}

const Argument * Command::GetArgument(int index) const {
    if(arguments.size() > index)
    {
        return arguments.at(index);
    }

    return NULL;
}

Command::Command()
{

}
