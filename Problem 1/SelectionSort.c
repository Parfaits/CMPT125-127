#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sort.h"

void SelectionSort(int a[], size_t len);

// Pre: Sorted, Reverse sorted, and scrambled array
// input len must be equal to the length of a[]
void SelectionSort(int a[], size_t len)
{
	for(unsigned long int i=0; i<len-1; i++)
	{
		//assert(a[i-1]<=a[i]);
		int min = a[i], pos = i;
		unsigned long int j=i+1;
		
		while(j<len)
		{
			// a[j..len-1] is unsorted
			if(a[j]<min)
			{
				min = a[j];
				pos = j;
			}
			j++;
		}
		//assert(j==len || a[pos]<=a[i]);

		int tmp = a[i];
		a[i] = a[pos];
		a[pos] = tmp;
	}
	// Post: Sorted array in ascending order a[i] to len-1
}