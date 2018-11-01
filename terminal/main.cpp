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
#include "Sockets.h"
#include "Pipe.h"

Container container;


Response HandleCommand(const std::string &str)
{
    const Command *command = deserializeInput(str);
//    std::cout<<str<<std::endl;
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

int main()
{
    int pipefds1[2], pipefds2[2];
    int returnstatus1, returnstatus2;
    int pid;
    char readmessage[250];
    returnstatus1 = pipe(pipefds1);

    if (returnstatus1 == -1) {
        printf("Unable to create pipe 1 \n");
        return 1;
    }
    returnstatus2 = pipe(pipefds2);

    if (returnstatus2 == -1) {
        printf("Unable to create pipe 2 \n");
        return 1;
    }
    pid = fork();

    if (pid != 0)
     {
         std::string str;
         Response response = Response();

         close(pipefds1[0]);
         close(pipefds2[1]);
         while (response.GetType() != Quit)
         {
             std::cout << "> ";
             std::getline(std::cin, str);

             write(pipefds1[1], str.c_str(), str.length() + 1);

             char value[250];
             char type[250];

             read(pipefds2[0], value, sizeof(value));
             read(pipefds2[0], type, sizeof(type));

             response = Response(value, type);

             std::cout << response.GetValue() << std::endl;
         }
    }
    else
    {
        auto *logInService = new LogInService();
        container.handlers.push_back(new LogInHandler(logInService, false));
        container.handlers.push_back(new QuitHandler(logInService, false));
        container.handlers.push_back(new MyFindHandler(logInService, false));
        container.handlers.push_back(new MyStatHandler(logInService, false));

        close(pipefds1[1]);
        close(pipefds2[0]);

        Response response = Response();

        while (response.GetType() != Quit)
        {
            read(pipefds1[0], readmessage, sizeof(readmessage));
            std::string str(readmessage);

            response = HandleCommand(str);

            write(pipefds2[1], response.GetValue().c_str(), response.GetValue().length() + 1);
            write(pipefds2[1], ResponseTypeMap[response.GetType()].c_str(), ResponseTypeMap[response.GetType()].length());
            exit(1);
        }

    }
    return 0;
}