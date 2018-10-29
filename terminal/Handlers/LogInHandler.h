#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class LogInHandler: public Handler
{
    bool isLoggedIn;
    void LogOut();

public:
    std::string username;

    LogInHandler();

    virtual bool CanHandle(const Command *command);
    virtual void Handle();

    bool IsLoggedIn();
};