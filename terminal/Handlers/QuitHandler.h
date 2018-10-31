#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class QuitHandler: public Handler
{
public:
    QuitHandler(LogInService *logInService, bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;
    void Handle() override;
};