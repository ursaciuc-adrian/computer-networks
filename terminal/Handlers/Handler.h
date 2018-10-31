#pragma once

#include "../Models/Command.h"
#include "../Services/LogInService.h"
#include "../Models/Response.h"

class Handler
{
protected:
    LogInService *logInService;
    bool mustBeLoggedIn{};

    const Command *command{};
    Response response;
public:
    explicit Handler(LogInService *logInService)
    {
        this->response = Response();
        this->logInService = logInService;
    };
    ~Handler() = default;

    virtual bool CanHandle(const Command *command) = 0;
    virtual void Handle() = 0;

    bool HasResponse()
    {
        return response.GetType() != ResponseType(None);
    }

    Response GetResponse()
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
                response = Response("You must be logged in to execute this command.", ResponseType(Error));
                return false;
            }
        }

        return true;
    }
};
