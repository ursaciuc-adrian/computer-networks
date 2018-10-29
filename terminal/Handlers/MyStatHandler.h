#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class MyStatHandler: public Handler
{
public:
    MyStatHandler();

    virtual bool CanHandle(const Command *command);
    virtual void Handle();
};