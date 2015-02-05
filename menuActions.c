#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "struct.h"

// This function checks if the char* is allocated, if not, reallocate it and then prints the 10 first characters
void readPointer(container *E, int pointerIndex)
{
  if (E->pointers[pointerIndex] == NULL)
    {
      printf("This pointer was freed, regenerating ...\n");
      reInitPointer(E, pointerIndex);
    }
  printf("%.10s\n", E->pointers[pointerIndex]);
}

// This function deallocate the memory of a given pointer
void freePointer(container *E, int pointerIndex)
{
  free(E->pointers[pointerIndex]);
  E->pointers[pointerIndex] = NULL;
  printf("Pointer # %d freed\n", pointerIndex);
}

// Print the menu to access a pointer
void accessPointerMenu(container *E)
{
  int input;
  int pointerIndex;

  input = -1;
  pointerIndex = -1;
  printf("Which pointer do you want to print ? (Please enter a number between 0 and 19) \n");

  while (pointerIndex < 0 || pointerIndex > (ARRAY_SIZE - 1))
    {
      if (scanf("%d", &pointerIndex) != 1)
	while (getchar() != '\n');
    }


  printf("\n(1) Print the first 10 chars\n\
(2) Delete all the char's associated with this pointer\n\
(3) Return to main menu\n");

  while (input < 0 || input > 3)
    {
      if (scanf("%d", &input) != 1)
	while (getchar() != '\n');
    }

  switch (input) {
  case 1:
    readPointer(E, pointerIndex);
    break;
  case 2:
    freePointer(E, pointerIndex);
    break;
  case 3:    
    break;
  }
}

// List all the deallocated memory in the array
void listDeallocated(container *E)
{
  int i;
  int count;

  count = 0;

  for (i = 0; i < ARRAY_SIZE ; i++)
    {
      if (E->pointers[i] == NULL)
	{
	  printf("[%d] ", i);
	  count++;
	}
    }
  if (count)
    printf(" are deallocated\n");
  else
    printf("All the array is allocated\n");
}
