#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

#include "Models/Command.h"
#include "Helpers/TermianlHelper.h"
#include "Handlers/LogInHandler.h"
#include "Handlers/QuitHandler.h"
#include "Handlers/Handler.h"

#define BUFF_SIZE 256

int main()
{
    std::cout << "Better than linux terminal. (v0.0.2)" << std::endl << std::endl;

    LogInHandler *logInHandler = new LogInHandler();
    QuitHandler *quitHandler = new QuitHandler();

    std::vector<Handler*> handlers;
    handlers.push_back(logInHandler);
    handlers.push_back(quitHandler);

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
                std::string inputString;
                char response[256];

                if(logInHandler->IsLoggedIn() == true)
                {
                    std::cout << logInHandler->username << "> ";
                }
                else
                {
                    std::cout << "> ";
                }

                std::getline(std::cin, inputString);

                if (write(sockets[1], inputString.c_str(), sizeof(inputString)) < 0)
                {
                    printf("[PARENT] Error occurred while writing.\n");
                }

                if (read(sockets[1], response, sizeof(response)) < 0)
                {
                    printf("[PARENT] Error occurred while reading.\n");
                }

                std::cout << response << std::endl;
            }

            close(sockets[1]);
        }
        else
        {
            close(sockets[1]);

            for (int i = 0; i < 5; ++i)
            {
                char inputString[256];

                if (read(sockets[0], inputString, sizeof(inputString)) < 0)
                {
                    printf("[CHILD] Error occurred while reading.\n");
                }

                const Command *command = deserializeInput(inputString);

                for(auto *handler: handlers)
                {
                    if(handler->CanHandle(command))
                    {
                        handler->Handle();

                        if(handler->HasResponse())
                        {
                            if (write(sockets[0], handler, sizeof(handler) < 0))
                            {
                                printf("[CHILD] Error occurred while writing.\n");
                            }
                        }
                    }
                    else
                    {
                        if(handler->HasResponse())
                        {
                            if (write(sockets[0], handler->GetResponse().c_str(), sizeof(handler->GetResponse())) < 0)
                            {
                                printf("[CHILD] Error occurred while writing.\n");
                            }
                        }
                    }
                }
            }

            close(sockets[0]);
        }
    }

    return 0;
}