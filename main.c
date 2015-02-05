#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "struct.h"

// Print the first menu of the program
int firstMenu(container *E)
{
  int input;

  printf("\n\
(1) Access a pointer\n\
(2) List deallocated memory (index)\n\
(3) Deallocate all memory\n\
(4) Exit program\n");

  if (scanf("%d", &input) != 1 || (input <= 0 || input > 4))
      while (getchar() != '\n');

  switch (input) {
  case 1:
    accessPointerMenu(E);
    break;
  case 2:
    listDeallocated(E);
    break;
  case 3:
    freeEverything(E);
    break;
  case 4:
    return 1;
  }
  return 0;
}

int main(int ac, char **av)
{
  container *E;
  int i;

  printf("Generating the random data. Please wait.\n");

  E = malloc(sizeof(container));
  initStruct(E);

  while (firstMenu(E) != 1);
  freeEverything(E);
}
