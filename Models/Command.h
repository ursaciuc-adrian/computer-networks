#pragma once

#include "Argument.h"

struct Command
{
    char value[256];
    struct Argument arguments[10];

    int argumentsCount;
};