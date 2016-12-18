#include "adventofcode.h"

void first_step(FILE *input)
{
        size_t len = 0;
        size_t i, j;
        ssize_t read;
        char *line = NULL;
        char *vowels = "aeiou";
        char not_allowed[][4] = {"ab", "cd", "pq", "xy"};
        int has_consecutive_letter = 0;
        int quantity_vowels = 0;
        int has_not_allowed = 0;
        int nice_strings = 0;

        while ((read = getline(&line, &len, input)) != -1) {
                read--;

                /* checking vowels */
                for (i = 0; i < strlen(vowels) && quantity_vowels < 3; i++) {
                        for (j = 0; j < strlen(line); j++) {
                                if (line[j] == vowels[i]) {
                                        ++quantity_vowels;
                                }
                        }
                }

                /* checking consecutive letters */
                for (i = 0; i < read && !has_consecutive_letter; i++) {
                        if (line[i] == line[i+1]) {
                                has_consecutive_letter++;
                        }
                }

                /* I put hardcoded because for get it in runtime I have to use two sizeof and divide them */
                for (i = 0; i < 4 && !has_not_allowed; i++) {
                        // match = ;
                        if (strstr(line, not_allowed[i]) != NULL)
                                has_not_allowed++;
                }

                if (quantity_vowels >= 3 && has_consecutive_letter && !has_not_allowed)
                        nice_strings++;

                // reseting
                quantity_vowels = has_consecutive_letter = has_not_allowed = 0;
        }

        printf("1. Nice Strings: %d\n", nice_strings);
}

void second_step(FILE *input)
{
        size_t len = 0;
        size_t i, j;
        ssize_t read;
        char *line = NULL;
        int nice_strings = 0;
        int has_pairs_twice;
        int has_one_between_two_equals = 0;
        while ((read = getline(&line, &len, input)) != -1) {

                for (i = 0; i < strlen(line) && !has_pairs_twice; i++) {
                        for (j = i + 2; j < strlen(line); j++) {
                                if (line[i] == line[j] && line[i+1] == line[j+1])
                                        has_pairs_twice++;
                        }
                }

                for (i = 0; i < strlen(line) && !has_one_between_two_equals; i++) {
                        if (line[i] == line[i+2])
                                has_one_between_two_equals++;
                }

                if (has_pairs_twice && has_one_between_two_equals)
                        nice_strings++;

                has_pairs_twice = has_one_between_two_equals = 0;
        }

        printf("2. Nice Strings: %d\n", nice_strings);
}

int main(int argc, char const *argv[])
{
        FILE *input = handle_file_by_arg(argc, argv);

        first_step(input);
        rewind(input);
        second_step(input);

        return 0;
}
