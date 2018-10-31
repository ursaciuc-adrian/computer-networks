#include <utility>

#pragma once

#include "../Models/Command.h"
#include "../Services/LogInService.h"

class Handler
{
protected:
    LogInService *logInService;
    bool mustBeLoggedIn{};

    const Command *command{};
    std::string response;
public:
    explicit Handler(LogInService *logInService)
    {
        this->logInService = logInService;
    };
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

    bool CheckLogIn()
    {
        if(mustBeLoggedIn)
        {
            if(logInService->IsLoggdedIn())
            {
                return true;
            }
            else
            {
                response = "You must be logged in to execute this command.";
                return false;
            }
        }

        return true;
    }
};
