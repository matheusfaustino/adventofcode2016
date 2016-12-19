#ifndef ADVENTOFCODE_H_
#define ADVENTOFCODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* a little workaround for use unit tests. Now I can include the *.c file without error */
/* i know, it is not good to include *.c file, but I found it easier to test e very simple */
#if UNIT_TESTING
#define main _main
#endif

FILE *handle_file_by_arg(int argc, char const *argv[]);

void help_message();

#endif // ADVENTOFCODE_H_
