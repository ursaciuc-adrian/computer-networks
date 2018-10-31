#pragma once

#include <string>

class LogInService
{
private:
    bool isLoggedIn;
    std::string username;
public:
    void LogIn(std::string username);
    void LogOut();
    bool IsLoggdedIn();
    std::string GetUsername();
};