#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"
#include "terminalHelper.h"
#include "loginService.h"

void handleCommand(char inputString[])
{
    struct Command command = deserializeInput(inputString);

    if (strcmp(command.value, "login") == 0)
    {
        logIn(command);
    }
}

int main()
{
    int sockp[2], parent;
    char command[1024];

    printf("Better than linux terminal. (v0.0.0.1-pre-pre-alpha)\n\n");

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0)
    {
        perror("Err... socketpair");
        exit(1);
    }

    if ((parent = fork()) == -1)
    {
        perror("Err...fork");
    }
    else
    {
        if (parent)
        {
            close(sockp[0]);
            char r_msg[1024];

            printf("> ");
            scanf("%[^\n]s", r_msg);

            if (write(sockp[1], r_msg, sizeof(r_msg)) < 0)
            {
                perror("[parinte]Err...write");
            }

            close(sockp[1]);
        }
        else
        {
            close(sockp[1]);

            if (read(sockp[0], command, 1024) < 0)
            {
                perror("[copil]Err..read");
            }

            //printf("%s", command);
            handleCommand(command);

            /*printf("[copil]  %s\n", loggedUser);*/

            close(sockp[0]);
        }
    }
}