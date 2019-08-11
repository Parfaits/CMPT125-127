#include <stdio.h>


void reverse( int arr[], unsigned int len )
{
	for(unsigned int i=0; i<len/2; i++)
	{
		int temp = arr[len-1-i];
		arr[len-1-i] = arr[i];
		arr[i] = temp;
	}
}