#include "cli.h"
#include <string.h>

int parse_cli_commands(struct cli_command commands[], int commands_count, int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < commands_count; j++) {
            if (strcmp(argv[i], commands[j].command_str) == 0) {
                if (commands[j].handler)
                    commands[j].handler(argc - i, &argv[i]);
                return 1;
                break;
            }
        }
    }
    return 0;
}