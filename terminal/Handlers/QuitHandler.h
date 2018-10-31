#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class QuitHandler: public Handler
{
private:
    int parentSocket;
    int childSocket;
public:
    QuitHandler(LogInService *logInService, bool mustBeLoggedIn, int parentSocket, int childSocket);

    bool CanHandle(const Command *command) override;
    void Handle() override;
};