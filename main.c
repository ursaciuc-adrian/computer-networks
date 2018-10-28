#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"
#include "terminalHelper.h"
#include "loginService.h"

#define BUFF_SIZE 256

void handleCommand(char *inputString)
{
    struct Command command = deserializeInput(inputString);

    if (strcmp(command.value, "login") == 0)
    {
        logIn(command);
    }
}

void readCommand()
{
    int sockets[2], parent;

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
    {
        printf("Error occurred on socketpair.\n");
        exit(1);
    }

    if ((parent = fork()) == -1)
    {
        printf("Error occurred on fork.\n");
    }
    else
    {
        if (parent)
        {
            close(sockets[0]);

            for (int i = 0; i < 5; ++i)
            {
                char command[BUFF_SIZE];
                char response[BUFF_SIZE];

                if(isLogged == true)
                {
                    printf("%s> ", loggedUser);
                }
                else
                {
                    printf("> ");
                }

                fgets(command, sizeof(command), stdin);
                command[strlen(command) - 1] = '\0';

                if (write(sockets[1], command, sizeof(command)) < 0)
                {
                    printf("[PARENT] Error occurred while writing.\n");
                }

                if (read(sockets[1], response, sizeof(response)) < 0)
                {
                    printf("[PARENT] Error occurred while reading.\n");
                }

                // printf("[parinte] %s\n", response);
            }

            close(sockets[1]);
        }
        else
        {
            close(sockets[1]);

            for (int i = 0; i < 5; ++i)
            {
                char command[BUFF_SIZE];
                char response[BUFF_SIZE];

                if (read(sockets[0], command, sizeof(command)) < 0)
                {
                    printf("[CHILD] Error occurred while reading.\n");
                }

                handleCommand(command);

                if (write(sockets[0], response, sizeof(response)) < 0)
                {
                    printf("[CHILD] Error occurred while writing.\n");
                }
            }

            close(sockets[0]);
        }
    }
}

int main()
{
    printf("Better than linux terminal. (v0.0.0.1-pre-pre-alpha)\n\n");

    readCommand();
}