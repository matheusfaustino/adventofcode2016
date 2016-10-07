#include "stdio.h"

#define FILENAME "input_first_day"
// #define FILENAME "example1"

int main()
{
  FILE *input;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int floor = 0;
  int i;

  input = fopen(FILENAME, "r");
  if (input == NULL) {
    perror("File");
    return 1;
  }

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
    for (i = 0; i < read; i++) {
      switch (line[i]) {
        case '(':
          floor++;
          break;

        case ')':
          floor--;
          break;
      }
      if (floor == -1) {
        break;
      }
    }
  }
  printf("Position that causes Santa to first enter the basement: %d\n", i + 1);

  return 0;
}
