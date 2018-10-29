#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

#include "Models/Command.h"
#include "Helpers/TermianlHelper.h"
#include "Handlers/LogInHandler.h"
#include "Handlers/QuitHandler.h"
#include "Handlers/Handler.h"
#include "Handlers/Container.h"
#include "Handlers/MyFindHandler.h"
#include "Handlers/MyStatHandler.h"

Container container;

void ParentProcess(int socket)
{
    //parinte
    for(int i = 0; i < 5; ++i)
    {
        std::string inputString;
        char response[256];

        if(container.logInHandler.IsLoggedIn() == true)
        {
            std::cout << container.logInHandler.username << "> ";
        }
        else
        {
            std::cout << "> ";
        }

        std::getline(std::cin, container.command);

        if (write(socket, &container, sizeof(container)) < 0)
        {
            printf("[PARENT] Error occurred while writing.\n");
        }

        if (read(socket, &container, sizeof(container)) < 0)
        {
            printf("[PARENT] Error occurred while reading.\n");
        }
    }

    close(socket);
}

void ChildProcess(int socket)
{
    for(int i = 0; i < 5; ++i)
    {
        if (read(socket, &container, sizeof(container)) < 0)
        {
            printf("[CHILD] Error occurred while reading.\n");
        }

        const Command *command = deserializeInput(container.command);

        for(auto *handler: container.handlers)
        {
            if(handler->CanHandle(command))
            {
                handler->Handle();

                if(handler->HasResponse())
                {
                    std::cout<< handler->GetResponse() << std::endl;
                }

                break;
            }
            else
            {
                if(handler->HasResponse())
                {
                    std::cout<< handler->GetResponse() << std::endl;
                }
            }
        }

        if (write(socket, &container, sizeof(container)) < 0)
        {
            printf("[CHILD] Error occurred while writing.\n");
        }
    }

    close(socket);
}

int main()
{
    container.logInHandler = LogInHandler();
    container.handlers.push_back(&container.logInHandler);
    container.handlers.push_back(new QuitHandler());
    container.handlers.push_back(new MyFindHandler());
    container.handlers.push_back(new MyStatHandler());

    std::cout << "Better than linux terminal. (v0.0.2)" << std::endl << std::endl;

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

            ParentProcess(sockets[1]);
        }
        else
        {
            close(sockets[1]);

            ChildProcess(sockets[0]);
        }
    }

    return 0;
}