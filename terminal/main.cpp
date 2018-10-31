#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <wait.h>

#include "Models/Command.h"
#include "Helpers/TermianlHelper.h"
#include "Handlers/LogInHandler.h"
#include "Handlers/QuitHandler.h"
#include "Handlers/Handler.h"
#include "Handlers/Container.h"
#include "Handlers/MyFindHandler.h"
#include "Handlers/MyStatHandler.h"
#include "Helpers/CommunicationHelper.h"

Container container;

std::string HandleCommand(const std::string &str)
{
    const Command *command = deserializeInput(str);

    for(auto *handler: container.handlers)
    {
        if(handler->CanHandle(command))
        {
            handler->Handle();

            if(handler->HasResponse())
            {
                return handler->GetResponse();
            }

            break;
        }
        else
        {
            if(handler->HasResponse())
            {
                return handler->GetResponse();
            }
        }
    }

    return "";
}

void ParentProcess(int socket)
{
    for(; ;)
    {
        std::string str;

        std::cout << "> ";
        std::getline(std::cin, str);

        Write(socket, str);
        Read(socket, str);

        std::cout<<str<<std::endl;
    }

    close(socket);
}

void ChildProcess(int socket)
{
    for(; ;)
    {
        std::string str;

        Read(socket, str);
        Write(socket, HandleCommand(str));
    }

    close(socket);
}

int main()
{
    std::cout << "Better than linux terminal. (v0.0.3)" << std::endl << std::endl;

    int sockets[2], parent;

    auto *logInService = new LogInService();
    container.handlers.push_back(new LogInHandler(logInService, false));
    container.handlers.push_back(new QuitHandler(logInService, false, sockets[1], sockets[0]));
    container.handlers.push_back(new MyFindHandler(logInService, false));
    container.handlers.push_back(new MyStatHandler(logInService, false));

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