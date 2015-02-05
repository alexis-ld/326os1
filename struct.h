
#ifndef __STRUCT
#define __STRUCT

#define	ARRAY_SIZE 5

typedef struct s_container
{
	char 	*pointers[ARRAY_SIZE];
	int  	sizeArray[ARRAY_SIZE];
} container;

int	getAllocationSize(int index);
void	initStruct(container *E);
void	listDeallocated(container *E);
void	accessPointerMenu(container *E);
void	reInitPointer(container *E, int pointerIndex);
void	freeEverything(container *E);

#endif
