#include "adventofcode.h"

// #define FILENAME "example1"
#define MAX_HOUSES 8200 // based on input

int main(int argc, char const *argv[]){
  FILE *input = handle_file_by_arg(argc, argv);
  char *line = NULL;
  // size_t is a type that can hold any array index
  size_t len = 0;
  ssize_t read;
  int i, x, y, visits, noelTurn;

  // initialize two dimensional array. It is not possible to initialize an array with this size statically
  int (*xy)[MAX_HOUSES] = malloc(sizeof(*xy) * MAX_HOUSES);

  x = y = MAX_HOUSES / 2;

  xy[x][y] = 1;
  visits = 1;

  // getline POSIX function (stdio). len need to be a size_t type.
  while ((read = getline(&line, &len, input)) != -1) {
    read--;
    for(i = 0; i < read; i++) {
      switch(line[i]) {
        case '^':
          y++;
          break;

        case 'v':
          y--;
          break;

        case '>':
          x++;
          break;

        case '<':
          x--;
          break;
      }

      if (xy[x][y] == 0) {
        xy[x][y] = 1;
        visits++;
      }
    }
    printf("Read: %zu \nVisits: %d\n", read, visits);
  }

  /**
   * Second challenge
   */
  rewind(input);
  printf("\nSecond Challenge...\n");
  int robox, roboy, noelx, noely;
  int (*doublexy)[MAX_HOUSES] = malloc(sizeof(*doublexy) * MAX_HOUSES);
  int *xp, *yp;

  noelTurn = 1;
  visits = 1;
  robox = roboy = noelx = noely = MAX_HOUSES / 2;
  doublexy[robox][roboy] = 1;
  while ((read = getline(&line, &len, input)) != -1) {
    read--;
    for(i = 0; i < read; i++) {
      if (noelTurn > 0) {
        xp = &noelx;
        yp = &noely;
      } else {
        xp = &robox;
        yp = &roboy;
      }

      switch(line[i]) {
        case '^':
            *yp = *yp + 1;
            break;

        case 'v':
            *yp = *yp - 1;
            break;

        case '>':
            *xp = *xp + 1;
            break;

        case '<':
            *xp = *xp - 1;
            break;
      }

      if (doublexy[*xp][*yp] == 0) {
        doublexy[*xp][*yp] = 1;
        visits++;
      }

      noelTurn *= -1;
    }
    printf("Visits (Noel + Robot): %d\n", visits);
  }

  free(line);
  fclose(input);
  return 0;
}
