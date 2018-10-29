#pragma once

#include <string>

#include "Handler.h"
#include "LogInHandler.h"

class Container {
public:
    std::string command;
    std::vector<Handler*> handlers;
};