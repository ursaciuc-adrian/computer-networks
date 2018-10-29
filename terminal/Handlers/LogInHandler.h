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
    LogInHandler(bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;
    void Handle() override;

    bool IsLoggedIn();
};