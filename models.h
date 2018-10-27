#pragma once

struct Argument {
    char value[256];
};

struct Command {
    char value[256];
    struct Argument arguments[10];
    int argumentsCount;
};