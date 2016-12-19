#include "./../sixth_day.c"
#include "minunit.h"

#if UNIT_TESTING
#define _main main
#endif

#define TURNON_PHRASE "turn on 0,0 through 999,999\n"
#define TOGGLE_PHRASE "toggle 0,0 through 999,0\n"
#define TURNOFF_PHRASE "turn off 499,499 through 500,500\n"

int tests_run = 0;

char *test_identify_turnon_action()
{
        actions a;
        a.toggle = a.turn_on = a.turn_off = 0;

        identify_action(TURNON_PHRASE, &a);
        mu_assert("It shoud TURN ON", a.turn_on == 1);
        a.turn_on = 0;

        identify_action(TOGGLE_PHRASE, &a);
        mu_assert("It NOT shoud TURN ON", a.turn_on == 0);
        a.turn_on = 0;

        identify_action(TURNOFF_PHRASE, &a);
        mu_assert("It NOT shoud TURN ON", a.turn_on == 0);

        return 0;
}

char *test_identify_toggle_action()
{
        actions a;
        a.toggle = a.turn_on = a.turn_off = 0;

        identify_action(TOGGLE_PHRASE, &a);
        mu_assert("It shoud TOGGLE", a.toggle == 1);
        a.toggle = 0;

        identify_action(TURNON_PHRASE, &a);
        mu_assert("It NOT shoud TOGGLE", a.toggle == 0);
        a.toggle = 0;

        identify_action(TURNOFF_PHRASE, &a);
        mu_assert("It NOT shoud TOGGLE", a.toggle == 0);

        return 0;
}

char *test_identify_turnoff_action()
{
        actions a;
        a.toggle = a.turn_on = a.turn_off = 0;

        identify_action(TURNOFF_PHRASE, &a);
        mu_assert("It shoud TURN OFF", a.turn_off == 1);
        a.turn_off = 0;

        identify_action(TOGGLE_PHRASE, &a);
        mu_assert("It NOT shoud TURN OFF", a.turn_off == 0);
        a.turn_off = 0;

        identify_action(TURNON_PHRASE, &a);
        mu_assert("It NOT shoud TURN OFF", a.turn_off == 0);

        return 0;
}

char *test_extract_dimension()
{
        int i[2], j[2];
        int toggle = 0;

        extract_dimension(TURNON_PHRASE, toggle, i, j);
        mu_assert("Extract dimension didnt work with TURN ON phrase", i[0] == 0 && i[1] == 0 & j[0] == 999 && j[1] == 999);

        extract_dimension(TURNOFF_PHRASE, toggle, i, j);
        mu_assert("Extract dimension didnt work with TURN OFF phrase", i[0] == 499 && i[1] == 499 & j[0] == 500 && j[1] == 500);

        extract_dimension(TOGGLE_PHRASE, ++toggle, i, j);
        mu_assert("Extract dimension didnt work with TOGGLE phrase", i[0] == 0 && i[1] == 0 & j[0] == 999 && j[1] == 0);

        return 0;
}

char *test_execute_action_turnon()
{
        actions a;
        int *garden = calloc(GARDEN_SIZE*GARDEN_SIZE, sizeof(int));

        a.toggle = a.turn_off = 0;
        a.turn_on = 1;

        int i[] = {0,0};
        int j[] = {999, 999};
        execute_action(&garden, a, i, j);
}

char * all_tests() {
     mu_run_test(test_identify_turnon_action);
     mu_run_test(test_identify_toggle_action);
     mu_run_test(test_identify_turnoff_action);
     mu_run_test(test_extract_dimension);
     mu_run_test(test_execute_action_turnon);
     return 0;
}

int main(int argc, char const *argv[])
{
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);

     return result != 0;
}
