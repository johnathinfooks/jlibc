#ifndef CLI_H
#define CLI_H

// DEPENDANCIES
#include <string.h>



// STRUCTURE DECLARATIONS

/* Intended command string. Function to be initiated. Total argc expectation. Number of arguments after expectation. */
struct cli_command
{
    char *command_str;
    void (*handler)(int argc, char **argv);
    int argc_expectation;
    int argc_after_expectation;
};



// FUNCTION DECLARATIONS

/* Takes cli commands array of structures. Looks at every argv and tries to match it with a string in the structure. Upon success, executes the handler and returns 1. Upon failure, returns 0. */
int parse_cli_commands(struct cli_command commands[], int commands_count, int argc, char **argv);

#endif // CLI_H