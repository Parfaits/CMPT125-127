#include <stdio.h>
#include <stdlib.h>

#include "intarr.h"


int intarr_save_json( intarr_t* ia, const char* filename )
{
	FILE *f = fopen(filename, "w");
	if(f == NULL)
	{
		return 1;
	}

	fprintf(f, "[ ");

	for (unsigned int i = 0; i < ia->len; ++i)
	{
		if(i == 0)
		{
			fprintf(f, "%i", ia->data[i]);
		} else 
		{
			fprintf(f, ", %i", ia->data[i]);
		}
	}
	fprintf(f, " ]\n");
	fclose(f);
	return 0;
}

int main(int argc, char const *argv[])
{
	intarr_t *a = intarr_create(10);
	for (unsigned int j = 1; j <= a->len; ++j)
	{
		a->data[j-1] = j;
	}
	for (unsigned int m = 0; m < a->len; ++m)
	{
		printf("%i ", a->data[m]);
	}
	printf("\n");
	int i = intarr_save_json(a, "DonaldTrump2016.json");
	return 0;
}

//gcc -std=c99 ../5/intarr.o t2.c -o t2 -W -Wall