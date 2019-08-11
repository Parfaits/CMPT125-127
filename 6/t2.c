#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "intarr.h"


int intarr_save_json( intarr_t* ia, const char* filename );
intarr_t* intarr_load_json( const char* filename );

int intarr_save_json( intarr_t* ia, const char* filename )
{
	FILE *f = fopen(filename, "w");
	if(f == NULL)
	{
		return 1;
	}

	fprintf(f, "[ ");

	if(ia != NULL)
	{
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
	} else
	{
		fprintf(f, " ]\n");
		return 2;
	}
	
	fprintf(f, " ]\n");
	fclose(f);
	return 0;
}

intarr_t* intarr_load_json( const char* filename )
{
	FILE *f = fopen(filename, "r+");
	if(f == NULL)
	{
		return NULL;
	}

	intarr_t *arr = (intarr_t *) malloc(sizeof(intarr_t));
	if(arr == NULL)
	{
		return NULL;
	}
	arr->data = (int *) malloc(0);
	if(arr->data == NULL)
	{
		free(arr);
		return NULL;
	}
	arr->len = 0;
	//char *numbuilt = malloc(len*sizeof(char));
	//char *num = malloc(len*sizeof(char));
	//int bracket = 0;
	int i = 0, n = 0;
	char tmp = 0;

	//printf("%u\n", arr->len);
	char firstbrack;
	while(!feof(f))
	{
		fscanf(f, "%c", &firstbrack);
		if(firstbrack == '[')
		{
			int killme = 0;
			while(fscanf(f, "%d,", &killme) == 1)
			{
				arr->data = realloc(arr->data, (arr->len+1)*sizeof(int));
				arr->len++;
				arr->data[arr->len-1] = killme;
				//printf("%i\n", arr->len);
				NULL;
			}
			return arr;
		}
	}

	fclose(f);
	return arr;
}

int main()
{
	intarr_t *a = intarr_create(20);
	for (unsigned int j = 1; j <= a->len; ++j)
	{
		a->data[j-1] = j;
	}
	for (unsigned int m = 0; m < a->len; ++m)
	{
		printf("%i ", a->data[m]);
	}
	printf("\n");
	int i = intarr_save_json(a, "stuff.json");
	intarr_t *ar = intarr_load_json("stuff.json");
	
	for (unsigned int k = 0; k < ar->len; ++k)
	{
		printf("%i ", ar->data[k]);
	}
	printf("\n");
	printf("ar len:%i\n", ar->len);
	//printf("%i\n", i);
	intarr_destroy(a);
	//intarr_destroy(ar);
	return 0;
}

//gcc -std=c99 ../5/intarr.o t2.c -o t2 -W -Wall