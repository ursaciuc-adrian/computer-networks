#include "Sockets.h"
#include "Pipe.h"

int main()
{
    Pipe pipe = Pipe();
    Sockets sockets = Sockets();

    return sockets.Start();
}