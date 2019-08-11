#include <stdio.h>
#include <stdlib.h>
// let r = recursive

void rselectsort(int arr[], int len);
int find(int a[], int maax, int len);
// Post: arr len-1 to 0 sorted.
void rselectsort(int arr[], int len)
{
	if(len <= 1) return; // Base case
	int maxpos = find(arr, len-1, len-2); // grabs the largest element's index
	//printf("%i\n", maxpos); // debug
	int tmp = arr[maxpos];     //
	arr[maxpos] = arr[len-1];     //Swapping
	arr[len-1] = tmp;          //
	rselectsort(arr, len-1); // Shift starting position to len-1
}

int find(int a[], int maax, int len) // in current position (next to sorted position)
{
	int pos = maax;
	if(len < 0) return pos; //base case if there is no larger element
	if(a[maax] < a[len])
	{
		pos = len; // largest element's index
	}
	return find(a, pos, len-1); // return me the index
}


int main()
{
	//int a[6] = {4, -2, 4, -5, 2, 12};
	//int a[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
	//int a[5] = {1, 2, 3, 4, 5};
	//int a[1] = {0};
	//int a[10] = {12, 3, 0, -1, 2, 9, 30, 20, 349, 34};
	//int a[] = {};
	int a[] = {1234, 23, 21,35,  4,15,1,45, 4,5,15};
	size_t size = sizeof(a)/sizeof(int);
	
	for(unsigned int i=0; i<size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
	
	rselectsort(a, size);
	
	for(unsigned int i=0; i<size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
	return 0;
}