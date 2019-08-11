#include <stdio.h>


int identical( int a[], int b[], unsigned int len )
{
	unsigned int i=0;
	while(i<len && a[i] == b[i])
	{
		i++;
	}
	if(i == len)
	{
		return 1;
	} else {
		return 0;
	}
}