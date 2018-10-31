#pragma once

#include <string>

class Argument {
public:
    std::string value;

    Argument() = default;;
    explicit Argument(std::string arg);
};
