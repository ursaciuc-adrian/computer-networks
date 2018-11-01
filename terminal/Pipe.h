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

        //while (response.GetType() != Quit)
        {
            std::cout << "> ";
            std::getline(std::cin, str);

            Write(socket, str);

            std::string value;
            std::string type;
            Read(socket, value);
            Read(socket, type);

            response = Response(value, type);

            std::cout << value<< std::endl;
        }
    }

    void ChildProcess(int socket)
    {
        std::string str;
        Response response = Response();

      //  while (response.GetType() != Quit)
        {
            Read(socket, str);
            // std::cout << str << std::endl;
            //response = HandleCommand(str);

            Write(socket, "Not working");
            Write(socket, "Error");
        }
    }

    void Start()
    {

    }
};