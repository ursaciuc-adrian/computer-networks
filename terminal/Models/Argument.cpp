#pragma once

#include "Argument.h"

Argument::Argument(std::string arg)
{
    this->value = std::move(arg);
}