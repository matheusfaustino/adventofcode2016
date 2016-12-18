#include "adventofcode.h"

int main(int argc, char const *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int floor = 0;
    int i;

    FILE *input = handle_file_by_arg(argc, argv);

    while ((read = getline(&line, &len, input)) != -1) {
        read--;
        for (i = 0; i < read; i++) {
            switch (line[i]) {
                case '(':
                    floor++;
                    break;

                case ')':
                    floor--;
                    break;
            }
        }
    }
    printf("Floor: %d\n", floor);

    /**
     * Second part
     */
    rewind(input);
    printf("\nSecond Part:\n");
    floor = 0;
    while ((read = getline(&line, &len, input)) != -1) {
        read--;
        for (i = 0; (i < read) && (floor != -1); i++) {
            switch (line[i]) {
                case '(':
                    floor++;
                    break;

                case ')':
                    floor--;
                    break;
            }
        }
    }
    printf("Position that causes Santa to first enter the basement: %d\n", i);

    return 0;
}
