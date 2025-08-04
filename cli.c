#include "cli.h"

struct cli_command
{
    char *command_str;
    void (*handler)(int argc, char **argv);
};