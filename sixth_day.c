#include "adventofcode.h"

#define GARDEN_SIZE 999

typedef struct {
        int unsigned turn_on;
        int unsigned toggle;
        int unsigned turn_off;
} actions;

void identify_action(char *line, actions *action)
{
        char *substring = NULL;

        substring = strstr(line, "turn on");
        if (substring != NULL) {
                action->turn_on = 1;
        }

        substring = strstr(line, "toggle");
        if (substring != NULL) {
                action->toggle = 1;
        }

        substring = strstr(line, "turn off");
        if (substring != NULL) {
                action->turn_off = 1;
        }
}

void extract_dimension(char *line, int toggle, int pair1[2], int pair2[2])
{
        char dumb[10];

        if (toggle) {
                sscanf(line, "%s %d,%d through %d,%d", &dumb, &pair1[0], &pair1[1], &pair2[0], &pair2[1]);
        }
        else {
                sscanf(line, "%s %s %d,%d through %d,%d", &dumb, &dumb, &pair1[0], &pair1[1], &pair2[0], &pair2[1]);
        }
}

void execute_action(int *garden, actions a, int i[2], int j[2])
{
        size_t k, l;

        // for (k = i[0]; k < )
}

void first_step(FILE *input)
{
        size_t len = 0;
        size_t i[2], j[2];
        ssize_t read;
        actions action;
        char *line = NULL;
        int *garden = calloc(GARDEN_SIZE*GARDEN_SIZE, sizeof(int));

        while ((read = getline(&line, &len, input)) != -1) {
                identify_action(line, &action);
                extract_dimension(line, action.toggle, i, j);
        }
}

int main(int argc, char const *argv[])
{
        FILE *input = handle_file_by_arg(argc, argv);
        first_step(input);

        return 0;
}
