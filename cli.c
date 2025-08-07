#include "cli.h"
#include <string.h>

int parse_cli_commands(struct cli_command commands[], int commands_count, int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < commands_count; j++) {
            if (strcmp(argv[i], commands[j].command_str) == 0 && commands[j].argc_expectation == i) {
                int args_after = argc - i - 1;
                if (args_after != commands[j].argc_after_expectation)
                    continue;
                if (commands[j].handler)
                    commands[j].handler(argc - i, &argv[i]);
                return 1;
            }
        }
    }
    return 0;
}