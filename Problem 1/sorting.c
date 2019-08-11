#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#include "sort.h"

int* create_array(char category, size_t n);


int* create_array(char category, size_t n)
{
	int *arr = NULL;
	arr = (int *) malloc(n*sizeof(int));
	//assert(arr != NULL);

	if(category == 's')
	{
		for(unsigned long int i=0; i<n; i++)
		{
			arr[i] = i;
		}
	} else if(category == 'v')
	{
		for (unsigned long int j=n-1; j>0; j--)
		{
			arr[j] = j;
		}
		arr[0] = 0;
	} else if(category == 'r')
	{
		srand(time(NULL));
		for (unsigned long int k=0; k<n; k++)
		{
			arr[k] = rand() % 500000;
		}
	} else {
		free(arr);
		return NULL;
	}
	return arr;
}


int main(int argc, char const *argv[])
{
	// time command is not an argument :P
	size_t size = atoi(argv[3]);
	int *a = create_array(*argv[2], size);

	for (unsigned long int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
	
	if(strcmp(argv[1], "select") == 0)
	{
		SelectionSort(a, size);
	} 
	else if(strcmp(argv[1], "insert") == 0)
	{
		InsertionSort(a, size);
	}
	for (unsigned long int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}

//gcc SelectionSort.o InsertionSort.o sorting.c -o sorting -Wall -W -std=c99
//Bobby said it was OK to use header files

//    *****TESTING*******
/*int main(int argc, char const *argv[])
{
	int arr[] = {4, -2, 4, -5, 2, 12};
	size_t size = sizeof(arr)/sizeof(arr[0]);
	SelectionSort(arr, size);
	for(unsigned int i=0; i<size; i++)
	{
		printf("%i ", arr[i]);
	}
	return 0;
}*/