#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "struct.h"

// Returns the size of the char* depending of the index, accordingly to the math function of the subject
int  getAllocationSize(int index)
{
  int i = 2900;
  int j;

  if (index == 0)
    {
      return 2900;
    }
  else
    {
      for (j = 1; j <= index ; j++)
	{
	  i *= 2;
	}
    }
  return i;
}

// If a pointer is deallocated, reallocate memory and refill it with random letters
void reInitPointer(container *E, int pointerIndex)
{
  int tmp;
  int size;
  int j;

  size = getAllocationSize(pointerIndex);
  E->pointers[pointerIndex] = malloc(size);
  for (j = 0; j < size; j++)
    {
      tmp = 'A' + (random() % 26);
      E->pointers[pointerIndex][j] = tmp;
    }
  printf("[%d] Re-generated\n", pointerIndex);
}

// This function is called at the beginning of the programm to allocate the memory accordingly to the given math function of the subject and to fill it with random letters
void initStruct(container *E)
{
  int i;
  int j;
  int size;
  int tmp;

  size = 0;
  tmp = 0;
  for (i = 0 ; i < ARRAY_SIZE ; i++)
    {
      size = getAllocationSize(i);
      E->pointers[i] = malloc(size);
      for (j = 0; j < size; j++)
	{
	  tmp = 'A' + (random() % 26);
	  E->pointers[i][j] = tmp;
	}
      printf("[%d] generated\n", i);
    }
  printf("Data successfully generated\n");
}

// This function deallocate all the array
void freeEverything(container *E)
{
  int i;

  printf("Deallocating all the array...\n");
  for (i = 0 ; i < ARRAY_SIZE ; i++)
    {
      free(E->pointers[i]);
      E->pointers[i] = NULL;
    }
  printf("All the array is deallocated\n");
}
