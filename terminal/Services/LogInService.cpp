#include <utility>

#include "LogInService.h"

void LogInService::LogIn(std::string username)
{
    this->username = std::move(username);
    this->isLoggedIn = true;
}

void LogInService::LogOut()
{
    this->username = "";
    this->isLoggedIn = false;
}

bool LogInService::IsLoggdedIn()
{
    return isLoggedIn;
}

std::string LogInService::GetUsername()
{
    return username;
}
