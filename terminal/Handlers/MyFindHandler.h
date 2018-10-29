#pragma once

#include "../Models/Command.h"
#include "Handler.h"

class MyFindHandler: public Handler
{
public:
    MyFindHandler();
    MyFindHandler(bool mustBeLoggedIn);

    bool CanHandle(const Command *command) override;
    void Handle() override;
};