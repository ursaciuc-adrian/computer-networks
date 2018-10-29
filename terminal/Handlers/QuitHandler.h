#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class QuitHandler: public Handler
{
public:
    QuitHandler();
    QuitHandler(bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;
    void Handle() override;
};