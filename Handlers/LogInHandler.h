#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../Models/Command.h"
#include "../Models/LogInData.h"

#define DATABASE "users.txt"

void logIn(struct Command command, char *response, struct LogInData *logInData)
{
    FILE *fp = fopen(DATABASE, "r");
    if(fp == NULL)
    {
        strcpy(response, "Error while opening the database.\\n\"");
        return;
    }

    char line[100];
    while (fgets(&line, sizeof(line), fp))
    {
        line[strlen(line) - 1] = '\0';
        if(strcmp(line, command.arguments[0].value) == 0)
        {
            logInData->isLogged = true;
        }
    }

    if(logInData->isLogged == false)
    {
        strcpy(response, "Invalid username.\n");
        return;
    }

    strcpy(logInData->username, command.arguments[0].value);

    strcpy(response, "Welcome ");
    strcat(response, logInData->username);
    strcat(response, "!\n");
}