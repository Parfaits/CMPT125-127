#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename );
intarr_t* intarr_load_binary( const char* filename );


int intarr_save_binary( intarr_t* ia, const char* filename )
{
	FILE *f = fopen(filename, "wb");
	if(f == NULL)
	{
		return 1;
	}

	if( ia != NULL)
	{
		if(fwrite(ia->data, sizeof(int), ia->len, f) != ia->len)
		{
			return 2;
		}
	} else
	{
		return 3;
	}

	fclose(f);
	return 0;
}

intarr_t* intarr_load_binary( const char* filename )
{
	FILE *f = fopen(filename, "rb");
	if(f == NULL)
	{
		return NULL;
	}
	fseek(f, 0, SEEK_END);
	long int len = ftell(f);
	len = len/sizeof(int);
	intarr_t *arr = (intarr_t *) malloc(sizeof(intarr_t));
	arr->data = (int *) malloc(len*sizeof(int));
	arr->len = len;
	fseek(f, 0, SEEK_SET);
	//printf("%i\n", ftell(f));
	int a=0;
	while(!feof(f) && a < arr->len)
	{
		fread(&arr->data[a], sizeof(int), 1, f);
		
		//printf("%d\n", arr->data[a]);
		a++;
	}
	//printf("a:%i\n", a);
	fclose(f);
	return arr;
}

int main()
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
	int i = intarr_save_binary(NULL, "test.bin");
	intarr_t *ar = intarr_load_binary("test.bin");
	for (unsigned int k = 0; k < ar->len; ++k)
	{
		printf("%i ", ar->data[k]);
	}
	printf("\n");
	printf("%i\n", i);
	intarr_destroy(a);
	//intarr_destroy(ar);
	return 0;
}

//gcc -std=c99 ../5/intarr.o t1.c -o t1 -W -Wall