#include <string.h>
#include "../Models/Command.h"

struct Command deserializeInput(char *inputString)
{
    struct Command command;
    command.argumentsCount = 0;

    int firstCommand = 1;

    char *p = strtok(inputString, " ");
    while (p != NULL)
    {
        if(firstCommand == 1)
        {
            strcpy(command.value, p);
            firstCommand = 0;
        }
        else
        {
            strcpy(command.arguments[command.argumentsCount++].value, p);
        }

        p = strtok(NULL, " ");
    }

    return command;
}
