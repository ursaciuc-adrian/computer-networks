#pragma once

#include "../Models/Command.h"

class Handler
{
protected:
    const Command *command;
    std::string response;
    bool mustBeLoggedIn;
public:
    ~Handler() = default;

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