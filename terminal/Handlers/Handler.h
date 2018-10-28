#pragma once

#include "../Models/Command.h"

class Handler
{
protected:
    const Command *command;
    std::string response;

public:
    ~Handler() {}

    virtual bool CanHandle(const Command *command) = 0;
    virtual void Handle() = 0;

    bool HasResponse()
    {
        return !response.empty();
    }

    std::string GetResponse()
    {
        return response;
    }
};