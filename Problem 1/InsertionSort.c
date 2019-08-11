#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sort.h"

void InsertionSort(int a[], size_t len);

// Pre: Sorted, Reverse sorted, and scrambled array
// input len must be equal to the length of a[]
void InsertionSort(int a[], size_t len)
{
	for(unsigned long int i=1; i<len; i++)
	{
		int x = a[i];
		unsigned long int j = i;

		while(j>0 && x<a[j-1])
		{
			//assert(a[j-1]>x);

			a[j] = a[j-1];
			j--;
		}
		//assert(j==0 || a[j-1]<=x);

		a[j] = x;
	}
	// Post: Sorted array in ascending order a[i] to len-1
}