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

int main()
{
    std::cout << "Better than linux terminal. (v0.0.3)" << std::endl << std::endl;

    Sockets sockets = Sockets();
    Pipe pipe = Pipe();
    pipe.Start();

    return 0;
}