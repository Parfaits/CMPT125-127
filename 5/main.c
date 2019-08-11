#include <stdio.h>

#include "intarr.h"


void print(intarr_t* ia);

void print(intarr_t* ia)
{
	printf("[ ");
	for (unsigned int i = 0; i < ia->len; ++i)
	{
		printf("%i ", ia->data[i]);
	}
	printf("]\n");
}

int main(int argc, char const *argv[])
{
	intarr_t *a = NULL;
	a = intarr_create(4);
	//intarr_push(a, 1);
	
	int i = 3;
	//intarr_get(a, 10, &i);
	
	intarr_set(a, 0, 1);
	intarr_set(a, 2, 2);
	intarr_set(a, 3, 3);

	//intarr_sort(a);

	//intarr_find(a, 3, &i);

	int b = intarr_pop(a, &i);
	b = intarr_pop(a, &i);
	b = intarr_pop(a, &i);
	b = intarr_pop(a, &i);

	//intarr_resize(a, 3);

	//intarr_t *dupel = intarr_copy(a);

	//intarr_t *dupel = intarr_copy_subarray(a, 0, 2);

	
	printf("%i %i\n", b, i);
	print(a);
	//print(dupel);
	intarr_destroy(a);
	//intarr_destroy(dupel);
	return 0;
}

//gcc -std=c99 intarr.o main.c -o main -W -Wall