#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class MyStatHandler: public Handler
{
public:
    MyStatHandler(LogInService *logInService, bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;

    void Handle() override;
};