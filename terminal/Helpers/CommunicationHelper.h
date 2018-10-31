#include <unistd.h>
#include <string>
#include <vector>

static void Write(int socket, const std::string &str)
{
    unsigned long length = str.length();
    write(socket, &length, sizeof(length));
    write(socket, str.c_str(), length);
}

static void Read(int socket, std::string &str)
{
    unsigned long length;
    read(socket, &length, sizeof(length));

    std::vector<char> buffer(length + 1);
    read(socket, buffer.data(), length);

    buffer[length] = '\0';
    str = buffer.data();
}

static void Close(int socket)
{
    close(socket);
}