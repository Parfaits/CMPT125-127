#include <stdio.h>


int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	unsigned int sum_a = 0, sum_b = 0;
	for(unsigned int i=0; i<len; i++)
	{
		sum_a+=a[i];
		sum_b+=b[i];
	}
	if(sum_a == sum_b)
	{
		return 1;
	} else
	{
		return 0;
	}
}