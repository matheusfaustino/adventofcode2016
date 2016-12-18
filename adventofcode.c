#include "adventofcode.h"

FILE *handle_file_by_arg(int argc, char const *argv[])
{
        if (argc < 2) {
                perror("The arguments were not right. Follow instructions.\n");
                help_message(argv);
                exit(1);
        }

        FILE *input = fopen(argv[1], "r");
        if (input == NULL) {
                perror("File: ");
                exit(1);
        }

        return input;
}

void help_message(char const *argv[])
{
        printf("Execute file: %s <input_path> \n", argv[0]);
        printf("\t%s input/input_day \n", argv[0]);
}
