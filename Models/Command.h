#pragma once

struct Command
{
    char *value;
    char **arguments;

    int argumentsLength;
};