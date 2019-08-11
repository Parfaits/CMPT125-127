#include <stdio.h>


int main()
{
	unsigned long int i;
	int j = 0, len = 0;
	unsigned long int values[128];
	while(scanf("%lu", &i) != EOF)
	{
		values[j] = i;
		len++;
		j++;
	}
	for (int k = 0; k < len; ++k)
	{
		for (unsigned long int h = 0; h < values[k]; ++h)
		{
			printf("#");
		}
		printf("\n");
	}
	return 0;
}