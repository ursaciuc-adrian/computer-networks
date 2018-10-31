#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class LogInHandler: public Handler
{
public:
    LogInHandler(LogInService *logInService, bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;
    void Handle() override;
};