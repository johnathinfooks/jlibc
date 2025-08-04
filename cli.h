#ifndef CLI_H
#define CLI_H

struct cli_command
{
    char *command_str;
    void (*handler)(int argc, char **argv);
};

#endif // CLI_H