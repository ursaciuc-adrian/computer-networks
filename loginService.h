#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "models.h"

#define DATABASE "users.txt"

static char loggedUser[256];
static bool isLogged;

void logIn(struct Command command)
{
    FILE *fp = fopen(DATABASE, "r");
    if(fp == NULL)
    {
        printf("Error while opening the database.\n");
        return;
    }

    char line[100];
    while (fgets(&line, sizeof(line), fp))
    {
        line[strlen(line) - 1] = '\0';
        if(strcmp(line, command.arguments[0].value) == 0)
        {
            isLogged = true;
        }
    }

    if(isLogged == false)
    {
        printf("Invalid username.\n");
        return;
    }

    strcpy(loggedUser, command.arguments[0].value);
    printf("Welcome %s\n", loggedUser);
}