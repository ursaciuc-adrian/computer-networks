#pragma once

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

class Sockets
{
public:
    Container container;

    Response HandleCommand(const std::string &str)
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

        return Response("Command not found.", Error);
    }

    void ParentProcess(int socket)
    {
        std::string str;
        Response response = Response();

        while (response.GetType() != Quit)
        {
            std::cout << "> ";
            std::getline(std::cin, str);

            Write(socket, str);

            std::string value;
            std::string type;
            Read(socket, value);
            Read(socket, type);

            response = Response(value, type);

            std::cout << response.GetValue() << std::endl;
        }

        Close(socket);
    }

    void ChildProcess(int socket)
    {
        std::string str;
        Response response = Response();

        while (response.GetType() != Quit)
        {
            Read(socket, str);

            response = HandleCommand(str);

            Write(socket, response.GetValue());
            Write(socket, ResponseTypeMap[response.GetType()]);
        }

        Close(socket);
    }

    int Start()
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
            auto *logInService = new LogInService();
            container.handlers.push_back(new LogInHandler(logInService, false));
            container.handlers.push_back(new QuitHandler(logInService, false));
            container.handlers.push_back(new MyFindHandler(logInService, true));
            container.handlers.push_back(new MyStatHandler(logInService, true));

            if (parent)
            {
                Close(sockets[1]);

                ParentProcess(sockets[0]);
            }
            else
            {
                Close(sockets[0]);

                ChildProcess(sockets[1]);
            }
        }

        return 0;
    }
};