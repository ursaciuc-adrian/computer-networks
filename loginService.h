#include "models.h"

char loggedUser[256];

void logIn(struct Command command)
{
    strcpy(loggedUser, command.arguments[0].value);
    printf("Welcome %s\n", loggedUser);
}