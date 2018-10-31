#pragma once

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <wait.h>
#include <cstring>

#include "Models/Command.h"
#include "Helpers/TermianlHelper.h"
#include "Handlers/LogInHandler.h"
#include "Handlers/QuitHandler.h"
#include "Handlers/Handler.h"
#include "Handlers/Container.h"
#include "Handlers/MyFindHandler.h"
#include "Handlers/MyStatHandler.h"
#include "Sockets.h"
#include "Helpers/CommunicationHelper.h"

class Pipe
{
public:
    Container container;

    Response HandleCommand(const std::string &str)
    {
        const Command *command = deserializeInput(str);
        std::cout<<str<<std::endl;
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
    }

    void Start()
    {
        int fd[2];
        std::string buffer;
        auto *logInService = new LogInService();
        container.handlers.push_back(new LogInHandler(logInService, false));
        container.handlers.push_back(new QuitHandler(logInService, false));
        container.handlers.push_back(new MyFindHandler(logInService, true));
        container.handlers.push_back(new MyStatHandler(logInService, true));
        if ( pipe(fd) < 0 ) {
            perror( "pipe" );
            exit( 1 );
        }

        switch( fork() ) {
            case -1:
            {
                perror( "fork" );
                exit( 1 );
            }
            case 0:
            {
                /*child process*/
                close(fd[1]);
                ChildProcess(fd[0]);
                exit(1);
            }
            default:
            {

                close(fd[0]);
                ParentProcess(fd[1]);
                break;
            }
        }
    }
};