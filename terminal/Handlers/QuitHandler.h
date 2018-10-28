#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class QuitHandler: public Handler
{
public:
    QuitHandler();

    virtual bool CanHandle(const Command *command);
    virtual void Handle();
};