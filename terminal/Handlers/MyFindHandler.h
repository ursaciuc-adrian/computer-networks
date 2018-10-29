#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class MyFindHandler: public Handler
{
public:
    MyFindHandler();

    virtual bool CanHandle(const Command *command);
    virtual void Handle();
};